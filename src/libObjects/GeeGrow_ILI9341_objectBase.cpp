/*!
 * @file GeeGrow_ILI9341_objectBase.cpp
 *
 * This is an addon library for the GeeGrow ILI9341 TFT 240x320 display,
 * which implements opportunity to create objects on screen
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "GeeGrow_ILI9341_objectBase.h"

/**************************************************************************/
/*!
    @brief    Instantiate a basic object
    @param    _objectType   Type of object to create
    @param    _partner      Pointer to class, which is a parent of main class and
                            allows to use drawing functions of main class
*/
/**************************************************************************/
GeeGrow_ILI9341_objectBase::GeeGrow_ILI9341_objectBase(
    uint8_t _objectType,
    GeeGrow_ILI9341_partnership* _partner
){
    this->objectType = _objectType;
    this->partner = _partner;
}

/**************************************************************************/
/*!
    @brief    Get X coordinate of the object
    @return   X coordinate of top left corner of the object
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341_objectBase::getX0(){
    return this->x0;
}

/**************************************************************************/
/*!
    @brief    Get Y coordinate of the object
    @return   Y coordinate of top left corner of the object
*/
/**************************************************************************/
int16_t GeeGrow_ILI9341_objectBase::getY0(){
    return this->y0;
}

/**************************************************************************/
/*!
    @brief    Get current color of the object
    @return   Color of the object
*/
/**************************************************************************/
uint16_t GeeGrow_ILI9341_objectBase::getColor(){
    return this->color;
}

/**************************************************************************/
/*!
    @brief    Get current background color of the object
    @return   Color, which is set to fill space after the object, when it moves
*/
/**************************************************************************/
uint16_t GeeGrow_ILI9341_objectBase::getColorBG(){
    return this->color_bg;
}

/**************************************************************************/
/*!
    @brief    Set color of the object
    @param    _color    Color of the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectBase::setColor(uint16_t _color){
    this->disappear();
    this->color = _color;
    this->appear();
}

/**************************************************************************/
/*!
    @brief    Set background color of the object
    @param    _color    Background color of the object
*/
/**************************************************************************/
void GeeGrow_ILI9341_objectBase::setColorBG(uint16_t _color){
    this->color_bg = _color;
}
