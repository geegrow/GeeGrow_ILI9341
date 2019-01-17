#include "Egg.h"

uint8_t Egg::id_counter = 0;

Egg::Egg(){
    this->_obj = Drawer::instance().createCircleObj();
    this->_obj->setColorBG(WHITE);
    this->id = Egg::id_counter;
    Egg::id_counter++;
    this->callbackID = Tweak::attachMsMemberCallback(this, 1000);
    Tweak::setCallbackActive(this->callbackID, false);
}

void Egg::tweakHandler(){
    this->step();
}

void Egg::born(uint8_t new_slide){
    if (!this->isAlive){
        this->currentSlide = new_slide;
        this->currentState = EGG_STATE_1;
        this->isAlive = true;
        this->step();
        Tweak::setCallbackActive(this->callbackID, true);
    }
}

void Egg::step(){
    CommonInfo::safeDelayAfterUpdateCounter = TICKS_SAFE_DELAY_AFTER_UPDATE;
    this->beep();

    if (this->currentState == EGG_STATE_LAST){
        this->lastStep();
        return;
    }

    this->_obj->moveTo(
        slides[this->currentSlide][this->currentState][0],
        slides[this->currentSlide][this->currentState][1],
        this->radius,
        this->color
    );
    this->currentState++;
}

void Egg::lastStep(){
    if (this->currentSlide == Wolf::basket_position){
        this->catched();
    } else {
        this->broken();
    }
    this->die();
}

void Egg::die(){
    this->_obj->disappear();
    this->isAlive = false;
    Tweak::setCallbackActive(this->callbackID, false);
}

void Egg::catched(){
    CommonInfo::updateScore(CommonInfo::score + 1);

    if (CommonInfo::score%20 == 0)
        CommonInfo::difficulty += 1;
    if (CommonInfo::score%100 == 0){
        CommonInfo::difficulty -= 3;
        CommonInfo::updateScoreBroken(0);
    }
}

void Egg::broken(){
    CommonInfo::updateScoreBroken(CommonInfo::score_broken + 1);
    if (this->currentSlide == LEFT_DOWN || this->currentSlide == LEFT_UP){
        CommonInfo::showLeftBroken();
    }

    if (this->currentSlide == RIGHT_DOWN || this->currentSlide == RIGHT_UP){
        CommonInfo::showRightBroken();
    }

    if (CommonInfo::score_broken == 3){
        CommonInfo::isGameover = true;
    }
}

void Egg::beep(){
    tone(BUZZER_PWM, 10000 + (this->currentSlide*2000), 100);
}
