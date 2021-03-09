#include "config.h"

static ClaySettings settings;

/////////////////////////////////
//// Configuration Functions ////
/////////////////////////////////

void config_default() {
  settings.UseSeconds             = false;

  settings.BackgroundColor  = GColorLightGray;
  settings.ForegroundColor  = GColorBlack;
}

void config_load() {
  config_default();
  persist_read_data(SETTINGS_KEY, &settings, sizeof(settings));
}

bool get_seconds_use() {
  return settings.UseSeconds;
}

ClaySettings get_settings() {
  return settings;
}
