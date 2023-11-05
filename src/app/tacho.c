#include <avr/io.h>
#include <avr/interrupt.h>
#include "xc4434.h"
#include "sysclock.h"
#include "tacho.h"

static unsigned long revCount; // Count our rpm
static unsigned long currentTime;

void tacho_init(void)
{
    sys_time_init();
    currentTime = sys_time_elapsed();
    he_init();
}

void tacho_close(void)
{
    he_close();
}

unsigned long tacho_get_rpm(void)
{
    he_eimsk_int0_disable();

    unsigned long rpm;
    unsigned long oldTime;

    oldTime = currentTime;
    currentTime = sys_time_elapsed();
    
    
    rpm = (revCount*60000) / (currentTime - oldTime); // Revs per ms
    revCount = 0;
    he_eimsk_int0_enable();
    return rpm; //convert to revs per minute
}

ISR(INT0_vect)
{
    PORTB ^= _BV(PINB5);
    revCount++;
}