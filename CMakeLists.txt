cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)

project(my_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

if (TARGET tinyusb_device)
    # rest of your project
    add_executable(hello_world
        hello_world.c
    )

    # Add pico_stdlib library which aggregates commonly used features
    target_link_libraries(hello_world pico_stdlib)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(hello_world 1)
    pico_enable_stdio_uart(hello_world 0)

    # create map/bin/hex/uf2 file in addition to ELF.
    pico_add_extra_outputs(hello_world)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_world because TinyUSB submodule is not initialized in the SDK")
endif()