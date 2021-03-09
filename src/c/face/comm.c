#include "comm.h"

/////////////////////////////////
//// Communication Functions ////
/////////////////////////////////

void message_received_handler(DictionaryIterator *iter, void *context) {
  // Parses MessageKeys into configuration values
  ClaySettings settings = get_settings();
  // MessageKey values are parsed from tuples, must translate through int32

  // Parse useage flags
  Tuple *sec_use_t = dict_find(iter, MESSAGE_KEY_USE_SECONDS);
  if (sec_use_t) { settings.UseSeconds = sec_use_t->value->int32; }

  // Parse simple color options
  Tuple *sbg_color_t = dict_find(iter, MESSAGE_KEY_C_S_BG);
  if (sbg_color_t) { settings.BackgroundColor = GColorFromHEX(sbg_color_t->value->int32); }

  Tuple *sfg_color_t = dict_find(iter, MESSAGE_KEY_C_S_FG);
  if (sfg_color_t) { settings.ForegroundColor = GColorFromHEX(sfg_color_t->value->int32); }

  // Write configuration to memory
  persist_write_data(SETTINGS_KEY, &settings, sizeof(settings));

  // Force settings load
  config_load();
  force_update();
}
