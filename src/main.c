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
#include <time.h>

#include "pico.h"

#include "hardware/rtc.h"
#include "lvgl.h"
#include "network/wifi.h"
#include "network/net_time.h"
#include "pico/stdlib.h"

int main() {
    stdio_init_all();

    wifi_init();
    for (int cnt = 0; cnt < 100; cnt++) {
        wifi_tick();
        if (wifi_connected()) {
            printf("WiFi connected!\n");
            break;
        }
        if (cnt % 10 == 0) {
            printf("Waiting for WiFi (%d)\n", cnt);
        }
        sleep_ms(100);
    }

    nettime_init();
    lv_init();

    while (true) {
        wifi_tick();

        static int cnt = 0;
        cnt++;
        if (cnt % 10 == 0) {
            printf("WiFi status: %d\n", wifi_connected());

            datetime_t dt = {};
            rtc_get_datetime(&dt);
            printf("Time: %04d-%02d-%02d %02d:%02d:%02d\n", dt.year, dt.month, dt.day, dt.hour, dt.min, dt.sec);
        }

        sleep_ms(100);

        // These don't belong here. (Part of it needs to go in a timer
        // callback.) lv_timer_handler(); lv_tick_inc(10);
    }
    return 0;
}