from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[4]
SETTINGS_PATH = REPO_ROOT / "starpilot/system/the_galaxy/assets/components/settings.js"
ROUTER_PATH = REPO_ROOT / "starpilot/system/the_galaxy/assets/components/router.js"
INDEX_PATH = REPO_ROOT / "starpilot/system/the_galaxy/templates/index.html"
TUNING_PATH = REPO_ROOT / "starpilot/system/the_galaxy/assets/components/tools/tuning.js"


def test_settings_does_not_create_a_second_router_module():
  source = SETTINGS_PATH.read_text(encoding="utf-8")

  assert "/assets/components/router.js" not in source
  assert "window.__theGalaxyNavigate" in source


def test_router_and_settings_cache_bust_is_consistent():
  router = ROUTER_PATH.read_text(encoding="utf-8")
  index = INDEX_PATH.read_text(encoding="utf-8")

  assert "/assets/components/settings.js?v=router-cycle-fix-1" in router
  assert "/assets/components/router.js?v=router-cycle-fix-1" in index


def test_custom_trial_apply_is_available_onroad_while_analysis_stays_offroad_only():
  source = TUNING_PATH.read_text(encoding="utf-8")
  apply_custom_trial = source.split("async function applyCustomTrial()", 1)[1].split("async function saveCurrentTune", 1)[0]

  assert "state.status?.isOnroad" not in apply_custom_trial
  assert "Apply only while parked" not in source
  assert "state.runningAction || state.status?.isOnroad || !state.customTrialValues" not in source
  assert "state.runningAction || state.status?.isOnroad || state.workspace?.activeTrial" not in source
  assert "state.selectedRoutes.length === 0 || !!state.status?.isOnroad" in source
