/*!
 * @file Geegrow_ILI9341_objectCircle.cpp
 *
 * This is an addon library for the Geegrow ILI9341 TFT 240x320 display,
 * which implements opportunity to create object circle
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "Geegrow_ILI9341_objectCircle.h"

/**************************************************************************/
/*!
    @brief    Instantiate a circle object
    @param    _objectType    Type of object to create
    @param    _partner       Pointer to class, which is a parent of main class and
                             allows to use drawing functions of main class
*/
/**************************************************************************/
Geegrow_ILI9341_objectCircle::Geegrow_ILI9341_objectCircle(
    uint8_t _objectType,
    Geegrow_ILI9341_partnership* _partner
) : Geegrow_ILI9341_objectBase(_objectType, _partner){

}

/**************************************************************************/
/*!
    @brief    Destruct the object
*/
/**************************************************************************/
Geegrow_ILI9341_objectCircle::~Geegrow_ILI9341_objectCircle(){
    this->disappear();
}

/**************************************************************************/
/*!
    @brief    Shows the object on the screen
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::appear(){
    this->partner->drawCircle(
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
void Geegrow_ILI9341_objectCircle::disappear(){
    this->partner->drawCircle(
        this->x0,
        this->y0,
        this->radius,
        this->color_bg
    );
}

/**************************************************************************/
/*!
    @brief    Set the circle object to certain place with certain properties
    @param    _x0       X coordinate of center
    @param    _y0       Y coordinate of center
    @param    _radius   Radius of circle object
    @param    _color    Color of circle object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::moveTo(
    int16_t _x0,
    int16_t _y0,
    int16_t _radius,
    uint16_t _color
){
    this->disappear();
    if (this->partner->drawCircle(_x0, _y0, _radius, _color)){
        // Error
        Serial.println("Error");
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
    @param    _delta     Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::moveRight(int16_t _delta){
    this->disappear();
    if (this->partner->drawCircle(
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
    @param    _delta     Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::moveLeft(int16_t _delta){
    this->disappear();
    if (this->partner->drawCircle(
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
    @param    _delta     Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::moveUp(int16_t _delta){
    this->disappear();
    if (this->partner->drawCircle(
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
    @param    _delta     Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::moveDown(int16_t _delta){
    this->disappear();
    if (this->partner->drawCircle(
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
    @param    _delta_x     Numbers of pixels to move the object to the right
    @param    _delta_y     Numbers of pixels to move the object up
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::moveRightUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawCircle(
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
    @param    _delta_x     Numbers of pixels to move the object to the right
    @param    _delta_y     Numbers of pixels to move the object down
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::moveRightDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawCircle(
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
    @param    _delta_x     Numbers of pixels to move the object to the left
    @param    _delta_y     Numbers of pixels to move the object up
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::moveLeftUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawCircle(
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
    @param    _delta_x     Numbers of pixels to move the object to the left
    @param    _delta_y     Numbers of pixels to move the object down
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::moveLeftDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawCircle(
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
int16_t Geegrow_ILI9341_objectCircle::getRadius(){
    return this->radius;
}

/**************************************************************************/
/*!
    @brief    Set radius of circle object
    @param    _radius   Radius of circle object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectCircle::setRadius(int16_t _radius){
    this->disappear();
    if (this->partner->drawCircle(
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
