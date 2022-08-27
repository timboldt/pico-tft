if (TARGET tinyusb_device)
    # rest of your project
    add_executable(app)
    set_target_properties(app PROPERTIES OUTPUT_NAME "picotft")
    target_sources(app PRIVATE main.c)
    target_include_directories(app PRIVATE "${PROJECT_SOURCE_DIR}")
    add_subdirectory(drivers)
    target_link_libraries(app pico_stdlib hardware_i2c)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(app 1)
    pico_enable_stdio_uart(app 0)

    # create map/bin/hex/uf2 file in addition to ELF.
    pico_add_extra_outputs(app)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building app because TinyUSB submodule is not initialized in the SDK")
endif()