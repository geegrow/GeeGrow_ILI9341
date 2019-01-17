#ifndef EGG_H
#define EGG_H

#include "Drawer.h"
#include "Wolf.h"
#include "CommonInfo.h"

class Egg : public TweakCallbackOwnerClass {
    public:
        Egg();
        void born(uint8_t new_slide);
        void step();
        void die();
        void tweakHandler();

        GeeGrow_ILI9341_objectCircle *_obj = nullptr;
        bool isAlive = false;
        uint8_t currentSlide = 0;
//        uint8_t stepTickCounter = 0;

    private:
        void catched();
        void broken();
        void beep();
        void lastStep();
        void gameover();

        static uint8_t id_counter;
        uint8_t id = 0;
        int8_t callbackID = 0;
        uint8_t currentState = EGG_STATE_LAST;
        uint8_t radius = 6;
        uint16_t color = BLACK;
};

#endif /* EGG_H */
