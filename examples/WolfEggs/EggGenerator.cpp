#include "EggGenerator.h"

EggGenerator::EggGenerator(){
    this->egg_list = new Egg[EGGS_MAX_NUM];
}

void EggGenerator::tryLaunchEgg(){
    bool res = chance(CommonInfo::difficulty);
    if (res){
        uint8_t temp = this->selectSlide();
        if (CommonInfo::safeDelaySlides[temp] > 0)
            return;
        CommonInfo::safeDelaySlides[temp] = TICKS_SAFE_DELAY_SLIDE;

        CommonInfo::isSafeDelayAfterCreate = true;
        Tweak::setCallbackActive(CommonInfo::callbackID_safeDelayAfterCreate, true);

        if (this->egg_list[this->eggs_pos].isAlive == false){
            this->egg_list[this->eggs_pos].born(temp);
        }
        this->eggs_pos++;
        if (this->eggs_pos == EGGS_MAX_NUM)
            this->eggs_pos = 0;
    }
}

uint8_t EggGenerator::selectSlide(){
    return random(100)%4;
}

void EggGenerator::update(){
    if (CommonInfo::safeDelayAfterUpdateCounter > 0)
        CommonInfo::safeDelayAfterUpdateCounter--;

    for (uint8_t i = 0; i < 4; i++)
        if (CommonInfo::safeDelaySlides[i] > 0)
            CommonInfo::safeDelaySlides[i]--;
}

void EggGenerator::killAll(){
    for (uint8_t i = 0; i < EGGS_MAX_NUM; i++)
        if (this->egg_list[i].isAlive == true)
            this->egg_list[i].die();
}
