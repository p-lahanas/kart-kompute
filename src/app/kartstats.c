#include <avr/io.h>

#include "sysclock.h"
#include "tacho.h"
#include "kartstats_settings.h"
#include "kartstats.h"

static unsigned long prevTime; // The last time we updated the statistics
static unsigned long lastRPM; // The last estimated RPM

void kartstats_init(void)
{
    tacho_init();
    prevTime = sys_time_elapsed();
    lastRPM = 0;
}

void kartstats_close(void)
{
    tacho_close();
}

void kartstats_update(void)
{
    if ((sys_time_elapsed() - prevTime) >= KARTSTATS_RPM_DELAY) {
        lastRPM = tacho_get_rpm();
        prevTime = sys_time_elapsed();
    }
}

unsigned long kartstats_get_axle_rpm(void)
{
    return lastRPM;
}

unsigned long kartstats_get_engine_rpm(void)
{
    return 0;
}

unsigned int kartstats_get_speed(void)
{
    return (lastRPM * KARTSTATS_WHEEL_CIRCUMFERENCE) * (0.06); // 0.06 to convert meters/min to km/hr
}