#ifndef XC4434_H
#define XC4434_H

#include "xc4434_settings.h"


void he_init(void);
void he_close(void);
void he_isr(void);

#define he_eimsk_int0_enable() HE_EIMSK_REG |= HE_EIMSK_INT0_MASK
#define he_eimsk_int0_disable() HE_EIMSK_REG &= ~HE_EIMSK_INT0_MASK

#endif