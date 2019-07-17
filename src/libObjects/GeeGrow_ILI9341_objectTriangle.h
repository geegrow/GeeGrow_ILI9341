/*!
 * @file Geegrow_ILI9341_objectTriangle.h
 *
 * This is an addon library for the Geegrow ILI9341 TFT 240x320 display,
 * which implements opportunity to create object triangle
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef GEEGROW_ILI9341_OBJECT_TRIANGLE_H
#define GEEGROW_ILI9341_OBJECT_TRIANGLE_H

#include "Geegrow_ILI9341_objectBase.h"

/**************************************************************************/
/*!
    @brief    Parent class that stores state and functions of object triangle
*/
/**************************************************************************/
class Geegrow_ILI9341_objectTriangle : public Geegrow_ILI9341_objectBase {
    public:
        Geegrow_ILI9341_objectTriangle(
            uint8_t _objectType,
            Geegrow_ILI9341_partnership* _partner
        );
        ~Geegrow_ILI9341_objectTriangle();
        void appear();
        void disappear();
        void moveTo(
            int16_t _x0,
            int16_t _y0,
            int16_t _x1,
            int16_t _y1,
            int16_t _x2,
            int16_t _y2,
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
        int16_t getX1();
        int16_t getY1();
        int16_t getX2();
        int16_t getY2();

    protected:
        int16_t x1 = 0;
        int16_t y1 = 0;
        int16_t x2 = 0;
        int16_t y2 = 0;
};

#endif /* GEEGROW_ILI9341_OBJECT_TRIANGLE_H */
