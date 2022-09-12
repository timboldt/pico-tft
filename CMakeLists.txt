cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)

project(picotft)

# Initialize the Raspberry Pi Pico SDK.
pico_sdk_init()

# Set up LVGL graphics library.
set(LV_CONF_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_conf.h
    CACHE STRING "" FORCE)
add_subdirectory(lvgl)

add_subdirectory(src)
