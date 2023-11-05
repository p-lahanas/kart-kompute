#include "sysclock.h"
#include "avr/interrupt.h"
#include "avr/io.h"

#define FREQ 16000000UL
#define PRESCALER 64
#define MAX 256

/* CALCULATION FOR VALUES:
    - With prescaler and 8 bit counter 16Mhz clock, we get an overflow ever 1024us
    - This means every interrupt has and error of 24 us
    - We can shift this by 3 bits to the right and maintain precision
    - This means when our error adds to 1000us or above, we just add the correction */
#define ERR_INC 24 >> 3
#define ERR_MAX 1000 >> 3

#define MILLIS_INC 1

volatile unsigned long timer0_millis = 0;
volatile unsigned long timer0_err = 0;

/* We have setup an 8 bit timer (with 64 bit prescaler meaning we get an interrupt every 1.024ms)
    1/16e6 * 256 * 64 = */
ISR(TIMER0_OVF_vect)
{

    // Copy millis into registers
    unsigned long m = timer0_millis;
    unsigned long err = timer0_err;

    /* Increment our timer and error */
    m += MILLIS_INC;
    err += ERR_INC;

    if (err >= ERR_MAX)
    {
        /* Adjust the ms accordingly and reset our error */
        m += MILLIS_INC;
        err -= ERR_MAX; // Will still hold the remaining error in this
    }

    timer0_millis = m;
    timer0_err = err;
}

void sys_time_init(void)
{

    // Set prescaler to be 64
    TCCR0B |= (1 << CS00) | (1 << CS01);

    // Enable interrupts on overflow
    TIMSK0 |= (1 << TOIE0);

    // Enable global interrupts
    sei();
}

unsigned long sys_time_elapsed(void)
{

    unsigned long m;
    uint8_t oldSREG = SREG;

    // disable interrupts while we read timer0_millis or we might get an
    // inconsistent value (e.g. in the middle of a write to timer0_millis)
    cli();
    m = timer0_millis;
    SREG = oldSREG;

    return m;
}

unsigned long sys_time_err(void)
{

    unsigned long m;
    uint8_t oldSREG = SREG;

    // disable interrupts while we read timer0_millis or we might get an
    // inconsistent value (e.g. in the middle of a write to timer0_millis)
    cli();
    m = timer0_err;
    SREG = oldSREG;

    return m;
}