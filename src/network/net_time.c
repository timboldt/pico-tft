#include "net_time.h"

#include <time.h>

#include "pico.h"

#include "hardware/rtc.h"
#include "lwip/apps/sntp.h"


        // -DSNTP_SERVER_DNS=1
        // -DSNTP_SERVER_ADDRESS="pool.ntp.org"
        // -DSNTP_SET_SYSTEM_TIME=nettime_set_system_time
        // -DSNTP_STARTUP_DELAY=0

void nettime_init(void) {
    rtc_init();
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_init();
    //sntp_setservername(0, "pool.ntp.org");
}

void nettime_set_system_time(uint32_t sec) {
    time_t epoch = sec;
    struct tm *time = gmtime(&epoch);

    datetime_t datetime = {
        .year = (int16_t)(1900 + time->tm_year),
        .month = (int8_t)(time->tm_mon + 1),
        .day = (int8_t)time->tm_mday,
        .hour = (int8_t)time->tm_hour,
        .min = (int8_t)time->tm_min,
        .sec = (int8_t)time->tm_sec,
        .dotw = (int8_t)time->tm_wday,
    };

    rtc_set_datetime(&datetime);
}