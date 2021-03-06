#include "pebble_process_info.h"
#include "src/resource_ids.auto.h"

const PebbleProcessInfo __pbl_app_info __attribute__ ((section (".pbl_header"))) = {
  .header = "PBLAPP",
  .struct_version = { PROCESS_INFO_CURRENT_STRUCT_VERSION_MAJOR, PROCESS_INFO_CURRENT_STRUCT_VERSION_MINOR },
  .sdk_version = { PROCESS_INFO_CURRENT_SDK_VERSION_MAJOR, PROCESS_INFO_CURRENT_SDK_VERSION_MINOR },
  .process_version = { 0, 0 },
  .load_size = 0xb6b6,
  .offset = 0xb6b6b6b6,
  .crc = 0xb6b6b6b6,
  .name = "Arcs",
  .company = "nitr1c",
  .icon_resource_id = RESOURCE_ID_IMAGE_MENU_IMAGE,
  .sym_table_addr = 0xA7A7A7A7,
  .flags = PROCESS_INFO_WATCH_FACE | PROCESS_INFO_PLATFORM_DIORITE,
  .num_reloc_entries = 0xdeadcafe,
  .uuid = { 0x79, 0xCA, 0x38, 0xDB, 0xF8, 0x80, 0x4C, 0xD3, 0xB9, 0xB5, 0xFE, 0x38, 0x36, 0x71, 0xC6, 0x02 },
  .virtual_size = 0xb6b6
};
