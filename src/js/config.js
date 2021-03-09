module.exports = [
  {
    "type": "heading",
    "size": 1,
    "defaultValue": "ARCS CONFIGURATION"
  },
  {
    "type": "toggle",
    "messageKey": "USE_SECONDS",
    "label": "DISPLAY SECOND ARC",
    "defaultValue": false
  },
//////////////////////////////
//// SIMPLE CONFIGURATION ////
//////////////////////////////
  {
    "type": "section",
    "items": [
      {
        "type": "heading",
        "size": 2,
        "defaultValue": "COLOR",
        "id": "simHead"
      },
//// SIMPLE BACKGROUND COLOR
      {
        "type": "color",
        "messageKey": "C_S_BG",
        "defaultValue": "000000",
        "allowGray": true,
        "label": "BACKGROUND",
        "layout": [
          ["000000", "aa00aa", "0055ff", "00aa00"],
          ["ffffff", "ffff00", "ff5500", "aa0000"]
        ]
      },
//// SIMPLE DIAL COLOR
      {
        "type": "color",
        "messageKey": "C_S_FG",
        "defaultValue": "ffaa00",
        "allowGray": true,
        "label": "DIALS",
        "layout": [
          ["000000", "aa00aa", "0055ff", "00aa00"],
          ["ffffff", "ffff00", "ff5500", "aa0000"]
        ]
      }
    ]
  },
//// SAVE CONFIGURATION BUTTON
  {
    "type": "submit",
    "defaultValue": "SAVE"
  }
];
