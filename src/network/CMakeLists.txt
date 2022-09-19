target_sources(app PRIVATE wifi.c wifi.h net_time.c net_time.h)

target_link_libraries(app
pico_stdlib
pico_lwip_sntp
pico_cyw43_arch_lwip_threadsafe_background)
