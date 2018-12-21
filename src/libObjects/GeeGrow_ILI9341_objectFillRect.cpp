/*!
 * @file GeeGrow_ILI9341_objectFillRect.cpp
 *
 * This is an addon library for the GeeGrow ILI9341 TFT 240x320 display,
 * which implements opportunity to create object filled rectangle
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "GeeGrow_ILI9341_objectFillRect.h"

/**************************************************************************/
/*!
    @brief    Instantiate a filled rectangle object
    @param    _objectType    Type of object to create
    @param    _partner       Pointer to class, which is a parent of main class and
                             allows to use drawing functions of main class
*/
/**************************************************************************/
GeeGrow_ILI9341_objectFillRect::GeeGrow_ILI9341_objectFillRect(
    uint8_t _objectType,
    GeeGrow_ILI9341_partnership* _partner
) : GeeGrow_ILI9341_objectBase(_objectType, _partner){

}

/**************************************************************************/
/*!
    @brief    Destruct the object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectFillRect::~GeeGrow_ILI9341_objectFillRect(){
    this->disappear();
}

/**************************************************************************/
/*!
    @brief    Shows the object on the screen
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillRect::appear(){
    this->partner->fillRect(
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
void GeeGrow_ILI9341_objectFillRect::disappear(){
    this->partner->fillRect(
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
    @param    _x0       X coordinate of top left corner
    @param    _y0       Y coordinate of top left corner
    @param    _width    Width of rectangle
    @param    _height   Height of rectangle
    @param    _color    Color of the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillRect::moveTo(
    int16_t _x0,
    int16_t _y0,
    int16_t _width,
    int16_t _height,
    uint16_t _color
){
    this->disappear();
    if (this->partner->fillRect(_x0, _y0, _width, _height, _color)){
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
void GeeGrow_ILI9341_objectFillRect::moveRight(int16_t _delta){
    this->disappear();
    if (this->partner->fillRect(
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
void GeeGrow_ILI9341_objectFillRect::moveLeft(int16_t _delta){
    this->disappear();
    if (this->partner->fillRect(
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
void GeeGrow_ILI9341_objectFillRect::moveUp(int16_t _delta){
    this->disappear();
    if (this->partner->fillRect(
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
void GeeGrow_ILI9341_objectFillRect::moveDown(int16_t _delta){
    this->disappear();
    if (this->partner->fillRect(
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
void GeeGrow_ILI9341_objectFillRect::moveRightUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->fillRect(
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
void GeeGrow_ILI9341_objectFillRect::moveRightDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->fillRect(
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
void GeeGrow_ILI9341_objectFillRect::moveLeftUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->fillRect(
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
void GeeGrow_ILI9341_objectFillRect::moveLeftDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->fillRect(
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
int16_t GeeGrow_ILI9341_objectFillRect::getWidth(){
    return this->width;
}

/**************************************************************************/
/*!
    @brief    Get current height of rectangle object
    @return   Height of rectangle object
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341_objectFillRect::getHeight(){
    return this->height;
}

/**************************************************************************/
/*!
    @brief    Set width of rectangle object
    @param    _width    Width of rectangle object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectFillRect::setWidth(int16_t _width){
    this->disappear();
    if (this->partner->fillRect(
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
void GeeGrow_ILI9341_objectFillRect::setHeight(int16_t _height){
    this->disappear();
    if (this->partner->fillRect(
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
