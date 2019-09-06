cmake_minimum_required (VERSION 2.6)
PROJECT (PiGame)
# version number
set (PiGame_VERSION_MAJOR 1)
set (PiGame_VERSION_MINOR 0)

# to find wiringpi
set(CMAKE_MODULE_PATH "./")

# configure header file
configure_file (
    "${PROJECT_SOURCE_DIR}/PiGameConfig.h.in"
    "${PROJECT_BINARY_DIR}/PiGameConfig.h"
)

# add binary tree to source path
include_directories("{PROJECT_BINARY_DIR}")

# add raylib
include_directories("${PROJECT_SOURCE_DIR}/raylib")
add_subdirectory(raylib)
set (EXTRA_LIBS ${EXTRA_LIBS} raylib)

# add wiringPi
include_directories("/usr/include")
link_directories("/usr/lib")
set (EXTRA_LIBS ${EXTRA_LIBS} wiringPi)

add_executable(PiGame main.cpp)
target_link_libraries(PiGame ${EXTRA_LIBS})

# add the install targets
install (TARGETS PiGame DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/PiGameConfig.h"        
         DESTINATION include)