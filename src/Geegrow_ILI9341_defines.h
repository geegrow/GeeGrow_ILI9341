#ifndef GEEGROW_ILI9341_DEFINES_H
#define GEEGROW_ILI9341_DEFINES_H

/**************************************************************************/
/*!
    @brief    Colors
*/
/**************************************************************************/
#define BLACK       0x0000
#define NAVY        0x000F
#define DARKGREEN   0x03E0
#define DARKCYAN    0x03EF
#define MAROON      0x7800
#define PURPLE      0x780F
#define OLIVE       0x7BE0
#define LIGHTGREY   0xC618
#define DARKGREY    0x7BEF
#define BLUE        0x001F
#define GREEN       0x07E0
#define CYAN        0x07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define YELLOW      0xFFE0
#define WHITE       0xFFFF
#define ORANGE      0xFD20
#define GREENYELLOW 0xAFE5
#define PINK        0xF81F

/**************************************************************************/
/*!
    @brief    Initialization commands from datasheet
*/
/**************************************************************************/
#define CMD_NOP                      0x00
#define CMD_SOFTWARE_RESET           0x01
#define CMD_POWER_CONTROL_1          0xC0
#define CMD_POWER_CONTROL_2          0xC1
#define CMD_VCOM_CONTROL_1           0xC5
#define CMD_VCOM_CONTROL_2           0xC7
#define CMD_MEMORY_ACCESS_CONTROL    0x36
#define CMD_PIXEL_FORMAT_SET         0x3A
#define CMD_FRAME_RATE_CONTROL       0xB1
#define CMD_GAMMA_SET                0x26
#define CMD_POS_GAMMA_CORRECTION     0xE0
#define CMD_NEG_GAMMA_CORRECTION     0xE1
#define CMD_COLUMN_ADDRESS_SET       0x2A
#define CMD_PAGE_ADDRESS_SET         0x2B
#define CMD_ENTRY_MODE_SET           0xB7
#define CMD_DISPLAY_FUNCTION_CONTROL 0xB6
#define CMD_ENTER_SLEEP_MODE         0x10
#define CMD_SLEEP_OUT                0x11
#define CMD_DISPLAY_OFF              0x28
#define CMD_DISPLAY_ON               0x29
#define CMD_MEMORY_WRITE             0x2C

/**************************************************************************/
/*!
    @brief    Hardware screen resolution
*/
/**************************************************************************/
#define LCD_WIDTH   240
#define LCD_HEIGHT  320

/**************************************************************************/
/*!
    @brief    Font size
*/
/**************************************************************************/
#define FONT_WIDTH  8
#define FONT_HEIGHT 16

/**************************************************************************/
/*!
    @brief    Libraries that can be attached
*/
/**************************************************************************/
#define LIB_NUMBERS_ASCII       (1 << 1)
#define LIB_LETTERS_ASCII       (1 << 2)
#define LIB_SYMBOLS_ASCII       (1 << 3)
#define LIB_LETTERS_CYRILLIC    (1 << 4)
#define LIB_DEVICE_SD           (1 << 5)

/**************************************************************************/
/*!
    @brief    Encodings
*/
/**************************************************************************/
#define ENCODING_UTF8   1
#define ENCODING_CP1251 2

#endif /* GEEGROW_ILI9341_DEFINES_H */
