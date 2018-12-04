/*!
 * @file GeeGrow_ILI9341_objectLine.cpp
 *
 * This is an addon library for the GeeGrow ILI9341 TFT 240x320 display,
 * which implements opportunity to create object line
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "GeeGrow_ILI9341_objectLine.h"

/**************************************************************************/
/*!
    @brief  Instantiate a line object
	@param	_objectType	Type of object to create
	@param	_partner	Pointer to class, which is a parent of main class and
						allows to use drawing functions of main class
*/
/**************************************************************************/
GeeGrow_ILI9341_objectLine::GeeGrow_ILI9341_objectLine(
    uint8_t _objectType,
    GeeGrow_ILI9341_partnership* _partner
) : GeeGrow_ILI9341_objectBase(_objectType, _partner){

}

/**************************************************************************/
/*!
    @brief  Destruct the object
*/
/**************************************************************************/
GeeGrow_ILI9341_objectLine::~GeeGrow_ILI9341_objectLine(){
    this->disappear();
}

/**************************************************************************/
/*!
    @brief  Shows the object on the screen
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::appear(){
    this->partner->drawLine(
        this->x0,
        this->y0,
        this->x1,
        this->y1,
        this->color
    );
}

/**************************************************************************/
/*!
    @brief  Hides the object on the screen
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::disappear(){
    this->partner->drawLine(
        this->x0,
        this->y0,
        this->x1,
        this->y1,
        this->color_bg
    );
}

/**************************************************************************/
/*!
    @brief  Set the object to certain place with certain properties
    @param  _x0     X coordinate of start point
    @param  _y0     Y coordinate of start point
    @param  _x1     X coordinate of end point
    @param  _y1     Y coordinate of end point
    @param  _color  Color of the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::moveTo(
    int16_t _x0,
    int16_t _y0,
    int16_t _x1,
    int16_t _y1,
    uint16_t _color
){
    this->disappear();
	if (this->partner->drawLine(_x0, _y0, _x1, _y1, _color)){
        // Error
		this->appear();
		return;
	}
	this->x0 = _x0;
	this->y0 = _y0;
    this->x1 = _x1;
	this->y1 = _y1;
	this->color = _color;
}

/**************************************************************************/
/*!
    @brief  Move the object to the right on certain number of pixels
    @param  _delta     Numbers of pixels to move the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::moveRight(int16_t _delta){
    this->disappear();
	if (this->partner->drawLine(
            this->x0 + _delta,
            this->y0,
            this->x1 + _delta,
            this->y1,
            this->color
        )
    ){
        // Error
		this->appear();
		return;
	}
	this->x0 += _delta;
    this->x1 += _delta;
}

/**************************************************************************/
/*!
    @brief  Move the object to the left on certain number of pixels
    @param  _delta     Numbers of pixels to move the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::moveLeft(int16_t _delta){
    this->disappear();
	if (this->partner->drawLine(
            this->x0 - _delta,
            this->y0,
            this->x1 - _delta,
            this->y1,
            this->color
        )
    ){
        // Error
		this->appear();
		return;
	}
	this->x0 -= _delta;
    this->x1 -= _delta;
}

/**************************************************************************/
/*!
    @brief  Move the object up on certain number of pixels
    @param  _delta     Numbers of pixels to move the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::moveUp(int16_t _delta){
    this->disappear();
	if (this->partner->drawLine(
            this->x0,
            this->y0 - _delta,
            this->x1,
            this->y1 - _delta,
            this->color
        )
    ){
        // Error
		this->appear();
		return;
	}
	this->y0 -= _delta;
    this->y1 -= _delta;
}

/**************************************************************************/
/*!
    @brief  Move the object down on certain number of pixels
    @param  _delta     Numbers of pixels to move the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::moveDown(int16_t _delta){
    this->disappear();
	if (this->partner->drawLine(
            this->x0,
            this->y0 + _delta,
            this->x1,
            this->y1 + _delta,
            this->color
        )
    ){
        // Error
		this->appear();
		return;
	}
	this->y0 += _delta;
    this->y1 += _delta;
}

/**************************************************************************/
/*!
    @brief  Move the object up and to the right on certain number of pixels
    @param  _delta_x     Numbers of pixels to move the object to the right
    @param  _delta_y     Numbers of pixels to move the object up
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::moveRightUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
	if (this->partner->drawLine(
            this->x0 + _delta_x,
            this->y0 - _delta_y,
            this->x1 + _delta_x,
            this->y1 - _delta_y,
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
}

/**************************************************************************/
/*!
    @brief  Move the object down and to the right on certain number of pixels
    @param  _delta_x     Numbers of pixels to move the object to the right
    @param  _delta_y     Numbers of pixels to move the object down
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::moveRightDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
	if (this->partner->drawLine(
            this->x0 + _delta_x,
            this->y0 + _delta_y,
            this->x1 + _delta_x,
            this->y1 + _delta_y,
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
}

/**************************************************************************/
/*!
    @brief  Move the object up and to the left on certain number of pixels
    @param  _delta_x     Numbers of pixels to move the object to the left
    @param  _delta_y     Numbers of pixels to move the object up
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::moveLeftUp(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
	if (this->partner->drawLine(
            this->x0 - _delta_x,
            this->y0 - _delta_y,
            this->x1 - _delta_x,
            this->y1 - _delta_y,
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
}

/**************************************************************************/
/*!
    @brief  Move the object down and to the left on certain number of pixels
    @param  _delta_x     Numbers of pixels to move the object to the left
    @param  _delta_y     Numbers of pixels to move the object down
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectLine::moveLeftDown(int16_t _delta_x, int16_t _delta_y){
    this->disappear();
	if (this->partner->drawLine(
            this->x0 - _delta_x,
            this->y0 + _delta_y,
            this->x1 - _delta_x,
            this->y1 + _delta_y,
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
}

/**************************************************************************/
/*!
    @brief  Get current X coordinate of end point
    @return X coordinate of end point
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341_objectLine::getX1(){
    return this->x1;
}

/**************************************************************************/
/*!
    @brief  Get current Y coordinate of end point
    @return Y coordinate of end point
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341_objectLine::getY1(){
    return this->y1;
}
