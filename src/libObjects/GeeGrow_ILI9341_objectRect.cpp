/*!
 * @file Geegrow_ILI9341_objectRect.cpp
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

#include "Geegrow_ILI9341_objectRect.h"

/**************************************************************************/
/*!
    @brief    Instantiate a rectangle object
    @param    _objectType    Type of object to create
    @param    _partner       Pointer to class, which is a parent of main class and
                             allows to use drawing functions of main class
*/
/**************************************************************************/
Geegrow_ILI9341_objectRect::Geegrow_ILI9341_objectRect(
    uint8_t _objectType,
    Geegrow_ILI9341_partnership* _partner
) : Geegrow_ILI9341_objectBase(_objectType, _partner){

}

/**************************************************************************/
/*!
    @brief    Destruct the object
*/
/**************************************************************************/
Geegrow_ILI9341_objectRect::~Geegrow_ILI9341_objectRect(){
    this->disappear();
}

/**************************************************************************/
/*!
    @brief    Shows the object on the screen
*/
/**************************************************************************/
void Geegrow_ILI9341_objectRect::appear(){
    this->partner->drawRect(
        this->x0,
        this->y0,
        this->width,
        this->height,
        this->color
    );
}

/**************************************************************************/
/*!
    @brief    Hides the object on the screen
*/
/**************************************************************************/
void Geegrow_ILI9341_objectRect::disappear(){
    this->partner->drawRect(
        this->x0,
        this->y0,
        this->width,
        this->height,
        this->color_bg
    );
}

/**************************************************************************/
/*!
    @brief    Set the object to certain place with certain properties
    @param    _x0     X coordinate of top left corner
    @param    _y0     Y coordinate of top left corner
    @param    _width  Width of rectangle
    @param    _height Height of rectangle
    @param    _color  Color of the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectRect::moveTo(
    int16_t _x0,
    int16_t _y0,
    int16_t _width,
    int16_t _height,
    uint16_t _color
){
    this->disappear();
    if (this->partner->drawRect(_x0, _y0, _width, _height, _color)){
        // Error
        this->appear();
        return;
    }
    this->x0 = _x0;
    this->y0 = _y0;
    this->width = _width;
    this->height = _height;
    this->color = _color;
}

/**************************************************************************/
/*!
    @brief    Move the object to the right on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectRect::moveRight(int16_t _delta){
    this->disappear();
    if (this->partner->drawRect(
            this->x0 + _delta,
            this->y0,
            this->width,
            this->height,
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
void Geegrow_ILI9341_objectRect::moveLeft(int16_t _delta){
    this->disappear();
    if (this->partner->drawRect(
            this->x0 - _delta,
            this->y0,
            this->width,
            this->height,
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
void Geegrow_ILI9341_objectRect::moveUp(int16_t _delta){
    this->disappear();
    if (this->partner->drawRect(
            this->x0,
            this->y0 - _delta,
            this->width,
            this->height,
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
void Geegrow_ILI9341_objectRect::moveDown(int16_t _delta){
    this->disappear();
    if (this->partner->drawRect(
            this->x0,
            this->y0 + _delta,
            this->width,
            this->height,
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
void Geegrow_ILI9341_objectRect::moveRightUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawRect(
            this->x0 + _delta_x,
            this->y0 - _delta_y,
            this->width,
            this->height,
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
void Geegrow_ILI9341_objectRect::moveRightDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawRect(
            this->x0 + _delta_x,
            this->y0 + _delta_y,
            this->width,
            this->height,
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
void Geegrow_ILI9341_objectRect::moveLeftUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawRect(
            this->x0 - _delta_x,
            this->y0 - _delta_y,
            this->width,
            this->height,
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
void Geegrow_ILI9341_objectRect::moveLeftDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawRect(
            this->x0 - _delta_x,
            this->y0 + _delta_y,
            this->width,
            this->height,
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
    @brief    Get current width of rectangle object
    @return   Width of rectangle object
*/
/**************************************************************************/
int16_t Geegrow_ILI9341_objectRect::getWidth(){
    return this->width;
}

/**************************************************************************/
/*!
    @brief    Get current height of rectangle object
    @return   Height of rectangle object
*/
/**************************************************************************/
int16_t Geegrow_ILI9341_objectRect::getHeight(){
    return this->height;
}

/**************************************************************************/
/*!
    @brief    Set width of rectangle object
    @param   _width    Width of rectangle object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectRect::setWidth(int16_t _width){
    this->disappear();
    if (this->partner->drawRect(
            this->x0,
            this->y0,
            _width,
            this->height,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->width = _width;
}

/**************************************************************************/
/*!
    @brief    Set height of rectangle object
    @param   _height    Height of rectangle object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectRect::setHeight(int16_t _height){
    this->disappear();
    if (this->partner->drawRect(
            this->x0,
            this->y0,
            this->width,
            _height,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->height = _height;
}
