/*!
 * @file GeeGrow_ILI9341_libSymbolsAscii.cpp
 *
 * This is an addon library for the GeeGrow ILI9341 TFT 240x320 display,
 * which implements bitmaps of ASCII special symbols
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "GeeGrow_ILI9341_libSymbolsAscii.h"

/**************************************************************************/
/*!
    @brief    Get a bitmap of certain symbol
    @param    _char    Requested symbol
    @return   Pointer to bitmap array
*/
/**************************************************************************/
uint16_t* GeeGrow_ILI9341_libSymbolsAscii::getBitMap(char _char){
    uint16_t idx = 0;
    // Check the number of "block" in ASCII which contains the synbol
    if ((uint8_t)_char >= 32 && (uint8_t)_char <= 47)
        idx = ((uint8_t)_char - 32) * FONT_WIDTH;
    else if ((uint8_t)_char >= 58 && (uint8_t)_char <= 64)
        idx = ((uint8_t)_char - 58 + 16) * FONT_WIDTH;
    else if ((uint8_t)_char >= 91 && (uint8_t)_char <= 96)
        idx = ((uint8_t)_char - 91 + 16 + 7) * FONT_WIDTH;
    else if ((uint8_t)_char >= 123 && (uint8_t)_char <= 126)
        idx = ((uint8_t)_char - 123 + 16 + 7 + 6) * FONT_WIDTH;
    else {
        Serial.print(F("getBitMap(): char not supported: "));
        Serial.println((uint8_t)_char, DEC);
        return;
    }
    return (fontLibSymbolsAscii + idx);
}
