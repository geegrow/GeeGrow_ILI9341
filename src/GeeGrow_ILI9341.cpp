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

#include "GeeGrow_ILI9341.h"

/**************************************************************************/
/*!
    @brief    Instantiate GeeGrow SSD1306 driver for 128x32 display
*/
/**************************************************************************/
GeeGrow_ILI9341::GeeGrow_ILI9341(){
    // Default params
    this->setRotation(ROTATION_UP);
}

/**************************************************************************/
/*!
    @brief    Configuration and init sequence for ILI9341 display
    @param    _led      LED pin
    @param    _reset    RESET pin
    @param    _dc       DC pin
    @param    _wr       WR pin
    @param    _cs       CS pin
*/
/**************************************************************************/
void GeeGrow_ILI9341::init(uint8_t _led, uint8_t _reset, uint8_t _dc, uint8_t _wr, uint8_t _cs){
    // Pinout
    this->pins.led      = _led;
    this->pins.reset    = _reset;
    this->pins.dc       = _dc;
    this->pins.wr       = _wr;
    this->pins.cs       = _cs;
    // Pin configuration
    pinMode(this->pins.led, OUTPUT);
    pinMode(this->pins.reset, OUTPUT);
    pinMode(this->pins.dc, OUTPUT);
    pinMode(this->pins.wr, OUTPUT);
    pinMode(this->pins.cs, OUTPUT);
    // SPI
    SPI.begin();
    // Hardware Reset
    digitalWrite(this->pins.reset, HIGH);
    delay(1);
    digitalWrite(this->pins.reset, LOW);
    delay(10);
    digitalWrite(this->pins.reset, HIGH);
    delay(120);
    // Software Reset
    this->sendSpiCmd(CMD_SOFTWARE_RESET);
    delay(5);
    this->sendSpiCmd(CMD_DISPLAY_OFF);
    // Power control
    this->sendSpiCmd(CMD_POWER_CONTROL_1);
    this->sendSpiData(0x26);
    this->sendSpiCmd(CMD_POWER_CONTROL_2);
    this->sendSpiData(0x11);
    this->sendSpiCmd(CMD_VCOM_CONTROL_1);
    this->sendSpiData(0x5C);
    this->sendSpiData(0x4C);
    this->sendSpiCmd(CMD_VCOM_CONTROL_2);
    this->sendSpiData(0x94);
    // Memory access control
    this->sendSpiCmd(CMD_MEMORY_ACCESS_CONTROL);
    this->sendSpiData(0x48);
    this->sendSpiCmd(CMD_PIXEL_FORMAT_SET);
    this->sendSpiData(0x55);
    // Frame rate control
    this->sendSpiCmd(CMD_FRAME_RATE_CONTROL);
    this->sendSpiData(0x00);
    this->sendSpiData(0x1B);
    // Gamma
    this->sendSpiCmd(CMD_GAMMA_SET);
    this->sendSpiData(0x01);
    this->sendSpiCmd(CMD_POS_GAMMA_CORRECTION);
    this->sendSpiData(0x1F);
    this->sendSpiData(0x1A);
    this->sendSpiData(0x18);
    this->sendSpiData(0x0A);
    this->sendSpiData(0x0F);
    this->sendSpiData(0x06);
    this->sendSpiData(0x45);
    this->sendSpiData(0x87);
    this->sendSpiData(0x32);
    this->sendSpiData(0x0A);
    this->sendSpiData(0x07);
    this->sendSpiData(0x02);
    this->sendSpiData(0x07);
    this->sendSpiData(0x05);
    this->sendSpiData(0x00);
    this->sendSpiCmd(CMD_NEG_GAMMA_CORRECTION);
    this->sendSpiData(0x00);
    this->sendSpiData(0x25);
    this->sendSpiData(0x27);
    this->sendSpiData(0x05);
    this->sendSpiData(0x10);
    this->sendSpiData(0x09);
    this->sendSpiData(0x3A);
    this->sendSpiData(0x78);
    this->sendSpiData(0x4D);
    this->sendSpiData(0x05);
    this->sendSpiData(0x18);
    this->sendSpiData(0x0D);
    this->sendSpiData(0x38);
    this->sendSpiData(0x3A);
    this->sendSpiData(0x1F);
    // DDRam
    this->sendSpiCmd(CMD_COLUMN_ADDRESS_SET);
    this->sendSpiData(0x00);
    this->sendSpiData(0x00);
    this->sendSpiData(0x00);
    this->sendSpiData(0xEF);
    this->sendSpiCmd(CMD_PAGE_ADDRESS_SET);
    this->sendSpiData(0x00);
    this->sendSpiData(0x00);
    this->sendSpiData(0x01);
    this->sendSpiData(0x3F);
    this->sendSpiCmd(CMD_ENTRY_MODE_SET);
    this->sendSpiData(0x07);
    // Display
    this->sendSpiCmd(CMD_DISPLAY_FUNCTION_CONTROL);
    this->sendSpiData(0x0A);
    this->sendSpiData(0x82);
    this->sendSpiData(0x27);
    this->sendSpiData(0x00);
    this->sendSpiCmd(CMD_SLEEP_OUT);
    delay(100);
    this->turnDisplayOn();
    this->turnLedOn();
}

