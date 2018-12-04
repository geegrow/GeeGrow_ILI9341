/*!
 * @file GeeGrow_ILI9341_libNumbersAscii.h
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

#ifndef GEEGROW_ILI9341_LIBNUMBERS_ASCII_H
#define GEEGROW_ILI9341_LIBNUMBERS_ASCII_H

#include <Arduino.h>
#include <avr/pgmspace.h>
#include <GeeGrow_ILI9341_defines.h>

/**************************************************************************/
/*!
    @brief  Class that stores state and functions for implementing bitmaps
			of ASCII numbers
*/
/**************************************************************************/
class GeeGrow_ILI9341_libNumbersAscii {
	public:
		GeeGrow_ILI9341_libNumbersAscii(){}
		~GeeGrow_ILI9341_libNumbersAscii(){}
		uint16_t* getBitMap(char _char);
};

/**************************************************************************/
/*!
    @brief  Bitmaps of ASCII numbers
*/
/**************************************************************************/
const uint16_t fontLibNumbersAscii[] PROGMEM = {
	0x07F8, 0x0FFC, 0x0984, 0x08C4, 0x0864, 0x0FFC, 0x07F8, 0x0000,		// 0
	0x0000, 0x0810, 0x0818, 0x0FFC, 0x0FFC, 0x0800, 0x0800, 0x0000,		// 1
	0x0E08, 0x0F0C, 0x0984, 0x08C4, 0x0864, 0x0C3C, 0x0C18, 0x0000,		// 2
	0x0408, 0x0C0C, 0x0844, 0x0844, 0x0844, 0x0FFC, 0x07B8, 0x0000,		// 3
	0x01C0, 0x01E0, 0x0130, 0x0918, 0x0FFC, 0x0FFC, 0x0900, 0x0000,		// 4
	0x047C, 0x0C7C, 0x0844, 0x0844, 0x0844, 0x0FC4, 0x0780, 0x0000,		// 5
	0x07F8, 0x0FFC, 0x0844, 0x0844, 0x0844, 0x0FCC, 0x0788, 0x0000,		// 6
	0x000C, 0x000C, 0x0F04, 0x0F84, 0x00C4, 0x007C, 0x003C, 0x0000,		// 7
	0x07B8, 0x0FFC, 0x0844, 0x0844, 0x0844, 0x0FFC, 0x07B8, 0x0000,		// 8
	0x0438, 0x0C7C, 0x0844, 0x0844, 0x0844, 0x0FFC, 0x07F8, 0x0000		// 9
};

#endif /* GEEGROW_ILI9341_LIBNUMBERS_ASCII_H */
