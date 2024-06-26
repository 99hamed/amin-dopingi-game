# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\amin_dopingi_game_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\amin_dopingi_game_autogen.dir\\ParseCache.txt"
  "amin_dopingi_game_autogen"
  )
endif()