/**************************************************************************/
/*!
    @brief    Turn on LED on display
*/
/**************************************************************************/
void GeeGrow_ILI9341::turnLedOn(){
    digitalWrite(this->pins.led, HIGH);
}

/**************************************************************************/
/*!
    @brief    Turn off LED on display
*/
/**************************************************************************/
void GeeGrow_ILI9341::turnLedOff(){
    digitalWrite(this->pins.led, LOW);
}

/**************************************************************************/
/*!
    @brief    Turn on display
*/
/**************************************************************************/
void GeeGrow_ILI9341::turnDisplayOn(){
    this->sendSpiCmd(CMD_DISPLAY_ON);
    delay(100);
}

/**************************************************************************/
/*!
    @brief    Turn off display
*/
/**************************************************************************/
void GeeGrow_ILI9341::turnDisplayOff(){
    this->sendSpiCmd(CMD_DISPLAY_OFF);
    delay(100);
}

/**************************************************************************/
/*!
    @brief    Select range of columns in display's RAM
    @param    _start    Start of range
    @param    _end      End of range
*/
/**************************************************************************/
void GeeGrow_ILI9341::setColumn(int16_t _start, int16_t _end){
    this->sendSpiCmd(CMD_COLUMN_ADDRESS_SET);
    this->sendSpiData(_start >> 8);
    this->sendSpiData(_start & 0xFF);
    this->sendSpiData(_end >> 8);
    this->sendSpiData(_end & 0xFF);
}

/**************************************************************************/
/*!
    @brief    Select range of pages (rows) in display's RAM
    @param    _start    Start of range
    @param    _end      End of range
*/
/**************************************************************************/
void GeeGrow_ILI9341::setPage(int16_t _start, int16_t _end){
    this->sendSpiCmd(CMD_PAGE_ADDRESS_SET);
    this->sendSpiData(_start >> 8);
    this->sendSpiData(_start & 0xFF);
    this->sendSpiData(_end >> 8);
    this->sendSpiData(_end & 0xFF);
}

/**************************************************************************/
/*!
    @brief    Draw a certain pixel of a certain color
    @param    _x0        X coordinate of pixel
    @param    _y0        Y coordinate of pixel
    @param    _color     Color of pixel to draw
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::drawPixel(int16_t _x0, int16_t _y0, uint16_t _color){
    int16_t w = this->params.width;
    int16_t h = this->params.height;
    // check coordinates
    if ( (_x0 < 0) || (_y0 < 0) || (_x0 >= w) || (_y0 >= h) ) {
        Serial.println(F("drawPixel():  invalid coordinates"));
        return -1;
    }

    int16_t xt = this->castX(_x0, _y0);
    int16_t yt = this->castY(_x0, _y0);
    this->setColumn(xt, xt);
    this->setPage(yt, yt);
    this->writeMemory(1, _color);
    return 0;
}

/**************************************************************************/
/*!
    @brief    Fill screen with certain color
    @param    _color    Color to fill screen
*/
/**************************************************************************/
void GeeGrow_ILI9341::fillDisplay(uint16_t _color){
    int16_t dx = LCD_WIDTH;
    int16_t dy = LCD_HEIGHT;
    this->setColumn(0, dx - 1);
    this->setPage(0, dy - 1);
    this->writeMemory((uint32_t)dx*dy, _color);
}

/**************************************************************************/
/*!
    @brief    Set rotation mode
    @param    _rotation    Rotation mode
*/
/**************************************************************************/
void GeeGrow_ILI9341::setRotation(uint8_t _rotation){
    this->params.rotation = _rotation;
    switch (_rotation){
        case ROTATION_UP:
            this->params.width = LCD_HEIGHT;
            this->params.height = LCD_WIDTH;
            break;
        case ROTATION_DOWN:
            this->params.width = LCD_HEIGHT;
            this->params.height = LCD_WIDTH;
            break;
        case ROTATION_LEFT:
            this->params.width = LCD_WIDTH;
            this->params.height = LCD_HEIGHT;
            break;
        case ROTATION_RIGHT:
            this->params.width = LCD_WIDTH;
            this->params.height = LCD_HEIGHT;
            break;
        default:
            break;
    }
}

/**************************************************************************/
/*!
    @brief    Get current rotation mode
    @return   Value of rotation mode
*/
/**************************************************************************/
uint8_t GeeGrow_ILI9341::getRotation(){
    return this->params.rotation;
}

