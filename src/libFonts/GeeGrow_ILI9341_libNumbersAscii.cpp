/*!
 * @file GeeGrow_ILI9341_libNumbersAscii.cpp
 *
 * This is an addon library for the GeeGrow ILI9341 TFT 240x320 display,
 * which implements bitmaps of ASCII numbers
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "GeeGrow_ILI9341_libNumbersAscii.h"

/**************************************************************************/
/*!
    @brief    Get a bitmap of certain symbol
    @param    _char    Requested symbol
    @return   Pointer to bitmap array
*/
/**************************************************************************/
uint16_t* GeeGrow_ILI9341_libNumbersAscii::getBitMap(char _char){
    uint16_t idx = 0;
    if ((uint8_t)_char >= 48 && (uint8_t)_char <= 57)
        idx = ((uint8_t)_char - 48) * FONT_WIDTH;
    else {
        Serial.print(F("getBitMap(): char not supported: "));
        Serial.println((uint8_t)_char, DEC);
        return;
    }
    return (fontLibNumbersAscii + idx);
}
