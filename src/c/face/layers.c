#include "layers.h"

static Layer *window_layer, *bg_layer, *sec_layer, *hour_layer, *min_layer;

/////////////////////////
//// Layer Functions ////
/////////////////////////

Layer* get_big_ole_layer() {
  // Returns root layer
  return window_layer;
}

void window_load(Window *window) {
  window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  // Create background layer
  bg_layer = layer_create(bounds);
  layer_set_update_proc(bg_layer, bg_update);
  layer_add_child(window_layer, bg_layer);

  // Create second arc layer
  sec_layer = layer_create(bounds);
  layer_set_update_proc(sec_layer, sec_update);
  layer_add_child(window_layer, sec_layer);

  // Create hour arc layer
  hour_layer = layer_create(bounds);
  layer_set_update_proc(hour_layer, hour_update);
  layer_add_child(window_layer, hour_layer);

  // Create minute arc layer
  min_layer = layer_create(bounds);
  layer_set_update_proc(min_layer, min_update);
  layer_add_child(window_layer, min_layer);

  //// Update drawing parameters before drawing
  // Load previous configuration from memory
  config_load();
  // Update arc angles
  force_update();
}

void window_unload(Window *window) {
  // Destroy child layers
  layer_destroy(bg_layer);
  layer_destroy(sec_layer);
  layer_destroy(hour_layer);
  layer_destroy(min_layer);
}
