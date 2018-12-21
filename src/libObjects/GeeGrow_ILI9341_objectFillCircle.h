/*!
 * @file GeeGrow_ILI9341_objectFillCircle.h
 *
 * This is an addon library for the GeeGrow ILI9341 TFT 240x320 display,
 * which implements opportunity to create object filled circle
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef GEEGROW_ILI9341_OBJECT_FILL_CIRCLE_H
#define GEEGROW_ILI9341_OBJECT_FILL_CIRCLE_H

#include "GeeGrow_ILI9341_objectBase.h"

/**************************************************************************/
/*!
    @brief    Parent class that stores state and functions of object filled circle
*/
/**************************************************************************/
class GeeGrow_ILI9341_objectFillCircle : public GeeGrow_ILI9341_objectBase {
    public:
        GeeGrow_ILI9341_objectFillCircle(
            uint8_t _objectType,
            GeeGrow_ILI9341_partnership* _partner
        );
        ~GeeGrow_ILI9341_objectFillCircle();
        void appear();
        void disappear();
        void moveTo(
            int16_t _x0,
            int16_t _y0,
            int16_t _radius,
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
        int16_t getRadius();
        void setRadius(int16_t _radius);

    private:
        int16_t radius = 0;
};

#endif /* GEEGROW_ILI9341_OBJECT_FILL_CIRCLE_H */
