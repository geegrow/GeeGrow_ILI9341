#include "Drawer.h"

Drawer::Drawer() : GeeGrow_ILI9341() {
    // Display
    this->init(LED, RESET, DC, WR, CS);
    this->attachLibs(LIB_NUMBERS_ASCII | LIB_LETTERS_ASCII | LIB_SYMBOLS_ASCII);
    this->fillDisplay(WHITE);
}

void Drawer::writeMemoryCustom(uint8_t pos, const uint8_t *_buf, uint8_t raws, uint8_t columns){
    digitalWrite(this->pins.cs, LOW);    // CS

    digitalWrite(this->pins.dc, LOW);    // DC CMD
    SPI.transfer(CMD_MEMORY_WRITE);
    SWAP_WR(this->pins.wr);
    digitalWrite(this->pins.dc, HIGH);    // DC DATA

    if (pos == RIGHT){
        for (uint8_t i = 0; i < columns; i++){
            for (uint8_t j = 0; j < raws/8; j++){
                uint8_t tmp = pgm_read_byte_near(_buf + (uint16_t)i*raws/8 + j);
                for (int8_t k = 7; k >= 0; k--){
                    if (tmp & (1 << k)){
                        SPI.transfer(BLACK >> 8);
                        SPI.transfer(BLACK & 0xFF);
                        SWAP_WR(this->pins.wr);
                    } else {
                        SPI.transfer(WHITE >> 8);
                        SPI.transfer(WHITE & 0xFF);
                        SWAP_WR(this->pins.wr);
                    }
                }
            }
        }
    } else if (pos == LEFT) {
        for (int8_t i = columns - 1; i >= 0; i--){
            for (uint8_t j = 0; j < raws/8; j++){
                uint8_t tmp = pgm_read_byte_near(_buf + (uint16_t)i*raws/8 + j);
                for (int8_t k = 7; k >= 0; k--){
                    if (tmp & (1 << k)){
                        SPI.transfer(BLACK >> 8);
                        SPI.transfer(BLACK & 0xFF);
                        SWAP_WR(this->pins.wr);
                    } else {
                        SPI.transfer(WHITE >> 8);
                        SPI.transfer(WHITE & 0xFF);
                        SWAP_WR(this->pins.wr);
                    }
                }
            }
        }
    }

    digitalWrite(this->pins.dc, LOW);    // DC CMD
    SPI.transfer(CMD_NOP);
    SWAP_WR(this->pins.wr);

    digitalWrite(this->pins.cs, HIGH);    // CS
}

void Drawer::castSelectedRangeCustom(int16_t _x0, int16_t _y0, int16_t _x1, int16_t _y1){
    this->castSelectedRange(_x0, _y0, _x1, _y1);
}