/**************************************************************************/
/*!
    @brief    Get current width of display
    @return   Value of width
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341::getWidth(){
    return this->params.width;
}

/**************************************************************************/
/*!
    @brief    Get current height of display
    @return   Value of height
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341::getHeight(){
    return this->params.height;
}

/**************************************************************************/
/*!
    @brief    Attach separate libraries with different symbol packs and addon features
    @param    _libs    Bitmask which defines libs that should be attached
*/
/**************************************************************************/
void GeeGrow_ILI9341::attachLibs(uint8_t _libs){
    // Create objects according to libs
    if (_libs & LIB_LETTERS_ASCII){
        if (this->libLettersAscii == nullptr)
            this->libLettersAscii = new GeeGrow_ILI9341_libLettersAscii();
        else
            Serial.println(F("attachLibs(): LIB_LETTERS_ASCII already set"));
    }

    if (_libs & LIB_NUMBERS_ASCII){
        if (this->libNumbersAscii == nullptr)
            this->libNumbersAscii = new GeeGrow_ILI9341_libNumbersAscii();
        else
            Serial.println(F("attachLibs(): LIB_NUMBERS_ASCII already set"));
    }

    if (_libs & LIB_SYMBOLS_ASCII){
        if (this->libSymbolsAscii == nullptr)
            this->libSymbolsAscii = new GeeGrow_ILI9341_libSymbolsAscii();
        else
            Serial.println(F("attachLibs(): LIB_SYMBOLS_ASCII already set"));
    }

    if (_libs & LIB_LETTERS_CYRILLIC){
        if (this->libLettersCyrillic == nullptr){
            this->libLettersCyrillic = new GeeGrow_ILI9341_libLettersCyrillic();
            this->encoding = ENCODING_UTF8;
        } else
            Serial.println(F("attachLibs(): LIB_LETTERS_CYRILLIC already set"));
    }

    if (_libs & LIB_DEVICE_SD){
        if (this->deviceSD == nullptr){
            this->deviceSD = new GeeGrow_ILI9341_deviceSD();
        } else
            Serial.println(F("attachLibs(): LIB_DEVICE_SD already set"));
    }
}

/**************************************************************************/
/*!
    @brief    Set rotation mode
    @param    _encoding    Value of encoding
*/
/**************************************************************************/
void GeeGrow_ILI9341::setEncoding(uint8_t _encoding){
    if (this->libLettersCyrillic == nullptr) {
        Serial.println(F("setEncoding(): LIB_LETTERS_CYRILLIC not set"));
        return;
    }
    this->encoding = _encoding;
}

/**************************************************************************/
/*!
    @brief    Get current rotation mode
    @return   Value of rotation mode
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::getEncoding(){
    if (this->libLettersCyrillic == nullptr) {
        Serial.println(F("getEncoding(): LIB_LETTERS_CYRILLIC not set"));
        return -1;
    }
    return this->encoding;
}

/**************************************************************************/
/*!
    @brief    Convert coordinates of selected range from current rotation
              to X coordinate of raw hardware rotation
    @param    _x0    Current X coordinate
    @param    _y0    Current Y coordinate
    @return   Value of hardware X coordinate
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341::castX(int16_t _x0, int16_t _y0){
    int16_t xt;
    switch (this->params.rotation) {
        case ROTATION_UP:
            xt = _y0;
            break;
        case ROTATION_DOWN:
            xt = this->params.height - _y0 - 1;
            break;
        case ROTATION_LEFT:
            xt = this->params.width - _x0 - 1;
            break;
        case ROTATION_RIGHT:
            xt = _x0;
            break;
        default:
            break;
    }
    return xt;
}

/**************************************************************************/
/*!
    @brief    Convert coordinates of selected range from current rotation
              to Y coordinate of raw hardware rotation
    @param    _x0    Current X coordinate
    @param    _y0    Current Y coordinate
    @return   Value of hardware Y coordinate
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341::castY(int16_t _x0, int16_t _y0){
    int16_t yt;
    switch (this->params.rotation) {
        case ROTATION_UP:
            yt = this->params.width - _x0 - 1;
            break;
        case ROTATION_DOWN:
            yt = _x0;
            break;
        case ROTATION_LEFT:
            yt = this->params.height - _y0 - 1;
            break;
        case ROTATION_RIGHT:
            yt = _y0;
            break;
        default:
            break;
    }
    return yt;
}

/**************************************************************************/
/*!
    @brief    Convert coordinates of selected range from current rotation to
              coordinates of raw hardware rotation. And select relevant range.
    @param    _x0    X coordinate of start point
    @param    _y0    Y coordinate of start point
    @param    _x1    X coordinate of end point
    @param    _y1    Y coordinate of end point
*/
/**************************************************************************/
void GeeGrow_ILI9341::castSelectedRange(int16_t _x0, int16_t _y0, int16_t _x1, int16_t _y1){
    int16_t xt0 = this->castX(_x0, _y0);
    int16_t yt0 = this->castY(_x0, _y0);
    int16_t xt1 = this->castX(_x1, _y1);
    int16_t yt1 = this->castY(_x1, _y1);

    if (xt1 >= xt0)
        this->setColumn(xt0, xt1);
    else
        this->setColumn(xt1, xt0);

    if (yt1 >= yt0)
        this->setPage(yt0, yt1);
    else
        this->setPage(yt1, yt0);
}

