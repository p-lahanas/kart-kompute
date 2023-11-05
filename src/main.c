#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "hd44780.h"
#include "app/tacho.h"

int main(void)
{
    lcd_init();
    tacho_init();
    char digit[6];
    DDRB |= _BV(PINB5);
    
    while (1)
    {

        lcd_clrscr();
        lcd_puts("RPM: ");

        lcd_goto(40); // Position 40 is the start of line 2
        
        ultoa(tacho_get_rpm(), digit, 10);
        lcd_puts(digit);
        _delay_ms(1000);
    }
    

    return (0);
}