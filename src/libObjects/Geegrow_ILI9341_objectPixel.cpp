/*!
 * @file Geegrow_ILI9341_objectPixel.cpp
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

#include "Geegrow_ILI9341_objectPixel.h"

/**************************************************************************/
/*!
    @brief    Instantiate a pixel object
    @param    _objectType    Type of object to create
    @param    _partner       Pointer to class, which is a parent of main class and
                             allows to use drawing functions of main class
*/
/**************************************************************************/
Geegrow_ILI9341_objectPixel::Geegrow_ILI9341_objectPixel(
    uint8_t _objectType,
    Geegrow_ILI9341_partnership* _partner
) : Geegrow_ILI9341_objectBase(_objectType, _partner){

}

/**************************************************************************/
/*!
    @brief    Destruct the object
*/
/**************************************************************************/
Geegrow_ILI9341_objectPixel::~Geegrow_ILI9341_objectPixel(){
    this->disappear();
}

/**************************************************************************/
/*!
    @brief    Shows the object on the screen
*/
/**************************************************************************/
void Geegrow_ILI9341_objectPixel::appear(){
    this->partner->drawPixel(this->x0, this->y0, this->color);
}

/**************************************************************************/
/*!
    @brief    Hides the object on the screen
*/
/**************************************************************************/
void Geegrow_ILI9341_objectPixel::disappear(){
    this->partner->drawPixel(this->x0, this->y0, this->color_bg);
}

/**************************************************************************/
/*!
    @brief    Set the object to certain place with certain properties
    @param    _x0     X coordinate of pixel
    @param    _y0     Y coordinate of pixel
    @param    _color  Color of the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectPixel::moveTo(
    int16_t _x0,
    int16_t _y0,
    uint16_t _color
){
    this->disappear();
    if (this->partner->drawPixel(_x0, _y0, _color)){
        this->appear();
        return;
    }
    this->x0 = _x0;
    this->y0 = _y0;
    this->color = _color;
}

/**************************************************************************/
/*!
    @brief    Move the object to the right on certain number of pixels
    @param    _delta    Numbers of pixels to move the object
*/
/**************************************************************************/
void Geegrow_ILI9341_objectPixel::moveRight(int16_t _delta){
    this->disappear();
    if (this->partner->drawPixel(
            this->x0 + _delta,
            this->y0,
            this->color
        )
    ){
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
void Geegrow_ILI9341_objectPixel::moveLeft(int16_t _delta){
    this->disappear();
    if (this->partner->drawPixel(
            this->x0 - _delta,
            this->y0,
            this->color
        )
    ){
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
void Geegrow_ILI9341_objectPixel::moveUp(int16_t _delta){
    this->disappear();
    if (this->partner->drawPixel(
            this->x0,
            this->y0 - _delta,
            this->color
        )
    ){
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
void Geegrow_ILI9341_objectPixel::moveDown(int16_t _delta){
    this->disappear();
    if (this->partner->drawPixel(
            this->x0,
            this->y0 + _delta,
            this->color
        )
    ){
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
void Geegrow_ILI9341_objectPixel::moveRightUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawPixel(
            this->x0 + _delta_x,
            this->y0 - _delta_y,
            this->color
        )
    ){
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
void Geegrow_ILI9341_objectPixel::moveRightDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawPixel(
            this->x0 + _delta_x,
            this->y0 + _delta_y,
            this->color
        )
    ){
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
void Geegrow_ILI9341_objectPixel::moveLeftUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawPixel(
            this->x0 - _delta_x,
            this->y0 - _delta_y,
            this->color
        )
    ){
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
void Geegrow_ILI9341_objectPixel::moveLeftDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
    if (this->partner->drawPixel(
            this->x0 - _delta_x,
            this->y0 + _delta_y,
            this->color
        )
    ){
        this->appear();
        return;
    }
    this->x0 -= _delta_x;
    this->y0 += _delta_y;
}