/**************************************************************************/
/*!
    @brief    Draw vertical line
    @param    _x0       X coordinate of top point of line
    @param    _y0       Y coordinate of top point of line
    @param    _height   Height of line
    @param    _color    Color of line to draw
*/
/**************************************************************************/
void GeeGrow_ILI9341::drawFastVLine(int16_t _x0, int16_t _y0, int16_t _height, uint16_t _color){
    int16_t h = this->params.height;
    // check coordinates
    if ( (_x0 < 0) || (_y0 < 0) || ( (_y0 + _height) > h ) ) {
        Serial.println(F("drawFastVLine(): invalid coordinates"));
        return;
    }

    this->castSelectedRange(_x0, _y0, _x0, _y0 + _height - 1);
    this->writeMemory(_height, _color);
}

/**************************************************************************/
/*!
    @brief    Draw horizontal line
    @param    _x0       X coordinate of left point of line
    @param    _y0       Y coordinate of left point of line
    @param    _width    Width of line
    @param    _color    Color of line to draw
*/
/**************************************************************************/
void GeeGrow_ILI9341::drawFastHLine(int16_t _x0, int16_t _y0, int16_t _width, uint16_t _color){
    int16_t w = this->params.width;
    // check coordinates
    if ( (_x0 < 0) || (_y0 < 0) || ( (_x0 + _width) > w ) ) {
        Serial.println(F("drawFastHLine(): invalid coordinates"));
        return;
    }

    this->castSelectedRange(_x0, _y0, _x0 + _width - 1, _y0);
    writeMemory(_width, _color);
}

