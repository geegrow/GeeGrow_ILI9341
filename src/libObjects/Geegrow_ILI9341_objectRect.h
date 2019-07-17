/*!
 * @file Geegrow_ILI9341_objectRect.h
 *
 * This is an addon library for the Geegrow ILI9341 TFT 240x320 display,
 * which implements opportunity to create object rectangle
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef GEEGROW_ILI9341_OBJECT_RECT_H
#define GEEGROW_ILI9341_OBJECT_RECT_H

#include "Geegrow_ILI9341_objectBase.h"

/**************************************************************************/
/*!
    @brief    Parent class that stores state and functions of object rectangle
*/
/**************************************************************************/
class Geegrow_ILI9341_objectRect : public Geegrow_ILI9341_objectBase {
    public:
        Geegrow_ILI9341_objectRect(
            uint8_t _objectType,
            Geegrow_ILI9341_partnership* _partner
        );
        ~Geegrow_ILI9341_objectRect();
        void appear();
        void disappear();
        void moveTo(
            int16_t _x0,
            int16_t _y0,
            int16_t _width,
            int16_t _height,
            uint16_t _color
        );
        void moveRight(int16_t _delta);
        void moveLeft(int16_t _delta);
        void moveUp(int16_t _delta);
        void moveDown(int16_t _delta);
        void moveRightUp(int16_t _delta_x, int16_t _delta_y);
        void moveRightDown(int16_t _delta_x, int16_t _delta_y);
        void moveLeftUp(int16_t _delta_x, int16_t _delta_y);
        void moveLeftDown(int16_t _delta_x, int16_t _delta_y);
        int16_t getWidth();
        int16_t getHeight();
        void setWidth(int16_t _width);
        void setHeight(int16_t _height);

    protected:
        int16_t width = 0;
        int16_t height = 0;
};

#endif /* GEEGROW_ILI9341_OBJECT_RECT_H */
