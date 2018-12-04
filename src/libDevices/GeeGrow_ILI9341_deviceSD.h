/*!
 * @file GeeGrow_ILI9341_deviceSD.h
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

#ifndef GEEGROW_ILI9341_DEVICE_SD_H
#define GEEGROW_ILI9341_DEVICE_SD_H

#include <Arduino.h>
#include <SdFat.h>
#include <GeeGrow_ILI9341_defines.h>

/**************************************************************************/
/*!
    @brief  Size of a buffer to store fragment of image
    @note   Size is 640 as image is sent by rows, and maximum size of row
            is 320 pixels (640 bytes)
*/
/**************************************************************************/
#define SD_BUFFER_SIZE  640

/**************************************************************************/
/*!
    @brief  Struct to store file header of .bmp image
*/
/**************************************************************************/
struct BITMAPFILEHEADER_t {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t rsvd0;
    uint16_t rsvd1;
    uint32_t bfOffBits;
};

/**************************************************************************/
/*!
    @brief  Struct to store image header of .bmp image
*/
/**************************************************************************/
struct BITMAPINFOHEADER_t
{
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};

/**************************************************************************/
/*!
    @brief  Class that stores state and functions to communicate with SD card
*/
/**************************************************************************/
class GeeGrow_ILI9341_deviceSD {
    public:
        GeeGrow_ILI9341_deviceSD(){}
        ~GeeGrow_ILI9341_deviceSD(){}
        int8_t init(uint8_t _cs_sd);
        void setFileName(char *_filename);
        int8_t getReady();
        uint16_t* getBlock(uint32_t _pos, uint16_t _size_bytes);
        BITMAPFILEHEADER_t BITMAPFILEHEADER;
        BITMAPINFOHEADER_t BITMAPINFOHEADER;

    private:
        SdFat SD;
        SdFile file;
        char *filename = NULL;
        uint16_t sd_buffer [SD_BUFFER_SIZE];
};

#endif /* GEEGROW_ILI9341_DEVICE_SD_H */