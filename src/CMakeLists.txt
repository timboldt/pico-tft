if (TARGET tinyusb_device)
    # rest of your project
    add_executable(picotft
        main.c
    )

    # Add pico_stdlib library which aggregates commonly used features
    target_link_libraries(picotft pico_stdlib)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(picotft 1)
    pico_enable_stdio_uart(picotft 0)

    # create map/bin/hex/uf2 file in addition to ELF.
    pico_add_extra_outputs(picotft)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building picotft because TinyUSB submodule is not initialized in the SDK")
endif()