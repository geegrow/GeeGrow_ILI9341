#include "CommonInfo.h"

CommonInfo _commonInfo;
uint8_t CommonInfo::difficulty = START_DIFFICULTY;
uint16_t CommonInfo::score = 0;
uint8_t CommonInfo::score_broken = 0;

bool CommonInfo::isSafeDelayAfterCreate = false;
bool CommonInfo::isGameover = false;

uint8_t CommonInfo::safeDelaySlides[4];
uint8_t CommonInfo::safeDelayAfterUpdateCounter = TICKS_SAFE_DELAY_AFTER_UPDATE;

int8_t CommonInfo::callbackID_leftBroken = 0;
int8_t CommonInfo::callbackID_rightBroken = 0;
int8_t CommonInfo::callbackID_globalTicks = 0;
int8_t CommonInfo::callbackID_showGameover = 0;
int8_t CommonInfo::callbackID_safeDelayAfterCreate = 0;


CommonInfo::CommonInfo(){
    for (uint8_t i = 0; i < 4; i++)
        CommonInfo::safeDelaySlides[i] = 0;
}

void CommonInfo::updateScore(uint16_t new_score){
    CommonInfo::score = new_score;
    Drawer::instance().fillRect(250, 10, 60, 40, WHITE);
    Drawer::instance().printStr(String(CommonInfo::score), 250, 10, 2, BLACK);
}

void CommonInfo::updateScoreBroken(uint8_t new_score){
    CommonInfo::score_broken = new_score;
    Drawer::instance().fillRect(50, 10, 60, 40, WHITE);
    Drawer::instance().printStr(String(CommonInfo::score_broken), 50, 10, 2, RED);
}

void CommonInfo::gameover(){
    CommonInfo::updateScore(0);
    CommonInfo::updateScoreBroken(0);
    CommonInfo::difficulty = START_DIFFICULTY;
    Tweak::setCallbackActive(CommonInfo::callbackID_globalTicks, false);
    CommonInfo::showGameover();
}

void CommonInfo::showLeftBroken(){
    int16_t temp_left_half_egg[16] = {
        77, 195,
        72, 199,
        72, 201,
        77, 205,
        67, 203,
        64, 200,
        67, 197,
        77, 195
    };
    int16_t temp_right_half_egg[16] = {
        83, 195,
        88, 199,
        88, 201,
        83, 205,
        93, 203,
        96, 200,
        93, 197,
        83, 195
    };
    Drawer::instance().fillCircle(80, 200, 4, YELLOW);
    Drawer::instance().drawCircle(80, 200, 4, BLACK);
    Drawer::instance().drawBrokenLine(8, temp_left_half_egg, BLACK);
    Drawer::instance().drawBrokenLine(8, temp_right_half_egg, BLACK);

    Tweak::setCallbackActive(CommonInfo::callbackID_leftBroken, true);
}

void CommonInfo::hideLeftBroken(){
    Drawer::instance().fillRect(64, 195, 33, 11, WHITE);
    Tweak::setCallbackActive(CommonInfo::callbackID_leftBroken, false);
}

void CommonInfo::showRightBroken(){
    int16_t temp_left_half_egg[16] = {
        319-77, 195,
        319-72, 199,
        319-72, 201,
        319-77, 205,
        319-67, 203,
        319-64, 200,
        319-67, 197,
        319-77, 195
    };
    int16_t temp_right_half_egg[16] = {
        319-83, 195,
        319-88, 199,
        319-88, 201,
        319-83, 205,
        319-93, 203,
        319-96, 200,
        319-93, 197,
        319-83, 195
    };
    Drawer::instance().fillCircle(239, 200, 4, YELLOW);
    Drawer::instance().drawCircle(239, 200, 4, BLACK);
    Drawer::instance().drawBrokenLine(8, temp_left_half_egg, BLACK);
    Drawer::instance().drawBrokenLine(8, temp_right_half_egg, BLACK);

    Tweak::setCallbackActive(CommonInfo::callbackID_rightBroken, true);
}

void CommonInfo::hideRightBroken(){
    Drawer::instance().fillRect(223, 195, 33, 11, WHITE);
    Tweak::setCallbackActive(CommonInfo::callbackID_rightBroken, false);
}

void CommonInfo::showGameover(){
    Drawer::instance().printStr("Game Over", 90, 10, 2, BLACK);
    Tweak::setCallbackActive(CommonInfo::callbackID_showGameover, true);
}

void CommonInfo::hideGameover(){
    Drawer::instance().fillRect(90, 10, 150, 40, WHITE);
    Tweak::setCallbackActive(CommonInfo::callbackID_showGameover, false);
    Tweak::setCallbackActive(CommonInfo::callbackID_globalTicks, true);
}

void CommonInfo::elapsedSafeDelayAfterCreate(){
    Tweak::setCallbackActive(CommonInfo::callbackID_safeDelayAfterCreate, false);
    CommonInfo::isSafeDelayAfterCreate = false;
}
