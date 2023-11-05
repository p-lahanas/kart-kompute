#ifndef XC4434_SETTINGS_H
#define XC4434_SETTINGS_H

#define HE_S_PORT PORTD
#define HE_S_PIN 2 // Can use INT0

#define HE_EICRA_REG EICRA
#define HE_EICRA_VAL 0x02   // 0x00 low level generates interrupt,
                            // 0x01 any changing edge, 
                            // 0x02 falling edge, 
                            // 0x03 rising edge

#define HE_EIMSK_REG EIMSK
#define HE_EIMSK_INT0_MASK 0x01  // 1 to enable INT0 else 0


#endif