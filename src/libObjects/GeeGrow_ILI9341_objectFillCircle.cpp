/*!
 * @file GeeGrow_ILI9341_objectFillCircle.cpp
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

#include "GeeGrow_ILI9341_objectFillCircle.h"

/**************************************************************************/
/*!
    @brief    Instantiate a filled circle object
    @param    _objectType    Type of object to create
    @param    _partner       Pointer to class, which is a parent of main class and
                             allows to use drawing functions of main class
*/
/**************************************************************************/
GeeGrow_ILI9341_objectFillCircle::GeeGrow_ILI9341_objectFillCircle(
    uint8_t _objectType,
    GeeGrow_ILI9341_partnership* _partner
) : GeeGrow_ILI9341_objectBase(_objectType, _partner){

}

/**************************************************************************/
/*!
    @brief    Destruct the object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectFillCircle::~GeeGrow_ILI9341_objectFillCircle(){
    this->disappear();
}

/**************************************************************************/
/*!
    @brief    Shows the object on the screen
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::appear(){
    this->partner->fillCircle(
        this->x0,
        this->y0,
        this->radius,
        this->color
    );
}

/**************************************************************************/
/*!
    @brief    Hides the object on the screen
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::disappear(){
    this->partner->fillCircle(
        this->x0,
        this->y0,
        this->radius,
        this->color_bg
    );
}

/**************************************************************************/
/*!
    @brief    Set the object to certain place with certain properties
    @param    _x0       X coordinate of center
    @param    _y0       Y coordinate of center
    @param    _radius   Radius of circle object
    @param    _color    Color of the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::moveTo(
    int16_t _x0,
    int16_t _y0,
    int16_t _radius,
    uint16_t _color
){
    this->disappear();
    if (this->partner->fillCircle(_x0, _y0, _radius, _color)){
        // Error
        this->appear();
        return;
    }
    this->x0 = _x0;
    this->y0 = _y0;
    this->radius = _radius;
    this->color = _color;
}

/**************************************************************************/
/*!
    @brief    Move the object to the right on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::moveRight(int16_t _delta){
    this->disappear();
    if (this->partner->fillCircle(
            this->x0 + _delta,
            this->y0,
            this->radius,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 += _delta;
}

/**************************************************************************/
/*!
    @brief    Move the object to the left on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::moveLeft(int16_t _delta){
    this->disappear();
    if (this->partner->fillCircle(
            this->x0 - _delta,
            this->y0,
            this->radius,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 -= _delta;
}

/**************************************************************************/
/*!
    @brief    Move the object up on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::moveUp(int16_t _delta){
    this->disappear();
    if (this->partner->fillCircle(
            this->x0,
            this->y0 - _delta,
            this->radius,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->y0 -= _delta;
}

/**************************************************************************/
/*!
    @brief    Move the object down on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::moveDown(int16_t _delta){
    this->disappear();
    if (this->partner->fillCircle(
            this->x0,
            this->y0 + _delta,
            this->radius,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->y0 += _delta;
}

/**************************************************************************/
/*!
    @brief    Move the object up and to the right on certain number of pixels
    @param    _delta_x    Numbers of pixels to move the object to the right
    @param    _delta_y    Numbers of pixels to move the object up
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::moveRightUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->fillCircle(
            this->x0 + _delta_x,
            this->y0 - _delta_y,
            this->radius,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 += _delta_x;
    this->y0 -= _delta_y;
}

/**************************************************************************/
/*!
    @brief    Move the object down and to the right on certain number of pixels
    @param    _delta_x    Numbers of pixels to move the object to the right
    @param    _delta_y    Numbers of pixels to move the object down
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::moveRightDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->fillCircle(
            this->x0 + _delta_x,
            this->y0 + _delta_y,
            this->radius,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 += _delta_x;
    this->y0 += _delta_y;
}

/**************************************************************************/
/*!
    @brief    Move the object up and to the left on certain number of pixels
    @param    _delta_x    Numbers of pixels to move the object to the left
    @param    _delta_y    Numbers of pixels to move the object up
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::moveLeftUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->fillCircle(
            this->x0 - _delta_x,
            this->y0 - _delta_y,
            this->radius,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 -= _delta_x;
    this->y0 -= _delta_y;
}

/**************************************************************************/
/*!
    @brief    Move the object down and to the left on certain number of pixels
    @param    _delta_x    Numbers of pixels to move the object to the left
    @param    _delta_y    Numbers of pixels to move the object down
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::moveLeftDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->fillCircle(
            this->x0 - _delta_x,
            this->y0 + _delta_y,
            this->radius,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 -= _delta_x;
    this->y0 += _delta_y;
}

/**************************************************************************/
/*!
    @brief    Get current radius of circle object
    @return   Radius of circle object
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341_objectFillCircle::getRadius(){
    return this->radius;
}

/**************************************************************************/
/*!
    @brief    Set radius of circle object
    @param    _radius    Radius of circle object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillCircle::setRadius(int16_t _radius){
    this->disappear();
    if (this->partner->fillCircle(
            this->x0,
            this->y0,
            _radius,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->radius = _radius;
}
