/*
 * Define pins and ports here
 */

#define LCD_PORT PORTB
#define LCD_DIR DDRB

#define LCD_RS _BV(PB0)
#define LCD_EN _BV(PB2)

#define LCD_D4 _BV(PB4)
#define LCD_D5 _BV(PB5)
#define LCD_D6 _BV(PB6)
#define LCD_D7 _BV(PB7)

// how many columns? default is 16
//#define LCD_COLUMNS 16
