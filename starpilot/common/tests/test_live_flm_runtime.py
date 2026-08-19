import json

from types import SimpleNamespace

from openpilot.starpilot.common.live_flm_runtime import (
  apply_live_flm_runtime_update,
  clear_live_flm_runtime_update,
  read_live_flm_runtime_update,
)


def test_live_flm_runtime_file_read_and_clear(tmp_path):
  update_path = tmp_path / "runtime.json"
  update_path.write_text('{"schemaVersion":1}', encoding="utf-8")

  assert read_live_flm_runtime_update(update_path) == '{"schemaVersion":1}'
  clear_live_flm_runtime_update(update_path)
  assert read_live_flm_runtime_update(update_path) == ""


def test_live_flm_runtime_update_patches_only_the_active_copy():
  active_toggles = SimpleNamespace(
    force_auto_tune=True,
    force_auto_tune_off=False,
    use_auto_steer_delay=True,
    steerActuatorDelay=0.25,
    friction=0.1,
    steerKp=[[0], [1.0]],
    latAccelFactor=1.5,
    steerRatio=15.0,
    flm_trial_applied=False,
    flm_active_profile_id="",
    flm_active_overrides={},
    use_custom_friction=False,
    use_custom_latAccelFactor=False,
    use_custom_steerRatio=False,
    use_custom_steerActuatorDelay=False,
  )
  update = {
    "schemaVersion": 1,
    "updateId": "session:1",
    "profileId": "live-flm:session",
    "trialApplied": True,
    "genericParams": {
      "ForceAutoTune": False,
      "ForceAutoTuneOff": True,
      "UseAutoSteerDelay": False,
      "SteerDelay": 0.31,
      "SteerFriction": 0.22,
      "SteerKP": 0.8,
      "SteerLatAccel": 1.82,
      "SteerRatio": 14.6,
    },
    "flmOverrides": {"schemaVersion": 1, "baseFrictionThresholds": {}, "vehicleKnobs": {"car.ff_gain_left": 0.2}},
  }

  updated, applied = apply_live_flm_runtime_update(active_toggles, json.dumps(update))

  assert applied is True
  assert updated is not active_toggles
  assert active_toggles.latAccelFactor == 1.5
  assert updated.force_auto_tune is False
  assert updated.force_auto_tune_off is True
  assert updated.steerActuatorDelay == 0.31
  assert updated.friction == 0.22
  assert updated.steerKp == [[0], [0.8]]
  assert updated.latAccelFactor == 1.82
  assert updated.steerRatio == 14.6
  assert updated.flm_trial_applied is True
  assert updated.flm_active_profile_id == "live-flm:session"
  assert updated.flm_active_overrides["vehicleKnobs"]["car.ff_gain_left"] == 0.2
  assert updated.use_custom_friction is True
  assert updated.use_custom_latAccelFactor is True
  assert updated.use_custom_steerRatio is True
  assert updated.use_custom_steerActuatorDelay is True


def test_live_flm_runtime_update_rejects_nonfinite_values_without_partial_mutation():
  active_toggles = SimpleNamespace(friction=0.1, latAccelFactor=1.5)
  update = {
    "schemaVersion": 1,
    "profileId": "live-flm:session",
    "trialApplied": True,
    "genericParams": {"SteerFriction": 0.2, "SteerLatAccel": float("nan")},
    "flmOverrides": {},
  }

  updated, applied = apply_live_flm_runtime_update(active_toggles, update)

  assert applied is False
  assert updated is active_toggles
  assert active_toggles.friction == 0.1


def test_live_flm_runtime_update_rejects_invalid_schema_without_raising():
  active_toggles = SimpleNamespace(friction=0.1)

  updated, applied = apply_live_flm_runtime_update(active_toggles, '{"schemaVersion":"invalid"}')

  assert applied is False
  assert updated is active_toggles
