/*!
 * @file Geegrow_ILI9341_libLettersCyrillic.cpp
 *
 * This is an addon library for the Geegrow ILI9341 TFT 240x320 display,
 * which implements bitmaps of cyrillic letters
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "Geegrow_ILI9341_libLettersCyrillic.h"

/**************************************************************************/
/*!
    @brief    Get a bitmap of certain symbol
    @param    _char    Requested symbol
    @return   Pointer to bitmap array
*/
/**************************************************************************/
uint16_t* Geegrow_ILI9341_libLettersCyrillic::getBitMap(char _char, uint8_t _encoding){
    uint16_t idx = 0;
    if (_encoding == ENCODING_UTF8)
        if ((uint8_t)_char >= 144 && (uint8_t)_char <= 175)         // А - Я
            idx = ((uint8_t)_char - 144) * FONT_WIDTH;
        else if ((uint8_t)_char >= 176 && (uint8_t)_char <= 191)    // а - п
            idx = ((uint8_t)_char - 176 + 32) * FONT_WIDTH;
        else if ((uint8_t)_char >= 128 && (uint8_t)_char <= 143)    // р - я
            idx = ((uint8_t)_char - 128 + 32 + 16) * FONT_WIDTH;
        else {
            Serial.print(F("getBitMap(): char not supported: "));
            Serial.println((uint8_t)_char, DEC);
            return;
        }

    if (_encoding == ENCODING_CP1251)
        if ((uint8_t)_char >= 192 && (uint8_t)_char <= 255)
            idx = ((uint8_t)_char - 192) * FONT_WIDTH;
        else {
            Serial.print(F("getBitMap(): char not supported: "));
            Serial.println((uint8_t)_char, DEC);
            return;
        }

    return (fontLibLettersCyrillic + idx);
}
