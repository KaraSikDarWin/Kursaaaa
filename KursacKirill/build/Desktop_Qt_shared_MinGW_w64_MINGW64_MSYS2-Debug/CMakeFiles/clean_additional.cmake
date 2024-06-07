# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\KursacKirill_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\KursacKirill_autogen.dir\\ParseCache.txt"
  "KursacKirill_autogen"
  )
endif()
