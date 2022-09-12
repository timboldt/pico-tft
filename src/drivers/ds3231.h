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

#pragma once

#include <time.h>

#include "hardware/i2c.h"
#include "pico/stdlib.h"

bool ds3231_fetch_time(i2c_inst_t *i2, struct tm *t);

// Usage example, since I didn't know where to put the test code for now:
//
// #include "drivers/ds3231.h"
// #include "hardware/i2c.h"
//
// #define FEATHER_I2C_BUS i2c1
// #define FEATHER_I2C_SDA_PIN 2
// #define FEATHER_I2C_SCL_PIN 3
//
// void init_i2c_bus(void) {
//     const uint baudrate_khz = 100;
//     i2c_init(FEATHER_I2C_BUS, baudrate_khz * 1000);
//     gpio_set_function(FEATHER_I2C_SDA_PIN, GPIO_FUNC_I2C);
//     gpio_set_function(FEATHER_I2C_SCL_PIN, GPIO_FUNC_I2C);
//     gpio_pull_up(FEATHER_I2C_SDA_PIN);
//     gpio_pull_up(FEATHER_I2C_SCL_PIN);
// }
//
// And then in main():
//
// init_i2c_bus();
// struct tm now = {};
// ds3231_fetch_time(FEATHER_I2C_BUS, &now);
// printf("%s\n", asctime(&now));