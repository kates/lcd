#ifndef __LCD_H__
#define __LCD_H__
#include "lcd_config.h"

#ifndef LCD_PORT
	#error "LCD_PORT not defined!"
#endif

#ifndef LCD_DIR
	#error "LCD_DIR not defined!"
#endif

#ifndef LCD_RS
	#error "LCD_RS not defined!"
#endif

#ifndef LCD_EN
	#error "LCD_EN not defined!"
#endif

#ifndef LCD_D4
	#error "LCD_D4 not defined!"
#endif

#ifndef LCD_D5
	#error "LCD_D5 not defined!"
#endif

#ifndef LCD_D6
	#error "LCD_D6 not defined!"
#endif

#ifndef LCD_D7
	#error "LCD_D7 not defined!"
#endif

void lcd_init(void);
void lcd_writeln(const char *str);
uint8_t lcd_write(const char *str);
void lcd_go(uint8_t row, uint8_t col);
void lcd_go_line(uint8_t line);
#endif // __LCD_H__
