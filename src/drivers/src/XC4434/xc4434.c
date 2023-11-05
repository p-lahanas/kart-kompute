#include <avr/io.h>
#include <avr/interrupt.h>
#include "xc4434.h"

#if !defined(HE_EICRA_VAL)
#error HE_EICRA_MASK is not defined.
#endif
#if !defined(HE_EIMSK_INT0_MASK)
#error HE_EIMSK_INT0_MASK is not defined
#endif

#define he_eicra_set() HE_EICRA_REG |= HE_EICRA_VAL

void he_init(void)
{
    sei(); // Enable global interrupts

    he_eimsk_int0_enable();
    he_eicra_set(); // Set interrupt control
}

void he_close(void)
{
    he_eimsk_int0_disable();
}