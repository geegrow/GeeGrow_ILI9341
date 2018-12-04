#ifndef GAME_H
#define GAME_H

#include <GeeGrow_ILI9341.h>

// Pinout display
#define LED   12
#define RESET 9
#define DC    11
#define WR    8
#define CS    10
// Pinout buttons
#define BUTTON_LEFT     3
#define BUTTON_RIGHT    0
#define BUTTON_LEFT_IRQ     0
#define BUTTON_RIGHT_IRQ    2

struct catcher_t {
    GeeGrow_ILI9341_objectFillRect *_obj = NULL;
    int16_t width = 0;
    int16_t height = 0;
    int16_t x0 = 0;
    int16_t y0 = 0;
    int16_t step = 0;
    uint16_t color = GREEN;
};

struct fly_t {
    GeeGrow_ILI9341_objectFillRect *_obj = NULL;
    int16_t size = 0;
    int16_t x0 = 0;
    int16_t y0 = 0;
    int16_t delta = 0;
    int16_t delta_x = 0;
    int16_t delta_y = 0;
    int16_t speed = 0;
    uint16_t color = GREEN;
};

struct display_t {
    GeeGrow_ILI9341 *_obj = NULL;
    int16_t width = 0;
    int16_t height = 0;
};

class Game {
    public:
        Game();
        ~Game(){}
        void setSpeed(uint8_t _speed);
        void refresh();
        void setInterface(uint16_t _color);
        void moveCatcherLeft();
        void moveCatcherRight();

        fly_t fly;
        catcher_t catcher;
        display_t display;

    private:
        void sayStart();
        void sayGameOver();
        void updateLives();
        void mistake();
        void restart();
        void clearChar(int16_t _x0, int16_t _y0);

        uint8_t lifeCounter;
        uint16_t interfaceColor;
};

#endif /* GAME_H */
