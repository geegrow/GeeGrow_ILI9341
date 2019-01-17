#ifndef TOOLS_H
#define TOOLS_H

#include <Arduino.h>

// Pinout display
#define LED   A0
#define RESET A3
#define DC    A1
#define WR    A4
#define CS    A2
// Pinout buttons
#define BUTTON_DOWN_LEFT       0
#define BUTTON_DOWN_RIGHT      3
#define BUTTON_UP_LEFT         1
#define BUTTON_UP_RIGHT        7
// Buttons interrupts
#define BUTTON_DOWN_LEFT_IRQ   2
#define BUTTON_DOWN_RIGHT_IRQ  0
#define BUTTON_UP_LEFT_IRQ     3
#define BUTTON_UP_RIGHT_IRQ    4
// Pinout buzzer
#define BUZZER_PWM             11

// Positions
enum {
    LEFT_UP    = 0,
    LEFT_DOWN  = 1,
    RIGHT_UP   = 2,
    RIGHT_DOWN = 3,
    LEFT       = 4,
    RIGHT      = 5
};
// Egg states
enum {
    EGG_STATE_1       = 0,
    EGG_STATE_2       = 1,
    EGG_STATE_3       = 2,
    EGG_STATE_4       = 3,
    EGG_STATE_5       = 4,
    EGG_STATE_LAST    = 5
};

#define TICK_MS                           100
#define TICKS_SAFE_DELAY_SLIDE            30
#define MSECONDS_SHOW_GAMEOVER            2000
#define MSECONDS_SHOW_BROKEN              2000
#define MSECONDS_SAFE_DELAY_AFTER_CREATE  500
#define MSECONDS_SAFE_DELAY_AFTER_UPDATE  300
#define TICKS_SAFE_DELAY_AFTER_UPDATE     3
#define EGGS_MAX_NUM                      5
#define START_DIFFICULTY                  4

// Random
bool chance(uint8_t percent);

#endif /* TOOLS_H */
