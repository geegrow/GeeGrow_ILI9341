#include "Wolf.h"
#include "Setting.h"

/* Pinout is defined in tools.h file */

Wolf *wolf = nullptr;

volatile bool left_up_pressed = false;
volatile bool left_down_pressed = false;
volatile bool right_up_pressed = false;
volatile bool right_down_pressed = false;

void leftBottomPressed();
void rightBottomPressed();
void leftTopPressed();
void rightTopPressed();
void clearCurrentBasket();
void clearCurrentWolf();

void setup(){
//    Serial.begin(9600);
//    while(!Serial);

    Tweak::setCallbackArraySize(16);
    attachInterrupt(BUTTON_DOWN_LEFT_IRQ, leftBottomPressed, FALLING);
    attachInterrupt(BUTTON_DOWN_RIGHT_IRQ, rightBottomPressed, FALLING);
    attachInterrupt(BUTTON_UP_LEFT_IRQ, leftTopPressed, FALLING);
    attachInterrupt(BUTTON_UP_RIGHT_IRQ, rightTopPressed, FALLING);
    wolf = new Wolf();
    Setting::instance().drawInterface();
    Setting::instance().launchEggs();
    left_down_pressed = true;
}

void loop(){
    noInterrupts();
    if (Setting::instance().gotTick){
        Setting::instance().gotTick = false;
        Setting::instance().ticksHandler();
    }

    if (left_up_pressed){
        left_up_pressed = false;
        if (Wolf::wolf_position != LEFT){
            clearCurrentWolf();
            wolf->wolfLeftAppear();
            Wolf::wolf_position = LEFT;
        }
        if (Wolf::basket_position != LEFT_UP){
            clearCurrentBasket();
            wolf->basketUpLeftAppear();
            Wolf::basket_position = LEFT_UP;
        }
    }

    if (left_down_pressed){
        left_down_pressed = false;
        if (Wolf::wolf_position != LEFT){
            clearCurrentWolf();
            wolf->wolfLeftAppear();
            Wolf::wolf_position = LEFT;
        }
        if (Wolf::basket_position != LEFT_DOWN){
            clearCurrentBasket();
            wolf->basketDownLeftAppear();
            Wolf::basket_position = LEFT_DOWN;
        }
    }

    if (right_up_pressed){
        right_up_pressed = false;
        if (Wolf::wolf_position != RIGHT){
            clearCurrentWolf();
            wolf->wolfRightAppear();
            Wolf::wolf_position = RIGHT;
        }
        if (Wolf::basket_position != RIGHT_UP){
            clearCurrentBasket();
            wolf->basketUpRightAppear();
            Wolf::basket_position = RIGHT_UP;
        }
    }

    if (right_down_pressed){
        right_down_pressed = false;
        if (Wolf::wolf_position != RIGHT){
            clearCurrentWolf();
            wolf->wolfRightAppear();
            Wolf::wolf_position = RIGHT;
        }
        if (Wolf::basket_position != RIGHT_DOWN){
            clearCurrentBasket();
            wolf->basketDownRightAppear();
            Wolf::basket_position = RIGHT_DOWN;
        }
    }
    interrupts();
}

void leftBottomPressed(){
    left_down_pressed = true;
}

void rightBottomPressed(){
    right_down_pressed = true;
}

void leftTopPressed(){
    left_up_pressed = true;
}

void rightTopPressed(){
    right_up_pressed = true;
}

void clearCurrentBasket(){
    switch (Wolf::basket_position){
        case LEFT_UP:
            wolf->basketUpLeftDisappear();
            break;
        case LEFT_DOWN:
            wolf->basketDownLeftDisappear();
            break;
        case RIGHT_UP:
            wolf->basketUpRightDisappear();
            break;
        case RIGHT_DOWN:
            wolf->basketDownRightDisappear();
            break;
        default:
            break;
    }
}

void clearCurrentWolf(){
    switch (Wolf::wolf_position){
        case LEFT:
            wolf->wolfLeftDisappear();
            break;
        case RIGHT:
            wolf->wolfRightDisappear();
            break;
        default:
            break;
    }
}
