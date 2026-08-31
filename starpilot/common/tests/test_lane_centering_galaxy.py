import json
from pathlib import Path


_LAYOUT_PATH = Path(__file__).resolve().parents[2] / "system/the_galaxy/assets/components/tools/device_settings_layout.json"
_DEVICE_LATERAL_PATH = Path(__file__).resolve().parents[3] / "selfdrive/ui/layouts/settings/starpilot/lateral.py"
_LANE_CENTERING_KEYS = {
  "LaneCentering",
  "LaneCenteringStrength",
  "LaneCenteringResponseTime",
  "LaneCenteringDeadband",
  "LaneCenterOffset",
  "LaneCenteringPauseOnSignal",
  "LaneCenteringE2EAuthority",
}


def _sections():
  layout = json.loads(_LAYOUT_PATH.read_text(encoding="utf-8"))
  return {
    section["name"]: {param["key"]: param for param in section["params"]}
    for section in layout
  }


def test_lane_centering_is_in_galaxy_developer_section():
  sections = _sections()

  assert _LANE_CENTERING_KEYS <= sections["Developer"].keys()
  for name, params in sections.items():
    if name != "Developer":
      assert _LANE_CENTERING_KEYS.isdisjoint(params)

  for key in _LANE_CENTERING_KEYS:
    assert sections["Developer"][key]["settings_tier"] == "advanced"


def test_lane_centering_is_exposed_in_device_steering_settings():
  source = _DEVICE_LATERAL_PATH.resolve().read_text(encoding="utf-8")
  assert 'self._controller._navigate_to("lane_centering")' in source
  assert 'self._sub_panels["lane_centering"]' in source
  for key in _LANE_CENTERING_KEYS:
    assert f'"{key}"' in source


def test_lane_centering_galaxy_controls():
  developer = _sections()["Developer"]
  centering = developer["LaneCentering"]
  offset = developer["LaneCenterOffset"]
  pause_on_signal = developer["LaneCenteringPauseOnSignal"]
  e2e_authority = developer["LaneCenteringE2EAuthority"]
  strength = developer["LaneCenteringStrength"]
  response_time = developer["LaneCenteringResponseTime"]
  deadband = developer["LaneCenteringDeadband"]

  assert centering["ui_type"] == "toggle"
  assert centering["is_parent_toggle"] is True

  assert pause_on_signal["ui_type"] == "toggle"
  assert pause_on_signal["parent_key"] == "LaneCentering"

  assert offset["parent_key"] == "LaneCentering"
  assert offset["min"] == -0.3
  assert offset["max"] == 0.3
  assert offset["step"] == 0.01

  assert e2e_authority["parent_key"] == "LaneCentering"
  assert e2e_authority["min"] == 0.0
  assert e2e_authority["max"] == 1.0
  assert e2e_authority["step"] == 0.05
  assert e2e_authority["control"] == "slider"
  assert len(e2e_authority["description_steps"]) == 5

  assert strength["parent_key"] == "LaneCentering"
  assert strength["min"] == 0.1
  assert strength["max"] == 0.6
  assert strength["step"] == 0.05

  assert response_time["parent_key"] == "LaneCentering"
  assert response_time["min"] == 0.1
  assert response_time["max"] == 0.8
  assert response_time["step"] == 0.05

  assert deadband["parent_key"] == "LaneCentering"
  assert deadband["min"] == 0.0
  assert deadband["max"] == 0.2
  assert deadband["step"] == 0.01