/**************************************************************************/
/*!
    @brief    Draw rectangle
    @param    _x0       X coordinate of top left corner
    @param    _y0       Y coordinate of top left corner
    @param    _width    Width of rectangle
    @param    _height   Height of rectangle
    @param    _color    Color of rectangle to draw
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::drawRect(
    int16_t _x0,
    int16_t _y0,
    int16_t _width,
    int16_t _height,
    uint16_t _color
){
    int16_t w = this->params.width;
    int16_t h = this->params.height;
    // check coordinates
    if  ((_x0 < 0) || (_y0 < 0) ||
        ((_y0 + _height) >= h) || ((_x0 + _width) >= w)
    ){
        Serial.println(F("drawRect(): invalid coordinates"));
        return -1;
    }

    this->drawFastHLine(_x0, _y0, _width, _color);
    this->drawFastHLine(_x0, _y0 + _height, _width, _color);
    this->drawFastVLine(_x0, _y0, _height, _color);
    this->drawFastVLine(_x0 + _width, _y0, _height, _color);
    return 0;
}

/**************************************************************************/
/*!
    @brief    Draw filled rectangle
    @param    _x0       X coordinate of top left corner
    @param    _y0       Y coordinate of top left corner
    @param    _width    Width of rectangle
    @param    _height   Height of rectangle
    @param    _color    Color of rectangle to fill
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::fillRect(
    int16_t _x0,
    int16_t _y0,
    int16_t _width,
    int16_t _height,
    uint16_t _color
){
    int16_t w = this->params.width;
    int16_t h = this->params.height;
    // check coordinates
    if  ((_x0 < 0) || (_y0 < 0) ||
        ((_y0 + _height) > h) || ((_x0 + _width) > w)
    ){
        Serial.println(F("fillRect(): invalid coordinates"));
        return -1;
    }

    this->castSelectedRange(_x0, _y0, _x0 + _width - 1, _y0 + _height - 1);
    this->writeMemory((uint32_t)_height*_width, _color);
    return 0;
}

/**************************************************************************/
/*!
    @brief    Draw circle
    @param    _x0       X coordinate of center
    @param    _y0       Y coordinate of center
    @param    _radius   Radius of circle
    @param    _color    Color of circle to draw
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::drawCircle(int16_t _x0, int16_t _y0, int16_t _radius, uint16_t _color){
    int16_t w = this->params.width;
    int16_t h = this->params.height;
    // Check coordinates
    if ((_x0 < 0) || (_y0 < 0) || (_x0 - _radius < 0) || (_y0 - _radius < 0) ||
        (_x0 + _radius >= w) || (_y0 + _radius >= h)
    ){

        Serial.println(F("drawCircle(): invalid coordinates"));
        return -1;
    }

    int16_t x = -_radius;
    int16_t y = 0;
    int16_t err = 2 - 2*_radius;
    int16_t e2;
    while (x <= 0) {
        this->drawPixel(_x0 - x, _y0 + y, _color);
        this->drawPixel(_x0 + x, _y0 + y, _color);
        this->drawPixel(_x0 + x, _y0 - y, _color);
        this->drawPixel(_x0 - x, _y0 - y, _color);
        e2 = err;
        if (e2 <= y) {
            err += ++y * 2 + 1;
            if (-x == y && e2 <= x)
                e2 = 0;
        }
        if (e2 > x)
            err += ++x * 2 + 1;
    }
    return 0;
}

/**************************************************************************/
/*!
    @brief    Draw filled circle
    @param    _x0       X coordinate of center
    @param    _y0       Y coordinate of center
    @param    _radius   Radius of circle
    @param    _color    Color of circle to fill
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::fillCircle(int16_t _x0, int16_t _y0, int16_t _radius, uint16_t _color){
    int16_t w = this->params.width;
    int16_t h = this->params.height;
    // Check coordinates
    if ((_x0 < 0) || (_y0 < 0) || (_x0 - _radius < 0) || (_y0 - _radius < 0) ||
        (_x0 + _radius >= w) || (_y0 + _radius >= h)
    ){

        Serial.println(F("fillCircle(): invalid coordinates"));
        return -1;
    }

    int16_t x = -_radius;
    int16_t y = 0;
    int16_t err = 2 - 2*_radius;
    int16_t e2;
    do {
        this->drawFastVLine(_x0 - x, _y0 - y, 2*y, _color);
        this->drawFastVLine(_x0 + x, _y0 - y, 2*y, _color);
        e2 = err;
        if (e2 <= y) {
            err += ++y * 2 + 1;
            if (-x == y && e2 <= x)
                e2 = 0;
        }
        if (e2 > x)
            err += ++x * 2 + 1;
    } while (x <= 0);
    return 0;
}

/**************************************************************************/
/*!
    @brief    Draw line
    @param    _x0       X coordinate of start point
    @param    _y0       Y coordinate of start point
    @param    _x1       X coordinate of end point
    @param    _y1       Y coordinate of end point
    @param    _color    Color of line to draw
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::drawLine(int16_t _x0, int16_t _y0, int16_t _x1, int16_t _y1, uint16_t _color){
    int16_t w = this->params.width;
    int16_t h = this->params.height;
    // Check coordinates
    if ((_x0 < 0) || (_y0 < 0) || (_x1 < 0) || (_y1 < 0) ||
        (_x0 >= w) || (_x1 >= w) ||
        (_y0 >= h) || (_y1 >= h)
    ){

        Serial.println(F("drawLine(): invalid coordinates"));
        return -1;
    }

    if (_x0 == _x1) {
        this->drawFastVLine(_x0, _y0, _y1 - _y0, _color);
        return 0;
    }

    if (_y0 == _y1) {
        this->drawFastHLine(_x0, _y0, _x1 - _x0, _color);
        return 0;
    }

    int16_t x = _x1 - _x0;
    int16_t y = _y1 - _y0;
    int16_t dx = abs(x);
    int16_t sx = (_x0 < _x1) ? 1 : -1;
    int16_t dy = -abs(y);
    int16_t sy = (_y0 < _y1) ? 1 : -1;
    int16_t err = dx + dy, e2;
    for (;;) {
        this->drawPixel(_x0, _y0, _color);
        e2 = 2*err;
        if (e2 >= dy) {
            if (_x0 == _x1)
                break;
            err += dy;
            _x0 += sx;
        }
        if (e2 <= dx){
            if (_y0 == _y1)
                break;
            err += dx;
            _y0 += sy;
        }
    }
    return 0;
}

/**************************************************************************/
/*!
    @brief    Draw triangle
    @param    _x0       X coordinate of first point
    @param    _y0       Y coordinate of first point
    @param    _x1       X coordinate of second point
    @param    _y1       Y coordinate of second point
    @param    _x2       X coordinate of third point
    @param    _y2       Y coordinate of third point
    @param    _color    Color of triangle to draw
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::drawTriangle(
    int16_t _x0,
    int16_t _y0,
    int16_t _x1,
    int16_t _y1,
    int16_t _x2,
    int16_t _y2,
    uint16_t _color
){
    int16_t w = this->params.width;
    int16_t h = this->params.height;
    // Check coordinates
    if ((_x0 < 0) || (_y0 < 0) || (_x1 < 0) || (_y1 < 0) || (_x2 < 0) || (_y2 < 0) ||
        (_x0 >= w) || (_x1 >= w) || (_x2 >= w) ||
        (_y0 >= h) || (_y1 >= h) || (_y2 >= h)
    ){

        Serial.println(F("drawTriangle(): invalid coordinates"));
        return -1;
    }

    this->drawLine(_x0, _y0, _x1, _y1, _color);
    this->drawLine(_x0, _y0, _x2, _y2, _color);
    this->drawLine(_x1, _y1, _x2, _y2, _color);
    return 0;
}

/**************************************************************************/
/*!
    @brief    Print symbol from addon library
    @param    _char     Symbol to print
    @param    _x0       X coordinate of top left corner of the symbol
    @param    _y0       Y coordinate of top left corner of the symbol
    @param    _size     Size of font
    @param    _color    Color of symbol to print
    @note     Size of font 1 is equivalent to bitmap 8x16
*/
/**************************************************************************/
void GeeGrow_ILI9341::printChar(char _char, int16_t _x0, int16_t _y0, uint8_t _size, uint16_t _color){
    int16_t w = this->params.width;
    int16_t h = this->params.height;
    // Check coordinates
    if ((_x0 < 0) || (_y0 < 0) ||
        (_x0 + _size * FONT_WIDTH >= w) || (_y0 + _size * FONT_HEIGHT >= h)
    ){

        Serial.println(F("drawChar(): invalid coordinates"));
        return;
    }

    // Check symbol (what library to use)
    uint8_t t = (uint8_t)_char;
    uint16_t *tmp_buf;

    // NUMBERS_ASCII
    if ((t >= 48) && (t <= 57)) {
        if (this->libNumbersAscii == nullptr){
            Serial.println(F("drawChar(): LIB_NUMBERS_ASCII not set"));
            return;
        }
        tmp_buf = this->libNumbersAscii->getBitMap(_char);
    }

    // LETTERS_ASCII
    else if (((t >= 65) && (t <= 90))
        ||     ((t >= 97) && (t <= 122))
    ){

        if (this->libLettersAscii == nullptr){
            Serial.println(F("drawChar(): LIB_LETTERS_ASCII not set"));
            return;
        }
        tmp_buf = this->libLettersAscii->getBitMap(_char);
    }

    // SYMBOLS_ASCII
    else if (((t >= 32) && (t <= 47))
        ||  ((t >= 58) && (t <= 64))
        ||  ((t >= 91) && (t <= 96))
        ||  ((t >= 123) && (t <= 126))
    ){

        if (this->libSymbolsAscii == nullptr){
            Serial.println(F("drawChar(): LIB_SYMBOLS_ASCII not set"));
            return;
        }
        tmp_buf = this->libSymbolsAscii->getBitMap(_char);
    }

    // LETTERS_CYRILLIC
    else if ( (t >= 128) && (t <= 255) ) {
        if (this->libLettersCyrillic == nullptr) {
            Serial.println(F("drawChar(): LIB_LETTERS_CYRILLIC not set"));
            return;
        } else {
            if ( ((t <= 191) && (this->encoding == ENCODING_UTF8))
              || ((t >= 192) && (this->encoding == ENCODING_CP1251))
            )
                tmp_buf = this->libLettersCyrillic->getBitMap(_char, encoding);
            else {
                Serial.println(F("drawChar(): encoding error"));
                return;
            }
        }
    }

    // unknown
    else {
        Serial.println(F("drawChar(): unknown symbol"));
        return;
    }

    for (uint8_t i = 0; i < FONT_WIDTH; i++) {
        uint16_t tmp_char = pgm_read_word_near(tmp_buf + i);
        for (uint8_t j = 0; j < FONT_HEIGHT; j++)
            if (tmp_char & (1 << j))
                this->fillRect(_x0 + i*_size, _y0 + j*_size, _size, _size, _color);
    }
}

