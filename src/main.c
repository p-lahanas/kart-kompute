#include <avr/io.h>
#include <util/delay.h>
#include "app/tacho.h"

int main(void)
{
    // lcd_init();

    // while (1)
    // {

    //     lcd_clrscr();
    //     lcd_puts("Hello World 2...");

    //     lcd_goto(40); // Position 40 is the start of line 2
    //     char digit[1];
    //     for (int i = 0; i < 16; i++)
    //     {
    //         _delay_ms(250);
    //         itoa(i, digit, 16);
    //         lcd_puts(digit);
    //     }
    // }
    // ENABLE THIS AS OUTPUT FOR OUT TESTING
    DDRB |= _BV(PINB5);
    tacho_init();


    
    while (1) {
        
    }

    return (0);
}