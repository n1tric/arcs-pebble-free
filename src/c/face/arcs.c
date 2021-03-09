#include "arcs.h"

GPoint notch1, notch2, notch3, pnt;
GRect bounds, bufFrame;

/////////////////////////
//// Drawing Helpers ////
/////////////////////////

// Draws a dot
static void draw_dot(GContext* c, GColor col, GPoint p, int thicc) {
  graphics_context_set_fill_color(c, col);
  graphics_fill_circle(c, p, thicc);
}

static void draw_outline_dot(GContext* c, GColor colBg, GColor col, GPoint p, int thiccBg, int thicc) {
  draw_dot(c, colBg, p, thiccBg);
  draw_dot(c, col, p, thicc);
}

// Draws a notched arc, used here for time display
static void draw_notch_arc(GContext* c, GColor col, int thicc, GRect bounds, int inset, int cutW, int ang, int cutL, int cutC) {

  // Set color and thickness
  graphics_context_set_stroke_color(c, col);
  graphics_context_set_stroke_width(c, thicc);

  // Draw arc
  bufFrame = grect_inset(bounds, GEdgeInsets(inset));
  graphics_draw_arc(c, bufFrame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(cutW + ang), DEG_TO_TRIGANGLE(360 - cutW + ang));

  // Find notch points
  bufFrame = grect_inset(bounds, GEdgeInsets(inset + cutL));
  notch2 = gpoint_from_polar(bufFrame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(ang));

  bufFrame = grect_inset(bounds, GEdgeInsets(inset + cutC));
  notch1 = gpoint_from_polar(bufFrame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(cutW + ang - cutC));
  notch3 = gpoint_from_polar(bufFrame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(360 - cutW + ang + cutC));

  // Draw notch
  graphics_draw_line(c, notch1, notch2);
  graphics_draw_line(c, notch2, notch3);
}

static void draw_outline_notch_arc(GContext* c, GColor colBg, GColor col, int thiccBg, int thicc, GRect bounds, int inset, int cutW, int ang, int cutL, int cutC) {
  draw_notch_arc(c, colBg, thiccBg, bounds, inset, cutW, ang, cutL, cutC);
  draw_notch_arc(c, col, thicc, bounds, inset, cutW, ang, cutL, cutC);
}

///////////////////////////
//// Drawing Functions ////
///////////////////////////

// Background update process
void bg_update(Layer *layer, GContext *ctx) {
  bounds = layer_get_bounds(layer);
  // Draw background
  graphics_context_set_fill_color(ctx, get_settings().BackgroundColor);
  graphics_fill_rect(ctx, bounds, 0, GCornerNone);
  // Draw time dots
  bufFrame = grect_inset(bounds, GEdgeInsets(DOTS_INSET));
  for(int i = 0; i < 12; i++) {
    pnt = gpoint_from_polar(bufFrame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(i * 30));
    if (i == 0) {
      draw_dot(ctx, get_settings().ForegroundColor, pnt, DOTS_BG_THICK);
    }
    else {
      draw_outline_dot(ctx, get_settings().ForegroundColor, get_settings().BackgroundColor, pnt, DOTS_BG_THICK, DOTS_THICK);
      if (i == 3) {
        draw_dot(ctx, get_settings().ForegroundColor, pnt, DOT_DECORATE_THICK);
      }
      else if (i == 6) {
        draw_dot(ctx, get_settings().ForegroundColor, pnt, DOT_DECORATE_THICK);
      }
      else if (i == 9) {
        draw_dot(ctx, get_settings().ForegroundColor, pnt, DOT_DECORATE_THICK);
      }
    }
  }
}

// Second update process
void sec_update(Layer *layer, GContext *ctx) {
  // Check on second hand
  if (get_settings().UseSeconds) {
    // Draw second arc
    draw_outline_notch_arc(ctx, get_settings().BackgroundColor, get_settings().ForegroundColor, SECONDS_BG_THICK, SECONDS_THICK, bounds, SECONDS_INSET, SECONDS_CUT_WIDTH, get_sAng(), SECONDS_CUT_LENGTH, CUT_CORRECTION);
    // Find second dots
    bufFrame = grect_inset(bounds, GEdgeInsets(SECONDS_INSET - SECONDS_DOT_POS));
    pnt = gpoint_from_polar(bufFrame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(get_sAng()));
    draw_outline_dot(ctx, get_settings().BackgroundColor, get_settings().ForegroundColor, pnt, SECONDS_BG_THICK, SECONDS_THICK);

    bufFrame = grect_inset(bounds, GEdgeInsets(SECONDS_INSET + SECONDS_CUT_LENGTH));
    pnt = gpoint_from_polar(bufFrame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(SECONDS_DOT_WIDTH + get_sAng()));
    draw_outline_dot(ctx, get_settings().BackgroundColor, get_settings().ForegroundColor, pnt, SECONDS_BG_THICK, SECONDS_THICK);

    pnt = gpoint_from_polar(bufFrame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(360 - SECONDS_DOT_WIDTH + get_sAng()));
    draw_outline_dot(ctx, get_settings().BackgroundColor, get_settings().ForegroundColor, pnt, SECONDS_BG_THICK, SECONDS_THICK);

    pnt = gpoint_from_polar(bufFrame, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(180 + get_sAng()));
    draw_outline_dot(ctx, get_settings().BackgroundColor, get_settings().ForegroundColor, pnt, SECONDS_BG_THICK, SECONDS_THICK);
  }
}

// Hour update process
void hour_update(Layer *layer, GContext *ctx) {
  // Draw hour arc
  draw_outline_notch_arc(ctx, get_settings().BackgroundColor, get_settings().ForegroundColor, HOURS_BG_THICK, HOURS_THICK, bounds, HOURS_INSET, HOURS_CUT_WIDTH, get_hAng(), HOURS_CUT_LENGTH, CUT_CORRECTION);
}

// Minute update process
void min_update(Layer *layer, GContext *ctx) {
  // Draw minute arc
  draw_outline_notch_arc(ctx, get_settings().BackgroundColor, get_settings().ForegroundColor, MINUTES_BG_THICK, MINUTES_THICK, bounds, MINUTES_INSET, MINUTES_CUT_WIDTH, get_mAng(), MINUTES_CUT_LENGTH, CUT_CORRECTION);
}
