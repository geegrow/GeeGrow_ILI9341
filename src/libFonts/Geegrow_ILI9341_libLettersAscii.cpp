/*!
 * @file Geegrow_ILI9341_libLettersAscii.cpp
 *
 * This is an addon library for the Geegrow ILI9341 TFT 240x320 display,
 * which implements bitmaps of ASCII letters
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "Geegrow_ILI9341_libLettersAscii.h"

/**************************************************************************/
/*!
    @brief    Get a bitmap of certain symbol
    @param    _char    Requested symbol
    @return   Pointer to bitmap array
*/
/**************************************************************************/
uint16_t* Geegrow_ILI9341_libLettersAscii::getBitMap(char _char){
    uint16_t idx = 0;
    // Check if letter is uppercase or lowercase
    if ((uint8_t)_char >= 65 && (uint8_t)_char <= 90)            // Uppercase
        idx = ((uint8_t)_char - 65) * FONT_WIDTH;
    else if ((uint8_t)_char >= 97 && (uint8_t)_char <= 122)      // Lowercase
        idx = ((uint8_t)_char - 97 + 26) * FONT_WIDTH;
    else {
        Serial.print(F("getBitMap(): char not supported: "));
        Serial.println((uint8_t)_char, DEC);
        return;
    }
    return (fontLibLettersAscii + idx);
}
