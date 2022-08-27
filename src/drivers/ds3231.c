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

#include "ds3231.h"

#define I2C_ADDR 0x68

static uint8_t bcd2bin(uint8_t val);

bool ds3231_fetch_time(i2c_inst_t *i2c, struct tm *t) {
    uint8_t buffer[19];
    uint8_t read_register_start = 0x00;
    int ret = i2c_write_blocking(i2c, I2C_ADDR, &read_register_start, 1, true);
    if (ret != 1) {
        return false;
    }
    ret = i2c_read_blocking(i2c, I2C_ADDR, buffer, sizeof(buffer), false);
    if (ret != sizeof(buffer)) {
        return false;
    }

    t->tm_year = bcd2bin(buffer[6]) + 100U;
    t->tm_mon = bcd2bin(buffer[5] & 0x1f) - 1;
    t->tm_mday = bcd2bin(buffer[4]);
    t->tm_wday = bcd2bin(buffer[3]) - 1;
    // TODO: Handle 12-hour.
    t->tm_hour = bcd2bin(buffer[2] & 0x3f);
    t->tm_min = bcd2bin(buffer[1]);
    t->tm_sec = bcd2bin(buffer[0]);
    return true;
}

static uint8_t bcd2bin(uint8_t val) { return val - 6 * (val >> 4); }