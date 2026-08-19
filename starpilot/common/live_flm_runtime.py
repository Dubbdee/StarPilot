import copy
import json
import math

from pathlib import Path


FLM_LIVE_RUNTIME_UPDATE_FILENAME = "flm_live_runtime_update.json"


def live_flm_runtime_update_path(shm_path):
  return Path(shm_path) / FLM_LIVE_RUNTIME_UPDATE_FILENAME


def read_live_flm_runtime_update(path):
  try:
    return Path(path).read_text(encoding="utf-8")
  except (OSError, UnicodeError):
    return ""


def clear_live_flm_runtime_update(path):
  try:
    Path(path).unlink()
  except FileNotFoundError:
    pass


def live_flm_runtime_marker(raw_update):
  if isinstance(raw_update, bytes):
    return raw_update.decode("utf-8", errors="replace")
  if isinstance(raw_update, str):
    return raw_update
  if isinstance(raw_update, dict):
    return json.dumps(raw_update, sort_keys=True, separators=(",", ":"))
  return ""


def decode_live_flm_runtime_update(raw_update):
  if isinstance(raw_update, bytes):
    raw_update = raw_update.decode("utf-8", errors="replace")
  if isinstance(raw_update, str):
    try:
      raw_update = json.loads(raw_update) if raw_update.strip() else {}
    except (TypeError, ValueError):
      return None
  if not isinstance(raw_update, dict):
    return None
  try:
    schema_version = int(raw_update.get("schemaVersion", 0) or 0)
  except (TypeError, ValueError):
    return None
  if schema_version != 1:
    return None
  if not isinstance(raw_update.get("genericParams", {}), dict):
    return None
  if not isinstance(raw_update.get("flmOverrides", {}), dict):
    return None
  return raw_update


def apply_live_flm_runtime_update(starpilot_toggles, raw_update):
  """Apply the compact Live FLM delta without rereading hundreds of Params."""
  update = decode_live_flm_runtime_update(raw_update)
  if update is None:
    return starpilot_toggles, False

  generic = update.get("genericParams", {})
  float_values = {}
  for key in ("SteerDelay", "SteerFriction", "SteerKP", "SteerLatAccel", "SteerRatio"):
    if key not in generic:
      continue
    try:
      value = float(generic[key])
    except (TypeError, ValueError):
      return starpilot_toggles, False
    if not math.isfinite(value):
      return starpilot_toggles, False
    float_values[key] = value

  updated = copy.copy(starpilot_toggles)
  if "ForceAutoTune" in generic:
    updated.force_auto_tune = bool(generic["ForceAutoTune"])
  if "ForceAutoTuneOff" in generic:
    updated.force_auto_tune_off = bool(generic["ForceAutoTuneOff"])
  if "UseAutoSteerDelay" in generic:
    updated.use_auto_steer_delay = bool(generic["UseAutoSteerDelay"])

  if "SteerDelay" in float_values:
    updated.steerActuatorDelay = float_values["SteerDelay"]
  if "SteerFriction" in float_values:
    updated.friction = float_values["SteerFriction"]
  if "SteerKP" in float_values:
    updated.steerKp = [[0], [float_values["SteerKP"]]]
  if "SteerLatAccel" in float_values:
    updated.latAccelFactor = float_values["SteerLatAccel"]
  if "SteerRatio" in float_values:
    updated.steerRatio = float_values["SteerRatio"]

  trial_applied = bool(update.get("trialApplied", False))
  profile_id = str(update.get("profileId", "") or "")
  updated.flm_trial_applied = trial_applied
  updated.flm_active_profile_id = profile_id
  updated.flm_active_overrides = copy.deepcopy(update.get("flmOverrides", {})) if trial_applied and profile_id else {}

  force_auto_tune = bool(getattr(updated, "force_auto_tune", False))
  force_auto_tune_off = bool(getattr(updated, "force_auto_tune_off", False))
  manual_torque_params = trial_applied and (not force_auto_tune or force_auto_tune_off)
  if "SteerFriction" in float_values:
    updated.use_custom_friction = manual_torque_params
  if "SteerLatAccel" in float_values:
    updated.use_custom_latAccelFactor = manual_torque_params
  if "SteerRatio" in float_values:
    updated.use_custom_steerRatio = manual_torque_params
  if "UseAutoSteerDelay" in generic or "SteerDelay" in float_values:
    updated.use_custom_steerActuatorDelay = not bool(getattr(updated, "use_auto_steer_delay", True))

  return updated, True
