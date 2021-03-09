#pragma once

#include <pebble.h>
#include "layers.h"

////////////////////////
//// TIME FUNCTIONS ////
////////////////////////

void tick_handler(struct tm *time_now, TimeUnits changed);

void force_update();

void set_sec(int t);

void set_min(int t);

void set_hour(int t);

int get_sAng();

int get_mAng();

int get_hAng();
