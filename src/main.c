#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lib/HD44780/hd44780.h"


int main (void)
{
    lcd_init();

    while (1) {

        lcd_clrscr();
        lcd_puts("Hello World...");   
    
        lcd_goto(40);                    //Position 40 is the start of line 2
        char digit[1];
        for (int i=0;i<16;i++) {
            _delay_ms(250);
            itoa(i,digit,16);
            lcd_puts(digit);
        }

    }

 
    return(0);
}