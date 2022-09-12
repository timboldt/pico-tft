//  Copyright 2022 Google LLC
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include <stdio.h>

// #include "drivers/ds3231.h"
// #include "hardware/i2c.h"
#include "lvgl.h"
#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"
#include "secrets.h"

// #define FEATHER_I2C_BUS i2c1
// #define FEATHER_I2C_SDA_PIN 2
// #define FEATHER_I2C_SCL_PIN 3

// void init_i2c_bus(void) {
//     const uint baudrate_khz = 100;
//     i2c_init(FEATHER_I2C_BUS, baudrate_khz * 1000);
//     gpio_set_function(FEATHER_I2C_SDA_PIN, GPIO_FUNC_I2C);
//     gpio_set_function(FEATHER_I2C_SCL_PIN, GPIO_FUNC_I2C);
//     gpio_pull_up(FEATHER_I2C_SDA_PIN);
//     gpio_pull_up(FEATHER_I2C_SCL_PIN);
// }

void init_wifi(void) {
    printf("cyw43_arch_init_with_country()...\n");
    if (cyw43_arch_init_with_country(CYW43_COUNTRY_USA)) {
        printf("cyw43_arch_init_with_country() failed.\n");
        return;
    }

    printf("cyw43_arch_enable_sta_mode()...\n");
    cyw43_arch_enable_sta_mode();

    printf("cyw43_arch_wifi_connect_async()...\n");
    int err = cyw43_arch_wifi_connect_async(
        WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK);
    if (err) {
        printf("cyw43_arch_wifi_connect_async() failed: %d\n", err);
        return;
    }
}

int main() {
    stdio_init_all();
    // init_i2c_bus();
    lv_init();

    sleep_ms(5000);
    init_wifi();

    while (true) {
        cyw43_arch_poll();

        // struct tm now = {};
        // ds3231_fetch_time(FEATHER_I2C_BUS, &now);
        // printf("%s\n", asctime(&now));

        printf("WiFi status: %d\n", cyw43_wifi_link_status(&cyw43_state, CYW43_ITF_STA));
        sleep_ms(100);

        // These don't belong here. (Part of it needs to go in a timer
        // callback.) lv_timer_handler(); lv_tick_inc(10);
    }
    return 0;
}