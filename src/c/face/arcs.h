#pragma once

#include <pebble.h>
#include "config.h"
#include "time.h"

////////////////////////////
//// DRAWING DIMENSIONS ////
////////////////////////////

// TIME DOTS //
#define DOTS_BG_THICK       PBL_IF_ROUND_ELSE( 7,  7)
#define DOTS_THICK          DOTS_BG_THICK - 2
#define DOT_DECORATE_THICK  DOTS_THICK - 2

// SECOND ARC //
#define SECONDS_BG_THICK    PBL_IF_ROUND_ELSE(6,  5)
#define SECONDS_THICK       SECONDS_BG_THICK - 2
#define SECONDS_CUT_WIDTH   PBL_IF_ROUND_ELSE(26, 30)
#define SECONDS_DOT_POS     PBL_IF_ROUND_ELSE(3, 2)
#define SECONDS_CUT_LENGTH  PBL_IF_ROUND_ELSE(12, 9)
#define SECONDS_DOT_WIDTH   3 * SECONDS_CUT_WIDTH

// HOUR ARC //
#define HOURS_BG_THICK      PBL_IF_ROUND_ELSE(12, 10)
#define HOURS_THICK         HOURS_BG_THICK - 4
#define HOURS_CUT_WIDTH     PBL_IF_ROUND_ELSE(20, 18)
#define HOURS_CUT_LENGTH    PBL_IF_ROUND_ELSE(12, 8)

// MINUTE ARC //
#define MINUTES_BG_THICK    PBL_IF_ROUND_ELSE(12, 10)
#define MINUTES_THICK       MINUTES_BG_THICK - 4
#define MINUTES_CUT_WIDTH   PBL_IF_ROUND_ELSE(16, 14)
#define MINUTES_CUT_LENGTH  PBL_IF_ROUND_ELSE(30, 25)

// INSET VALUES //
#define MINUTES_INSET       PBL_IF_ROUND_ELSE(MINUTES_BG_THICK + 4, MINUTES_BG_THICK + 1)
#define HOURS_INSET         PBL_IF_ROUND_ELSE(HOURS_BG_THICK + MINUTES_INSET, HOURS_BG_THICK + MINUTES_INSET)
#define DOTS_INSET          MINUTES_INSET + MINUTES_CUT_LENGTH + 2
#define SECONDS_INSET       DOTS_INSET + 2 * DOTS_THICK + PBL_IF_ROUND_ELSE(6, 4)
#define CUT_CORRECTION      PBL_IF_ROUND_ELSE(1, 1)


///////////////////////////
//// DRAWING FUNCTIONS ////
///////////////////////////

void bg_update(Layer *layer, GContext *ctx);

void sec_update(Layer *layer, GContext *ctx);

void hour_update(Layer *layer, GContext *ctx);

void min_update(Layer *layer, GContext *ctx);