/**************************************************************************/
/*!
    @brief    Print string
    @param    _string   String to print
    @param    _x0       X coordinate of top left corner of the string
    @param    _y0       Y coordinate of top left corner of the string
    @param    _size     Size of font
    @param    _color    Color of symbols to print
    @note     Size of font 1 is equivalent to bitmap 8x16
*/
/**************************************************************************/
void GeeGrow_ILI9341::printStr(String _str, int16_t _x0, int16_t _y0, uint8_t _size, uint16_t _color){
    uint16_t n = _str.length();
    uint8_t missed_bytes = 0;
    // Divide string to separate symbols
    for (uint16_t i = 0; i < n; i++) {
        uint8_t t = (uint8_t)*(_str.c_str() + i);
        if (t == 208 || t == 209) {        // Extra bytes from utf-8, don't need them
            missed_bytes++;
            continue;
        }
        this->printChar((char)t, _x0 + (i - missed_bytes)*_size*FONT_WIDTH, _y0, _size, _color);
    }
}

/**************************************************************************/
/*!
    @brief    Send command via SPI
    @param    _cmd    Command byte
*/
/**************************************************************************/
void GeeGrow_ILI9341::sendSpiCmd(uint8_t _cmd){
    digitalWrite(this->pins.dc, LOW);
    digitalWrite(this->pins.cs, LOW);
    SPI.transfer(_cmd);
    SWAP_WR(this->pins.wr);
    digitalWrite(this->pins.cs, HIGH);
}

/**************************************************************************/
/*!
    @brief    Send 1 data byte via SPI
    @param    _data    Data byte
*/
/**************************************************************************/
void GeeGrow_ILI9341::sendSpiData(uint8_t _data){
    digitalWrite(this->pins.dc, HIGH);
    digitalWrite(this->pins.cs, LOW);
    SPI.transfer(_data);
    SWAP_WR(this->pins.wr);
    digitalWrite(this->pins.cs, HIGH);
}

/**************************************************************************/
/*!
    @brief    Send 2 data bytes via SPI
    @param    _data    Data bytes
*/
/**************************************************************************/
void GeeGrow_ILI9341::sendSpiData16(uint16_t _data){
    digitalWrite(this->pins.dc, HIGH);
    digitalWrite(this->pins.cs, LOW);
    SPI.transfer(_data >> 8);
    SPI.transfer(_data & 0xFF);
    SWAP_WR(this->pins.wr);
    digitalWrite(this->pins.cs, HIGH);
}

