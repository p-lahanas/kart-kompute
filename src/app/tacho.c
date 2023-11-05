#include <avr/io.h>
#include <avr/interrupt.h>
#include "xc4434.h"
#include "sysclock.h"
#include "tacho.h"

static uint16_t revCount; // Count our rpm

void tacho_init(void)
{
    he_init();
    sys_time_init();
}

void tacho_close(void)
{
    he_close();
}

ISR(INT0_vect)
{
    PORTB ^= _BV(PINB5);
    revCount++;
}