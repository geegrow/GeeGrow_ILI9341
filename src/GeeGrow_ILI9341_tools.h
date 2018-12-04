/*!
 * @file GeeGrow_ILI9341_tools.h
 *
 * These are auxiliary structs and defines for GeeGrow ILI9341 library
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef GEEGROW_ILI9341_TOOLS_H
#define GEEGROW_ILI9341_TOOLS_H

#include <Arduino.h>

/**************************************************************************/
/*!
    @brief  Pull down and up WR pin to flush data from integral circuit to
			display's RAM
*/
/**************************************************************************/
#define SWAP_WR(num)	{	digitalWrite(num, LOW);		\
							__asm__("nop\n\t");			\
							digitalWrite(num, HIGH);	\
						}

/**************************************************************************/
/*!
    @brief  Swap two numbers
*/
/**************************************************************************/
#define SWAP(a, b) {uint16_t t = a; a = b; b = t;}

/**************************************************************************/
/*!
    @brief  Struct to store pins
*/
/**************************************************************************/
struct pins_t {
	uint8_t led;
	uint8_t reset;
	uint8_t dc;
	uint8_t wr;
	uint8_t cs;
};

/**************************************************************************/
/*!
    @brief  Struct to store current display parameters
*/
/**************************************************************************/
struct params_t {
	int16_t width;
	int16_t height;
	uint8_t rotation;
};

/**************************************************************************/
/*!
    @brief  Rotation modes
*/
/**************************************************************************/
enum {	ROTATION_UP,
		ROTATION_DOWN,
		ROTATION_LEFT,
		ROTATION_RIGHT
	};

/**************************************************************************/
/*!
    @brief  IDs for different types of objects
*/
/**************************************************************************/
enum {	OBJ_PIXEL,
		OBJ_LINE,
		OBJ_RECT,
		OBJ_FILL_RECT,
		OBJ_CIRCLE,
		OBJ_FILL_CIRCLE,
		OBJ_TRIANGLE
	};

/**************************************************************************/
/*!
    @brief  Parent class for main class and object classes, which allows
			object classes to use drawing functions of main class
*/
/**************************************************************************/
class GeeGrow_ILI9341_partnership {
	public:
		virtual int8_t drawPixel(int16_t _x0, int16_t _y0, uint16_t _color) = 0;
		virtual int8_t drawLine(
			int16_t _x0,
			int16_t _y0,
			int16_t _x1,
			int16_t _y1,
			uint16_t _color
		) = 0;
		virtual int8_t drawRect(
			int16_t _x0,
			int16_t _y0,
			int16_t _width,
			int16_t _height,
			uint16_t _color
		) = 0;
		virtual int8_t fillRect(
			int16_t _x0,
			int16_t _y0,
			int16_t _width,
			int16_t _height,
			uint16_t _color
		) = 0;
		virtual int8_t drawCircle(
			int16_t _x0,
			int16_t _y0,
			int16_t _radius,
			uint16_t _color
		) = 0;
		virtual int8_t fillCircle(
			int16_t _x0,
			int16_t _y0,
			int16_t _radius,
			uint16_t _color
		) = 0;
		virtual int8_t drawTriangle(
			int16_t _x0,
			int16_t _y0,
			int16_t _x1,
			int16_t _y1,
			int16_t _x2,
			int16_t _y2,
			uint16_t _color
		) = 0;
};


#endif /* GEEGROW_ILI9341_TOOLS_H */
