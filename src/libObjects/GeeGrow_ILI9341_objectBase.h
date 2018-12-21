/*!
 * @file GeeGrow_ILI9341_objectBase.h
 *
 * This is an addon library for the GeeGrow ILI9341 TFT 240x320 display,
 * which implements opportunity to create objects on screen
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef GEEGROW_ILI9341_OBJECT_BASE_H
#define GEEGROW_ILI9341_OBJECT_BASE_H

#include <Arduino.h>
#include <GeeGrow_ILI9341_defines.h>
#include <GeeGrow_ILI9341_tools.h>

/**************************************************************************/
/*!
    @brief    Parent class that stores state and functions of object
*/
/**************************************************************************/
class GeeGrow_ILI9341_objectBase : public GeeGrow_ILI9341_partnership {
    public:
        GeeGrow_ILI9341_objectBase(
            uint8_t _objectType,
            GeeGrow_ILI9341_partnership* _partner
        );
        ~GeeGrow_ILI9341_objectBase(){}
        int16_t getX0();
        int16_t getY0();
        uint16_t getColor();
        uint16_t getColorBG();
        void setColor(uint16_t _color);
        void setColorBG(uint16_t _color);
        virtual void appear();
        virtual void disappear();

    protected:
        uint8_t objectType = OBJ_PIXEL;
        GeeGrow_ILI9341_partnership* partner = 0;
        int16_t x0 = 0;
        int16_t y0 = 0;
        uint16_t color = WHITE;
        uint16_t color_bg = BLACK;
        /**************************************************************************/
        /*!
            @brief    Functions that allow to use main class's functionality
        */
        /**************************************************************************/
        int8_t drawPixel(
            int16_t _x0,
            int16_t _y0,
            uint16_t _color
        ){}
        int8_t drawLine(
            int16_t _x0,
            int16_t _y0,
            int16_t _x1,
            int16_t _y1,
            uint16_t _color
        ){}
        int8_t drawRect(
            int16_t _x0,
            int16_t _y0,
            int16_t _width,
            int16_t _height,
            uint16_t _color
        ){}
        int8_t fillRect(
            int16_t _x0,
            int16_t _y0,
            int16_t _width,
            int16_t _height,
            uint16_t _color
        ){}
        int8_t drawCircle(
            int16_t _x0,
            int16_t _y0,
            int16_t _radius,
            uint16_t _color
        ){}
        int8_t fillCircle(
            int16_t _x0,
            int16_t _y0,
            int16_t _radius,
            uint16_t _color
        ){}
        int8_t drawTriangle(
            int16_t _x0,
            int16_t _y0,
            int16_t _x1,
            int16_t _y1,
            int16_t _x2,
            int16_t _y2,
            uint16_t _color
        ){}
};

#endif /* GEEGROW_ILI9341_OBJECT_BASE_H */
