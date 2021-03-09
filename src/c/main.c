#include "main.h"

static Window *s_window;

//////////////////////////
//// Window Functions ////
//////////////////////////

static void init() {
  s_window = window_create();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  window_stack_push(s_window, true);

  app_message_register_inbox_received(message_received_handler);
  app_message_open(256, 256);

  // TickTimerService subscribed in window_load() in layers.c
}

static void deinit() {
  tick_timer_service_unsubscribe();

  window_destroy(s_window);
}

int main() {
  init();
  app_event_loop();
  deinit();
}
