#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "lcd_config.h"
#include "lcd.h"

uint8_t lcd_pins[4] = {LCD_D4, LCD_D5, LCD_D6, LCD_D7};

void lcd_send4(uint8_t data) {
	uint8_t i;
  LCD_PORT |= LCD_EN;
	for (i = 0; i < 4; i++) {
		if (data & (1 << i)){
			LCD_PORT |= lcd_pins[i];
		} else {
			LCD_PORT &= ~lcd_pins[i];
		}
	}
  _delay_us(1);
  LCD_PORT &= ~LCD_EN;
  LCD_PORT &= ~(LCD_DATA_PINS);
  _delay_us(1);
}

void lcd_send(uint8_t cmd, uint8_t data) {
  LCD_PORT &= ~(LCD_RS | LCD_EN | LCD_DATA_PINS);

  if (cmd & LCD_DATA) {
    LCD_PORT |= LCD_RS;
  }

  lcd_send4(data >> 4);

  if (cmd & LCD_CMD) {
    _delay_ms(5);
  } else {
    _delay_us(1);
  }

  lcd_send4(data & 0x0F);

  if (cmd & LCD_DATA) {
    LCD_PORT &= ~LCD_RS;
  }

  _delay_us(200);
}

void lcd_char(uint8_t data) {
  lcd_send(LCD_DATA, data);
}

void lcd_cmd(uint8_t data) {
  lcd_send(LCD_CMD, data);
}

uint8_t lcd_write(const char *str) {
  uint8_t i = 0;
  while (*str) {
    lcd_char(*str++);
    i++;
  }
  return i;
}

void lcd_writeln(const char *str) {
  uint8_t i = lcd_write(str);
	while(i++ < LCD_COLUMNS) {
		lcd_char(' ');
	}
}

void lcd_init(void) {
  LCD_DIR |= LCD_RS | LCD_EN | LCD_DATA_PINS;
  LCD_PORT &= ~(LCD_RS | LCD_EN | LCD_DATA_PINS);

  _delay_ms(20); // give lcd time to startup

  lcd_send4(0x03);
  _delay_ms(5);

  if (LCD_MODE == LCD_MODE_4) {
    lcd_send4(0x02);
    _delay_us(37);
  }

  lcd_cmd(0x28);
  lcd_cmd(0x01);
  lcd_cmd(0x06);
  _delay_us(1200);
  lcd_cmd(0x0C);
}

void lcd_go(uint8_t row, uint8_t col) {
  if (row == 4) {
    lcd_cmd(LCD_LINE_4 + col);
	} else if (row == 3) {
    lcd_cmd(LCD_LINE_3 + col);
	} else if (row == 2) {
    lcd_cmd(LCD_LINE_2 + col);
	} else {
    lcd_cmd(LCD_LINE_1 + col);
  }
}

void lcd_go_line(uint8_t line) {
  lcd_go(line, 0);
}

