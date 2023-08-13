# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\ESP32-CFG_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ESP32-CFG_autogen.dir\\ParseCache.txt"
  "ESP32-CFG_autogen"
  )
endif()