/**************************************************************************/
/*!
    @brief    Write array of certain color to display's RAM
    @param    _num      Number of pixels to fill with certain color
    @param    _color    Color to fill pixels
*/
/**************************************************************************/
void GeeGrow_ILI9341::writeMemory(uint32_t _num, uint16_t _color){
    digitalWrite(this->pins.cs, LOW);    // CS

    digitalWrite(this->pins.dc, LOW);    // DC CMD
    SPI.transfer(CMD_MEMORY_WRITE);
    SWAP_WR(this->pins.wr);

    digitalWrite(this->pins.dc, HIGH);    // DC DATA

    for (uint32_t i = 0; i < _num; i++) {
        SPI.transfer(_color >> 8);
        SPI.transfer(_color & 0xFF);
        SWAP_WR(this->pins.wr);
    }

    digitalWrite(this->pins.dc, LOW);    // DC CMD
    SPI.transfer(CMD_NOP);
    SWAP_WR(this->pins.wr);

    digitalWrite(this->pins.cs, HIGH);    // CS
}

/**************************************************************************/
/*!
    @brief    Write array of user's bytes to display's RAM
    @param    _num    Number of pixels to fill
    @param    _buf    Pointer to array of data to send
*/
/**************************************************************************/
void GeeGrow_ILI9341::writeMemoryBuf(uint32_t _num, uint16_t *_buf){
    digitalWrite(this->pins.cs, LOW);    // CS

    digitalWrite(this->pins.dc, LOW);    // DC CMD
    SPI.transfer(CMD_MEMORY_WRITE);
    SWAP_WR(this->pins.wr);

    digitalWrite(this->pins.dc, HIGH);    // DC DATA
    for (uint32_t i = 0; i < _num; i++) {
        SPI.transfer(*(_buf + i) >> 8);
        SPI.transfer(*(_buf + i) & 0xFF);
        SWAP_WR(this->pins.wr);
    }

    digitalWrite(this->pins.dc, LOW);    // DC CMD
    SPI.transfer(CMD_NOP);
    SWAP_WR(this->pins.wr);

    digitalWrite(this->pins.cs, HIGH);    // CS
}

/**************************************************************************/
/*!
    @brief    Create an object of pixel
    @return   Pointer to created object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectBase* GeeGrow_ILI9341::createPixelObj(){
    uint8_t type = OBJ_PIXEL;
    GeeGrow_ILI9341_objectBase *_obj = new GeeGrow_ILI9341_objectPixel(type, this);
    return _obj;
}

/**************************************************************************/
/*!
    @brief    Create an object of line
    @return   Pointer to created object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectBase* GeeGrow_ILI9341::createLineObj(){
    uint8_t type = OBJ_LINE;
    GeeGrow_ILI9341_objectBase *_obj = new GeeGrow_ILI9341_objectLine(type, this);
    return _obj;
}

/**************************************************************************/
/*!
    @brief    Create an object of rectangle
    @return   Pointer to created object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectBase* GeeGrow_ILI9341::createRectObj(){
    uint8_t type = OBJ_RECT;
    GeeGrow_ILI9341_objectBase *_obj = new GeeGrow_ILI9341_objectRect(type, this);
    return _obj;
}

/**************************************************************************/
/*!
    @brief    Create an object of filled rectangle
    @return   Pointer to created object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectBase* GeeGrow_ILI9341::createFillRectObj(){
    uint8_t type = OBJ_FILL_RECT;
    GeeGrow_ILI9341_objectBase *_obj = new GeeGrow_ILI9341_objectFillRect(type, this);
    return _obj;
}

/**************************************************************************/
/*!
    @brief    Create an object of circle
    @return   Pointer to created object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectBase* GeeGrow_ILI9341::createCircleObj(){
    uint8_t type = OBJ_CIRCLE;
    GeeGrow_ILI9341_objectBase *_obj = new GeeGrow_ILI9341_objectCircle(type, this);
    return _obj;
}

/**************************************************************************/
/*!
    @brief    Create an object of filled circle
    @return   Pointer to created object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectBase* GeeGrow_ILI9341::createFillCircleObj(){
    uint8_t type = OBJ_FILL_CIRCLE;
    GeeGrow_ILI9341_objectBase *_obj = new GeeGrow_ILI9341_objectFillCircle(type, this);
    return _obj;
}

/**************************************************************************/
/*!
    @brief    Create an object of triangle
    @return   Pointer to created object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectBase* GeeGrow_ILI9341::createTriangleObj(){
    uint8_t type = OBJ_TRIANGLE;
    GeeGrow_ILI9341_objectBase *_obj = new GeeGrow_ILI9341_objectTriangle(type, this);
    return _obj;
}

/**************************************************************************/
/*!
    @brief    Initialize SD card
    @param    _cs_sd    Pin of SD card Chip Select
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::initSD(uint8_t _cs_sd){
    if (this->deviceSD == nullptr) {
        Serial.println(F("initSD(): LIB_DEVICE_SD not set"));
        return -1;
    }
    if (this->deviceSD->init(_cs_sd))
        return -1;
    return 0;
}

/**************************************************************************/
/*!
    @brief    Show a .bmp image from SD card on the screen
    @param    _x0       X coordinate of top left corner of the image
    @param    _y0       Y coordinate of top left corner of the image
    @param    _filename Full path to image on SD card
    @return   Status byte
    @note     Image MUST be .bmp with color depth 16 bit (R5, G6, B5)!
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341::showBMPfromSD(int16_t _x0, int16_t _y0, char *_filename){
    if (this->deviceSD == nullptr) {
        Serial.println(F("showBMPfromSD(): LIB_DEVICE_SD not set"));
        return -1;
    }

    this->deviceSD->setFileName(_filename);
    if (this->deviceSD->getReady())
        return -1;

    if (_x0 + this->deviceSD->BITMAPINFOHEADER.biWidth > this->params.width
        || _y0 + this->deviceSD->BITMAPINFOHEADER.biHeight > this->params.height
    ){
        Serial.println(F("showBMPfromSD(): invalid coordinates"));
        return -1;
    }
    if (this->deviceSD->BITMAPFILEHEADER.bfType != 0x4D42){
        Serial.println(F("showBMPfromSD(): image type not valid"));
        return -1;
    }
    if (this->deviceSD->BITMAPINFOHEADER.biBitCount != 16){
        Serial.println(F("showBMPfromSD(): color depth not valid"));
        return -1;
    }

    uint16_t blocks_num = this->deviceSD->BITMAPINFOHEADER.biHeight;
    uint16_t block_size_pixels = this->deviceSD->BITMAPINFOHEADER.biWidth;
    uint32_t pos = this->deviceSD->BITMAPFILEHEADER.bfOffBits;

    this->OnSettingsForBMP();
    for (uint16_t i = 0; i < blocks_num; i++){
        this->castSelectedRangeForBMP(
            _x0,
            _y0,
            block_size_pixels,
            blocks_num,
            i
        );
        this->writeMemoryBuf(
            block_size_pixels,
            this->deviceSD->getBlock(pos, block_size_pixels*2)
        );
        pos += block_size_pixels*2;
    }
    this->OffSettingsForBMP();
    return 0;
}

/**************************************************************************/
/*!
    @brief    Configure display properly for correct image mapping. Needed
              only while image is being copied to display's RAM
*/
/**************************************************************************/
void GeeGrow_ILI9341::OnSettingsForBMP(){
    switch (this->params.rotation){
        case ROTATION_UP:
            this->sendSpiCmd(CMD_MEMORY_ACCESS_CONTROL);
            this->sendSpiData((1 << 7) | (1 << 6) | (1 << 3));
            break;
        case ROTATION_DOWN:
            this->sendSpiCmd(CMD_MEMORY_ACCESS_CONTROL);
            this->sendSpiData((0 << 7) | (1 << 6) | (1 << 3));
            break;
        case ROTATION_LEFT:
            this->sendSpiCmd(CMD_MEMORY_ACCESS_CONTROL);
            this->sendSpiData((0 << 7) | (0 << 6) | (1 << 3));
            break;
        case ROTATION_RIGHT:
            this->sendSpiCmd(CMD_MEMORY_ACCESS_CONTROL);
            this->sendSpiData((0 << 7) | (1 << 6) | (1 << 3));
            break;
        default:
            break;
    }
}

