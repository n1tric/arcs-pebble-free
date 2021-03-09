#include "time.h"

struct tm *now;
time_t cur_time;
int sec, min, hour, sAng, mAng, hAng;

////////////////////////
//// Time Functions ////
////////////////////////

// Tick handler
void tick_handler(struct tm *time_now, TimeUnits changed) {
  // Set time
  // This order is necessary for angle calculations
  set_sec(time_now->tm_sec);
  set_min(time_now->tm_min);
  set_hour(time_now->tm_hour);

  // Tell Pebble to update root layer
  layer_mark_dirty(get_big_ole_layer());
}

void set_timer_service(bool second) {
  // Determine which time unit to track
  if (second) {
    tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
  }
  else {
    tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  }
}

void force_update() {
  cur_time = time(NULL);
  now = localtime(&cur_time);
  tick_handler(now, 0);
  set_timer_service(get_seconds_use());
}

void set_sec(int t) {
  // Set second value
  sec = t;
  // 6deg per second
  sAng = 6 * sec;
}

void set_min(int t) {
  // Set minute value
  min = t;
  // 6deg per minute
  // 6deg per full second rotation
  mAng = 6 * min + sAng / 60;
}

void set_hour(int t) {
  // Set hour value
  hour = t;
  // Bring hours within 12 hour period
  hour -= (hour > 12) ? 12 : 0;
  // 30deg per hour
  // 30deg per full minute rotation
  hAng = 30 * hour + mAng / 12;
}

int get_sAng() {
  // Return second angle
  return sAng;
}

int get_mAng() {
  // Return minute angle
  return mAng;
}

int get_hAng() {
  // Return hour angle
  return hAng;
}
