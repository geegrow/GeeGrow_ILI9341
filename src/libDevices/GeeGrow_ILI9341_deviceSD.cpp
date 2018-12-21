/*!
 * @file GeeGrow_ILI9341_deviceSD.cpp
 *
 * This is an addon library for the GeeGrow ILI9341 TFT 240x320 display,
 * which implements communication with SD card
 * https://www.geegrow.ru
 *
 * @section author Author
 * Written by Anton Pomazanov
 *
 * @section license License
 * BSD license, all text here must be included in any redistribution.
 *
 */

#include "GeeGrow_ILI9341_deviceSD.h"

/**************************************************************************/
/*!
    @brief    Initialization of SD card
    @param    _cs_sd    Chip Select pin for SD card
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341_deviceSD::init(uint8_t _cs_sd){
    pinMode(_cs_sd, OUTPUT);
    if (!this->SD.begin(_cs_sd)){
        Serial.println(F("init(): SD init error"));
        return -1;
    }
    return 0;
}

/**************************************************************************/
/*!
    @brief    Set filename of image, that we will read from SD card
*/
/**************************************************************************/
void GeeGrow_ILI9341_deviceSD::setFileName(char *_filename){
    if (!this->SD.exists(_filename)){
        Serial.println(F("setFileName(): file doesn't exist"));
        return;
    }
    this->filename = _filename;
}

/**************************************************************************/
/*!
    @brief    Read metadata of a file
    @return   Status byte
*/
/**************************************************************************/
int8_t GeeGrow_ILI9341_deviceSD::getReady(){
    if (!this->file.open(this->filename)){
        Serial.println(F("getReady(): file open error"));
        return -1;
    }

    this->file.read(&this->BITMAPFILEHEADER, sizeof(BITMAPFILEHEADER_t));
    this->file.read(&this->BITMAPINFOHEADER, sizeof(BITMAPINFOHEADER_t));
    this->file.close();
    return 0;
}

/**************************************************************************/
/*!
    @brief    Get a certain fragment of data from the image
    @param    _pos        Address of requested fragment
    @param    _size_bytes Number of bytes to read
    @return   Pointer to data, read from SD card
*/
/**************************************************************************/
uint16_t* GeeGrow_ILI9341_deviceSD::getBlock(uint32_t _pos, uint16_t _size_bytes){
    if (_size_bytes > SD_BUFFER_SIZE){
        Serial.println(F("getNextBlock(): size too big"));
        return nullptr;
    }

    if (!this->file.open(this->filename)){
        Serial.println(F("getNextBlock(): file open error"));
        return nullptr;
    }

    this->file.seekSet(_pos);
    this->file.read(this->sd_buffer, _size_bytes);
    this->file.close();
    return this->sd_buffer;
}