/**************************************************************************/
/*!
    @brief    Return display configuration to default values after coping the
              image from SD card
*/
/**************************************************************************/
void GeeGrow_ILI9341::OffSettingsForBMP(){
    this->sendSpiCmd(CMD_MEMORY_ACCESS_CONTROL);
    this->sendSpiData(0x48);
}

/**************************************************************************/
/*!
    @brief    Convert coordinates of selected range (where the image will be
              placed) for correct image mapping.
    @param    _x0                   X coordinate of left point of row, which will
                                    be mapped during this iteration
    @param    _y0                   Y coordinate of left point of row, which will
                                    be mapped during this iteration
    @param    _block_size_pixels    Number of pixels in block (row)
    @param    _blocks_num           Number of blocks (rows) in image
    @param    _i                    Number of current block (row)
*/
/**************************************************************************/
void GeeGrow_ILI9341::castSelectedRangeForBMP(
    int16_t _x0,
    int16_t _y0,
    uint16_t _block_size_pixels,
    uint16_t _blocks_num,
    uint16_t _i
){
    switch (this->params.rotation){
        case ROTATION_UP:
            this->castSelectedRange(
                this->params.width - _x0 - _block_size_pixels,
                _y0 + _blocks_num - _i - 1,
                this->params.width - _x0 - 1,
                _y0 + _blocks_num - _i - 1
            );
            break;
        case ROTATION_DOWN:
            this->castSelectedRange(
                _x0,
                _y0 + _blocks_num - _i - 1,
                _x0 + _block_size_pixels - 1,
                _y0 + _blocks_num - _i - 1
            );
            break;
        case ROTATION_LEFT:
            this->castSelectedRange(
                this->params.width - _x0 - _block_size_pixels,
                _y0 + _blocks_num - _i - 1,
                this->params.width - _x0 - 1,
                _y0 + _blocks_num - _i - 1
            );
            break;
        case ROTATION_RIGHT:
            this->castSelectedRange(
                _x0,
                _y0 + _blocks_num - _i - 1,
                _x0 + _block_size_pixels - 1,
                _y0 + _blocks_num - _i - 1
            );
            break;
        default:
            break;
    }
}
