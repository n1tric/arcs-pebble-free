#pragma once

#include <pebble.h>
#include "config.h"
#include "time.h"

/////////////////////////////
//// MESSAGING FUNCTIONS ////
/////////////////////////////

void message_received_handler(DictionaryIterator *iter, void *context);
