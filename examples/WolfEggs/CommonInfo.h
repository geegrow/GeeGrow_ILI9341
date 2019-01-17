#ifndef COMMONINFO_H
#define COMMONINFO_H

#include <Tweak.h>
#include "Drawer.h"

class CommonInfo {
    public:
        CommonInfo();
        static void updateScore(uint16_t new_score);
        static void updateScoreBroken(uint8_t new_score);
        static void gameover();
        static void showLeftBroken();
        static void hideLeftBroken();
        static void showRightBroken();
        static void hideRightBroken();
        static void showGameover();
        static void hideGameover();
        static void elapsedSafeDelayAfterCreate();

        static uint8_t difficulty;
        static uint16_t score;
        static uint8_t score_broken;
        // Flags
        static bool isSafeDelayAfterCreate;
        static bool isGameover;
        // Tick counters
        static uint8_t safeDelaySlides[4];
        static uint8_t safeDelayAfterUpdateCounter;
        // Callbacks
        static int8_t callbackID_leftBroken;
        static int8_t callbackID_rightBroken;
        static int8_t callbackID_globalTicks;
        static int8_t callbackID_showGameover;
        static int8_t callbackID_safeDelayAfterCreate;
};

// Coords of eggs on slides in every state
const int16_t slides[4][5][2] = {
    {
        { 10, 62 },
        { 27, 69 },
        { 44, 78 },
        { 61, 88 },
        { 77, 110}
    },
    {
        { 10, 122 },
        { 27, 129 },
        { 44, 138 },
        { 61, 148 },
        { 77, 165 }
    },
    {
        { 319-10, 62 },
        { 319-27, 69 },
        { 319-44, 78 },
        { 319-61, 88 },
        { 319-77, 110}
    },
    {
        { 319-10, 122 },
        { 319-27, 129 },
        { 319-44, 138 },
        { 319-61, 148 },
        { 319-77, 165 }
    }
};

#endif /* COMMONINFO_H */
