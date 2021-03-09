#pragma once

#include <pebble.h>

//////////////////////////////
//// CONFIGURATION VALUES ////
//////////////////////////////

// Configuration struct with Clay settings
typedef struct ClaySettings {

  // Useage values
  bool   UseSeconds;

  // Simple colors
  GColor BackgroundColor;
  GColor ForegroundColor;

} ClaySettings;

// Persistent Configuration Storage Key
#define SETTINGS_KEY  1

/////////////////////////////////
//// CONFIGURATION FUNCTIONS ////
/////////////////////////////////

void config_default();

void config_load();

bool get_seconds_use();

ClaySettings get_settings();
