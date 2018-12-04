/*!
 * @file GeeGrow_ILI9341.h
 *
 * This is a library for the GeeGrow ILI9341 TFT 240x320 display
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef GEEGROW_ILI9341_H
#define GEEGROW_ILI9341_H

#include <SPI.h>
#include "GeeGrow_ILI9341_tools.h"
#include "libFonts/GeeGrow_ILI9341_libLettersAscii.h"
#include "libFonts/GeeGrow_ILI9341_libNumbersAscii.h"
#include "libFonts/GeeGrow_ILI9341_libSymbolsAscii.h"
#include "libFonts/GeeGrow_ILI9341_libLettersCyrillic.h"
#include "libObjects/GeeGrow_ILI9341_objectPixel.h"
#include "libObjects/GeeGrow_ILI9341_objectLine.h"
#include "libObjects/GeeGrow_ILI9341_objectRect.h"
#include "libObjects/GeeGrow_ILI9341_objectFillRect.h"
#include "libObjects/GeeGrow_ILI9341_objectCircle.h"
#include "libObjects/GeeGrow_ILI9341_objectFillCircle.h"
#include "libObjects/GeeGrow_ILI9341_objectTriangle.h"
#include "libDevices/GeeGrow_ILI9341_deviceSD.h"

/**************************************************************************/
/*!
	@brief  Class that stores state and functions for interacting with ILI9341 display
*/
/**************************************************************************/
class GeeGrow_ILI9341 : public GeeGrow_ILI9341_partnership {
	public:
		GeeGrow_ILI9341();
		~GeeGrow_ILI9341(){}
		void init(uint8_t _led, uint8_t _reset, uint8_t _dc, uint8_t _wr, uint8_t _cs);
		void turnLedOn();
		void turnLedOff();
		void turnDisplayOn();
		void turnDisplayOff();
		int8_t drawPixel(int16_t _x0, int16_t _y0, uint16_t _color);
		void fillDisplay(uint16_t _color);
		void setRotation(uint8_t _rotation);
		uint8_t getRotation();
		int16_t getWidth();
		int16_t getHeight();
		void attachLibs(uint8_t _libs);
		void setEncoding(uint8_t _encoding);
		int8_t getEncoding();
		void drawFastVLine(int16_t _x0, int16_t _y0, int16_t _height, uint16_t _color);
		void drawFastHLine(int16_t _x0, int16_t _y0, int16_t _width, uint16_t _color);
		int8_t drawRect(
			int16_t _x0,
			int16_t _y0,
			int16_t _width,
			int16_t _height,
			uint16_t _color
		);
		int8_t fillRect(
			int16_t _x0,
			int16_t _y0,
			int16_t _width,
			int16_t _height,
			uint16_t _color
		);
		int8_t drawCircle(int16_t _x0, int16_t _y0, int16_t _radius, uint16_t _color);
		int8_t fillCircle(int16_t _x0, int16_t _y0, int16_t _radius, uint16_t _color);
		int8_t drawLine(int16_t _x0, int16_t _y0, int16_t _x1, int16_t _y1, uint16_t _color);
		int8_t drawTriangle(
			int16_t _x0,
			int16_t _y0,
			int16_t _x1,
			int16_t _y1,
			int16_t _x2,
			int16_t _y2,
			uint16_t _color
		);
		void printChar(char _char, int16_t _x0, int16_t _y0, uint8_t _size, uint16_t _color);
		void printStr(String _str, int16_t _x0, int16_t _y0, uint8_t _size, uint16_t _color);
		int8_t initSD(uint8_t _cs_sd);
		int8_t showBMPfromSD(int16_t _x0, int16_t _y0, char *_filename);
		GeeGrow_ILI9341_objectBase* createPixelObj();
		GeeGrow_ILI9341_objectBase* createLineObj();
		GeeGrow_ILI9341_objectBase* createRectObj();
		GeeGrow_ILI9341_objectBase* createFillRectObj();
		GeeGrow_ILI9341_objectBase* createCircleObj();
		GeeGrow_ILI9341_objectBase* createFillCircleObj();
		GeeGrow_ILI9341_objectBase* createTriangleObj();

	private:
		int16_t castX(int16_t _x0, int16_t _y0);
		int16_t castY(int16_t _x0, int16_t _y0);
		void castSelectedRange(int16_t _x0, int16_t _y0, int16_t _x1, int16_t _y1);
		void setColumn(int16_t _start, int16_t _end);
		void setPage(int16_t _start, int16_t _end);
		void sendSpiCmd(uint8_t _cmd);
		void sendSpiData(uint8_t _data);
		void sendSpiData16(uint16_t _data);
		void writeMemory(uint32_t _num, uint16_t _color);
		void writeMemoryBuf(uint32_t _num, uint16_t *_buf);
		void OnSettingsForBMP();
		void OffSettingsForBMP();
		void castSelectedRangeForBMP(
			int16_t _x0,
			int16_t _y0,
			uint16_t _block_size_pixels,
			uint16_t _blocks_num,
			uint16_t i
		);
		pins_t pins;
		params_t params;
		uint8_t encoding;
		GeeGrow_ILI9341_libLettersAscii *libLettersAscii = NULL;
		GeeGrow_ILI9341_libNumbersAscii *libNumbersAscii = NULL;
		GeeGrow_ILI9341_libSymbolsAscii *libSymbolsAscii = NULL;
		GeeGrow_ILI9341_libLettersCyrillic *libLettersCyrillic = NULL;
		GeeGrow_ILI9341_deviceSD *deviceSD = NULL;
};

extern GeeGrow_ILI9341 display;

#endif /* GEEGROW_ILI9341_H */
