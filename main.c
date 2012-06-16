#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "lcd.h"

int main(void) {
  uint8_t i = 1;
  lcd_init();
  while (1) {
    if (i ^= 1) {
      lcd_go_line(1);
      lcd_writeln("Hello World!");
      lcd_go_line(2);
      lcd_writeln("AVR LCD Library");
    } else {
      lcd_go_line(1);
      lcd_writeln("HD44780");
      lcd_go_line(2);
      lcd_writeln("ST7066U");
    }
    _delay_ms(2000);
  }
  return 0;
}
