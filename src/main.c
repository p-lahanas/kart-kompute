#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "hd44780.h"
#include "app/kartstats.h"

int main(void)
{
    kartstats_init(); 
    lcd_init();
    char digit[6];
    DDRB |= _BV(PINB5);
    
    while (1)
    {
        kartstats_update();
        lcd_clrscr();
        lcd_puts("Speed: ");

        lcd_goto(40); // Position 40 is the start of line 2
        
        ultoa(kartstats_get_speed(), digit, 10);
        lcd_puts(digit);
        lcd_puts("km/hr");
        _delay_ms(300);
    }
    

    return (0);
}