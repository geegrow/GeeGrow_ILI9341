/*!
 * @file Geegrow_ILI9341_objectPixel.h
 *
 * This is an addon library for the Geegrow ILI9341 TFT 240x320 display,
 * which implements opportunity to create object pixel
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef GEEGROW_ILI9341_OBJECT_PIXEL_H
#define GEEGROW_ILI9341_OBJECT_PIXEL_H

#include "Geegrow_ILI9341_objectBase.h"

/**************************************************************************/
/*!
    @brief    Parent class that stores state and functions of object pixel
*/
/**************************************************************************/
class Geegrow_ILI9341_objectPixel : public Geegrow_ILI9341_objectBase {
    public:
        Geegrow_ILI9341_objectPixel(
            uint8_t _objectType,
            Geegrow_ILI9341_partnership* _partner
        );
        ~Geegrow_ILI9341_objectPixel();
        void appear();
        void disappear();
        void moveTo(
            int16_t _x0,
            int16_t _y0,
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

    protected:
        int16_t x0 = 0;
        int16_t y0 = 0;
        uint16_t color = WHITE;
        uint16_t color_bg = BLACK;
};

#endif /* GEEGROW_ILI9341_OBJECT_PIXEL_H */
