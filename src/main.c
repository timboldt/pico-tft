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
#include "network/wifi.h"
#include "pico/stdlib.h"

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

int main() {
    stdio_init_all();
    wifi_init();
    lv_init();
    // init_i2c_bus();

    while (true) {
        wifi_tick();

        // struct tm now = {};
        // ds3231_fetch_time(FEATHER_I2C_BUS, &now);
        // printf("%s\n", asctime(&now));

        printf("WiFi status: %d\n", wifi_connected());
        sleep_ms(100);

        // These don't belong here. (Part of it needs to go in a timer
        // callback.) lv_timer_handler(); lv_tick_inc(10);
    }
    return 0;
}