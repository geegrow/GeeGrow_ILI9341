#include "Setting.h"

Setting::Setting(){
    // Buttons
    pinMode(BUTTON_DOWN_LEFT, INPUT);
    pinMode(BUTTON_DOWN_RIGHT, INPUT);
    pinMode(BUTTON_UP_LEFT, INPUT);
    pinMode(BUTTON_UP_RIGHT, INPUT);
    // Buzzer
    pinMode(BUZZER_PWM, OUTPUT);

    this->_generator = new EggGenerator();
}

void Setting::launchEggs(){
    CommonInfo::callbackID_globalTicks = Tweak::attachMsCallback(
        timerHandler,
        TICK_MS
    );
    CommonInfo::callbackID_leftBroken = Tweak::attachMsCallback(
        CommonInfo::hideLeftBroken,
        MSECONDS_SHOW_BROKEN
    );
    CommonInfo::callbackID_rightBroken = Tweak::attachMsCallback(
        CommonInfo::hideRightBroken,
        MSECONDS_SHOW_BROKEN
    );
    CommonInfo::callbackID_showGameover = Tweak::attachMsCallback(
        CommonInfo::hideGameover,
        MSECONDS_SHOW_GAMEOVER
    );
    CommonInfo::callbackID_safeDelayAfterCreate = Tweak::attachMsCallback(
        CommonInfo::elapsedSafeDelayAfterCreate,
        MSECONDS_SAFE_DELAY_AFTER_CREATE
    );
    Tweak::setCallbackActive(CommonInfo::callbackID_leftBroken, false);
    Tweak::setCallbackActive(CommonInfo::callbackID_rightBroken, false);
    Tweak::setCallbackActive(CommonInfo::callbackID_showGameover, false);
    Tweak::setCallbackActive(CommonInfo::callbackID_safeDelayAfterCreate, false);
    randomSeed(analogRead(10));
}

void Setting::timerHandler(){
    Setting::instance().gotTick = true;
}

void Setting::ticksHandler(){
    // Handle gameover routine
    if (CommonInfo::isGameover){
        CommonInfo::isGameover = false;
        this->_generator->killAll();
        CommonInfo::gameover();
        return;
    }
    // Update
    this->_generator->update();
    // Launch new eggs
    if (CommonInfo::isSafeDelayAfterCreate == false &&
        CommonInfo::safeDelayAfterUpdateCounter == 0
    ){
        this->_generator->tryLaunchEgg();
    }
}

void Setting::drawInterface(){
    // Left up slide
    Drawer::instance().drawLine(0, 70, 12, 70, RED);
    Drawer::instance().drawLine(0, 71, 12, 71, RED);
    Drawer::instance().drawLine(12, 70, 64, 98, RED);
    Drawer::instance().drawLine(12, 71, 64, 99, RED);
    Drawer::instance().drawLine(50, 91, 50, 110, RED);
    Drawer::instance().drawLine(51, 91, 51, 110, RED);

    // Left down slide
    Drawer::instance().drawLine(0, 130, 12, 130, RED);
    Drawer::instance().drawLine(0, 131, 12, 131, RED);
    Drawer::instance().drawLine(12, 130, 64, 158, RED);
    Drawer::instance().drawLine(12, 131, 64, 159, RED);
    Drawer::instance().drawLine(50, 151, 50, 170, RED);
    Drawer::instance().drawLine(51, 151, 51, 170, RED);
    Drawer::instance().fillRect(2, 135, 10, 35, RED);
    Drawer::instance().fillRect(14, 140, 10, 30, RED);
    Drawer::instance().fillRect(26, 148, 10, 22, RED);
    Drawer::instance().fillRect(38, 155, 10, 15, RED);

    // Right up slide
    Drawer::instance().drawLine(319 - 0, 70, 319 - 12, 70, RED);
    Drawer::instance().drawLine(319 - 0, 71, 319 - 12, 71, RED);
    Drawer::instance().drawLine(319 - 12, 70, 319 - 64, 98, RED);
    Drawer::instance().drawLine(319 - 12, 71, 319 - 64, 99, RED);
    Drawer::instance().drawLine(319 - 50, 91, 319 - 50, 110, RED);
    Drawer::instance().drawLine(319 - 51, 91, 319 - 51, 110, RED);

    // Right down slide
    Drawer::instance().drawLine(319 - 0, 130, 319 - 12, 130, RED);
    Drawer::instance().drawLine(319 - 0, 131, 319 - 12, 131, RED);
    Drawer::instance().drawLine(319 - 12, 130, 319 - 64, 158, RED);
    Drawer::instance().drawLine(319 - 12, 131, 319 - 64, 159, RED);
    Drawer::instance().drawLine(319 - 50, 151, 319 - 50, 170, RED);
    Drawer::instance().drawLine(319 - 51, 151, 319 - 51, 170, RED);
    Drawer::instance().fillRect(319 - 12, 135, 10, 35, RED);
    Drawer::instance().fillRect(319 - 24, 140, 10, 30, RED);
    Drawer::instance().fillRect(319 - 36, 148, 10, 22, RED);
    Drawer::instance().fillRect(319 - 48, 155, 10, 15, RED);

    // Left bush
    Drawer::instance().fillCircle(50, 190, 15, GREEN);
    Drawer::instance().fillCircle(15, 175, 20, GREEN);
    Drawer::instance().fillCircle(40, 175, 10, GREEN);
    Drawer::instance().fillCircle(30, 190, 15, GREEN);
    Drawer::instance().fillCircle(5, 195, 10, GREEN);

    // Right bush
    Drawer::instance().fillCircle(319 - 50, 190, 15, GREEN);
    Drawer::instance().fillCircle(319 - 15, 175, 20, GREEN);
    Drawer::instance().fillCircle(319 - 40, 175, 10, GREEN);
    Drawer::instance().fillCircle(319 - 30, 190, 15, GREEN);
    Drawer::instance().fillCircle(319 - 5, 195, 10, GREEN);

    // Score
    Drawer::instance().printStr(String(CommonInfo::score), 250, 10, 2, BLACK);
    Drawer::instance().printStr(String(CommonInfo::score_broken), 50, 10, 2, RED);
}
