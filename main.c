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
      lcd_write("Hello World!");
      lcd_go_line(2);
      lcd_write("AVR LCD Library");
    } else {
      lcd_go_line(1);
      lcd_write("HD44780");
      lcd_go_line(2);
      lcd_write("ST7066U");
    }
    _delay_ms(2000);
  }
  return 0;
}
