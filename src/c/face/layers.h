#pragma once

#include <pebble.h>
#include "arcs.h"
#include "config.h"
#include "time.h"

/////////////////////////
//// Layer Functions ////
/////////////////////////

void tick_handler(struct tm *time_now, TimeUnits changed);

Layer* get_big_ole_layer();

void window_load(Window *window);

void window_unload(Window *window);
