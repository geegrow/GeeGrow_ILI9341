/*!
 * @file Geegrow_ILI9341_objectTriangle.cpp
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

#include "Geegrow_ILI9341_objectTriangle.h"

/**************************************************************************/
/*!
    @brief    Instantiate a triangle object
    @param    _objectType    Type of object to create
    @param    _partner       Pointer to class, which is a parent of main class and
                             allows to use drawing functions of main class
*/
/**************************************************************************/
Geegrow_ILI9341_objectTriangle::Geegrow_ILI9341_objectTriangle(
    uint8_t _objectType,
    Geegrow_ILI9341_partnership* _partner
) : Geegrow_ILI9341_objectBase(_objectType, _partner){

}

/**************************************************************************/
/*!
    @brief    Destruct the object
*/
/**************************************************************************/
Geegrow_ILI9341_objectTriangle::~Geegrow_ILI9341_objectTriangle(){
    this->disappear();
}

/**************************************************************************/
/*!
    @brief    Shows the object on the screen
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::appear(){
    this->partner->drawTriangle(
        this->x0,
        this->y0,
        this->x1,
        this->y1,
        this->x2,
        this->y2,
        this->color
    );
}

/**************************************************************************/
/*!
    @brief    Hides the object on the screen
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::disappear(){
    this->partner->drawTriangle(
        this->x0,
        this->y0,
        this->x1,
        this->y1,
        this->x2,
        this->y2,
        this->color_bg
    );
}

/**************************************************************************/
/*!
    @brief    Set the object to certain place with certain properties
    @param    _x0     X coordinate of first point
    @param    _y0     Y coordinate of first point
    @param    _x1     X coordinate of second point
    @param    _y1     Y coordinate of second point
    @param    _x2     X coordinate of third point
    @param    _y2     Y coordinate of third point
    @param    _color  Color of the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::moveTo(
    int16_t _x0,
    int16_t _y0,
    int16_t _x1,
    int16_t _y1,
    int16_t _x2,
    int16_t _y2,
    uint16_t _color
){
    this->disappear();
    if (this->partner->drawTriangle(_x0, _y0, _x1, _y1, _x2, _y2, _color)){
        // Error
        this->appear();
        return;
    }
    this->x0 = _x0;
    this->y0 = _y0;
    this->x1 = _x1;
    this->y1 = _y1;
    this->x2 = _x2;
    this->y2 = _y2;
    this->color = _color;
}

/**************************************************************************/
/*!
    @brief    Move the object to the right on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::moveRight(int16_t _delta){
    this->disappear();
    if (this->partner->drawTriangle(
            this->x0 + _delta,
            this->y0,
            this->x1 + _delta,
            this->y1,
            this->x2 + _delta,
            this->y2,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 += _delta;
    this->x1 += _delta;
    this->x2 += _delta;
}

/**************************************************************************/
/*!
    @brief    Move the object to the left on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::moveLeft(int16_t _delta){
    this->disappear();
    if (this->partner->drawTriangle(
            this->x0 - _delta,
            this->y0,
            this->x1 - _delta,
            this->y1,
            this->x2 - _delta,
            this->y2,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 -= _delta;
    this->x1 -= _delta;
    this->x2 -= _delta;
}

/**************************************************************************/
/*!
    @brief    Move the object up on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::moveUp(int16_t _delta){
    this->disappear();
    if (this->partner->drawTriangle(
            this->x0,
            this->y0 - _delta,
            this->x1,
            this->y1 - _delta,
            this->x2,
            this->y2 - _delta,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->y0 -= _delta;
    this->y1 -= _delta;
    this->y2 -= _delta;
}

/**************************************************************************/
/*!
    @brief    Move the object down on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::moveDown(int16_t _delta){
    this->disappear();
    if (this->partner->drawTriangle(
            this->x0,
            this->y0 + _delta,
            this->x1,
            this->y1 + _delta,
            this->x2,
            this->y2 + _delta,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->y0 += _delta;
    this->y1 += _delta;
    this->y2 += _delta;
}

/**************************************************************************/
/*!
    @brief    Move the object up and to the right on certain number of pixels
    @param    _delta_x    Numbers of pixels to move the object to the right
    @param    _delta_y    Numbers of pixels to move the object up
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::moveRightUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawTriangle(
            this->x0 + _delta_x,
            this->y0 - _delta_y,
            this->x1 + _delta_x,
            this->y1 - _delta_y,
            this->x2 + _delta_x,
            this->y2 - _delta_y,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 += _delta_x;
    this->y0 -= _delta_y;
    this->x1 += _delta_x;
    this->y1 -= _delta_y;
    this->x2 += _delta_x;
    this->y2 -= _delta_y;
}

/**************************************************************************/
/*!
    @brief  Move the object down and to the right on certain number of pixels
    @param    _delta_x    Numbers of pixels to move the object to the right
    @param    _delta_y    Numbers of pixels to move the object down
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::moveRightDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawTriangle(
            this->x0 + _delta_x,
            this->y0 + _delta_y,
            this->x1 + _delta_x,
            this->y1 + _delta_y,
            this->x2 + _delta_x,
            this->y2 + _delta_y,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 += _delta_x;
    this->y0 += _delta_y;
    this->x1 += _delta_x;
    this->y1 += _delta_y;
    this->x2 += _delta_x;
    this->y2 += _delta_y;
}

/**************************************************************************/
/*!
    @brief    Move the object up and to the left on certain number of pixels
    @param    _delta_x    Numbers of pixels to move the object to the left
    @param    _delta_y    Numbers of pixels to move the object up
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::moveLeftUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawTriangle(
            this->x0 - _delta_x,
            this->y0 - _delta_y,
            this->x1 - _delta_x,
            this->y1 - _delta_y,
            this->x2 - _delta_x,
            this->y2 - _delta_y,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 -= _delta_x;
    this->y0 -= _delta_y;
    this->x1 -= _delta_x;
    this->y1 -= _delta_y;
    this->x2 -= _delta_x;
    this->y2 -= _delta_y;
}

/**************************************************************************/
/*!
    @brief  Move the object down and to the left on certain number of pixels
    @param    _delta_x    Numbers of pixels to move the object to the left
    @param    _delta_y    Numbers of pixels to move the object down
*/
/**************************************************************************/
void Geegrow_ILI9341_objectTriangle::moveLeftDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawTriangle(
            this->x0 - _delta_x,
            this->y0 + _delta_y,
            this->x1 - _delta_x,
            this->y1 + _delta_y,
            this->x2 - _delta_x,
            this->y2 + _delta_y,
            this->color
        )
    ){
        // Error
        this->appear();
        return;
    }
    this->x0 -= _delta_x;
    this->y0 += _delta_y;
    this->x1 -= _delta_x;
    this->y1 += _delta_y;
    this->x2 -= _delta_x;
    this->y2 += _delta_y;
}

/**************************************************************************/
/*!
    @brief    Get X coordinate of second point
    @return   X coordinate of second point
*/
/**************************************************************************/
int16_t Geegrow_ILI9341_objectTriangle::getX1(){
    return this->x1;
}

/**************************************************************************/
/*!
    @brief    Get Y coordinate of second point
    @return   Y coordinate of second point
*/
/**************************************************************************/
int16_t Geegrow_ILI9341_objectTriangle::getY1(){
    return this->y1;
}

/**************************************************************************/
/*!
    @brief    Get X coordinate of third point
    @return   X coordinate of third point
*/
/**************************************************************************/
int16_t Geegrow_ILI9341_objectTriangle::getX2(){
    return this->x2;
}

/**************************************************************************/
/*!
    @brief    Get Y coordinate of third point
    @return   Y coordinate of third point
*/
/**************************************************************************/
int16_t Geegrow_ILI9341_objectTriangle::getY2(){
    return this->y2;
}
