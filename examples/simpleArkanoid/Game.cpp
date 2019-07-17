#include "Game.h"

Game::Game(){
    // Buttons
    pinMode(BUTTON_LEFT, INPUT);
    pinMode(BUTTON_RIGHT, INPUT);
    // Display
    this->display._obj = new Geegrow_ILI9341();
    this->display._obj->init(LED, RESET, DC, WR, CS);
    this->display._obj->attachLibs(LIB_LETTERS_ASCII | LIB_NUMBERS_ASCII | LIB_SYMBOLS_ASCII);
    this->display._obj->fillDisplay(BLACK);
    this->display.width = this->display._obj->getWidth();
    this->display.height = this->display._obj->getHeight();
    // Game objects
    this->fly._obj = this->display._obj->createFillRectObj();
    this->fly.size = 5;
    this->fly.x0 = 150;
    this->fly.y0 = 110;
    this->fly._obj->moveTo(
        this->fly.x0,
        this->fly.y0,
        this->fly.size,
        this->fly.size,
        this->fly.color
    );
    this->catcher._obj = this->display._obj->createFillRectObj();
    this->catcher.width = 64;
    this->catcher.height = 5;
    this->catcher.x0 = 2 * this->catcher.width;
    this->catcher.y0 = this->display._obj->getHeight() - this->catcher.height - 1;
    this->catcher.step = this->catcher.width;
    this->catcher._obj->moveTo(
        this->catcher.x0,
        this->catcher.y0,
        this->catcher.width,
        this->catcher.height,
        this->catcher.color
    );
    // Lifes
    this->lifeCounter = 3;
}

void Game::setSpeed(uint8_t _speed){
    this->fly.speed = _speed;
    this->fly.delta = 2 * this->fly.speed;
    this->fly.delta_x = this->fly.delta;
    this->fly.delta_y = -this->fly.delta;
}

void Game::refresh(){
    if (this->fly.speed == 0){
        Serial.println(F("Speed not set!"));
        return;
    }
    this->fly._obj->moveTo(
        this->fly.x0,
        this->fly.y0,
        this->fly.size,
        this->fly.size,
        this->fly.color
    );
    delay(20);
    this->fly.x0 += this->fly.delta_x;
    this->fly.y0 += this->fly.delta_y;

    if (this->fly.x0 + this->fly.size >= this->display.width - 1){
        this->fly.delta_x = -this->fly.delta_x;
        this->fly.x0 += this->fly.delta_x;
    }

    if (this->fly.y0 + this->fly.size >= this->display.height - this->catcher.height){
        if ( ( (this->fly.x0 >= this->catcher.x0)
             && (this->fly.x0 < this->catcher.x0 + this->catcher.width)
             )
          || (  (this->fly.x0 + this->fly.size > this->catcher.x0)
             && (this->fly.x0 + this->fly.size <= this->catcher.x0 + this->catcher.width)
             )
        ){
            this->fly.delta_y = -this->fly.delta_y;
            this->fly.y0 += this->fly.delta_y;
        } else {
            this->mistake();
        }
    }

    if (this->fly.x0 < 1){
        this->fly.delta_x = -this->fly.delta_x;
        this->fly.x0 += this->fly.delta_x;
    }

    if (this->fly.y0 < FONT_HEIGHT + 1){
        this->fly.delta_y = -this->fly.delta_y;
        this->fly.y0 += this->fly.delta_y;
    }
}

void Game::setInterface(uint16_t _color){
    this->interfaceColor = _color;

    this->display._obj->drawLine(
        0,
        FONT_HEIGHT,
        this->display.width - 1,
        FONT_HEIGHT,
        this->interfaceColor
    );

    this->display._obj->drawLine(
        0,
        FONT_HEIGHT,
        0,
        this->display.height - this->catcher.height - 1,
        this->interfaceColor
    );

    this->display._obj->drawLine(
        this->display.width - 1,
        FONT_HEIGHT,
        this->display.width - 1,
        this->display.height - this->catcher.height - 1,
        this->interfaceColor
    );

    this->display._obj->printStr(
        F("Geegrow Gaming inc."),
        0,
        0,
        1,
        this->interfaceColor
    );


    this->display._obj->printStr(
        F("lifes:"),
        this->display.width - 9*FONT_WIDTH,
        0,
        1,
        this->interfaceColor
    );

    this->sayStart();
    this->updateLives();
}

void Game::moveCatcherLeft(){
    this->catcher._obj->moveLeft(this->catcher.step);
    this->catcher.x0 = this->catcher._obj->getX0();
}

void Game::moveCatcherRight(){
    this->catcher._obj->moveRight(this->catcher.step);
    this->catcher.x0 = this->catcher._obj->getX0();
}

void Game::sayStart(){
    this->display._obj->printStr("START", 120, 140, 2, YELLOW);
    delay(2000);
    this->display._obj->printStr("START", 120, 140, 2, BLACK);
}

void Game::sayGameOver(){
    this->display._obj->printStr("GAME OVER", 90, 140, 2, RED);
    delay(2000);
    this->display._obj->printStr("GAME OVER", 90, 140, 2, BLACK);
}

void Game::updateLives(){
    this->clearChar(this->display.width - 2*FONT_WIDTH, 0);
    this->display._obj->printChar(
        (char)(48 + this->lifeCounter),
        this->display.width - 2*FONT_WIDTH,
        0,
        1,
        this->interfaceColor
    );
}

void Game::mistake(){
    for (uint8_t i = 0; i < 2; i++){
        delay(500);
        this->catcher._obj->disappear();
        this->fly._obj->disappear();
        delay(500);
        this->catcher._obj->appear();
        this->fly._obj->appear();
    }

    this->fly.x0 = 150;
    this->fly.y0 = 110;
    this->fly.delta_x = this->fly.delta;
    this->fly.delta_y = -this->fly.delta;
    this->lifeCounter--;
    this->updateLives();

    if (this->lifeCounter == 0)
        this->restart();
}

void Game::restart(){
    this->sayGameOver();
    delay(1000);

    this->fly.x0 = 150;
    this->fly.y0 = 110;
    this->fly.delta_x = this->fly.delta;
    this->fly.delta_y = -this->fly.delta;

    this->catcher.x0 = 2 * this->catcher.width;
    this->catcher.step = this->catcher.width;
    this->catcher._obj->moveTo(
        this->catcher.x0,
        this->catcher.y0,
        this->catcher.width,
        this->catcher.height,
        this->catcher.color
    );

    this->lifeCounter = 3;
    this->updateLives();
    this->sayStart();
}

void Game::clearChar(int16_t _x0, int16_t _y0){
    this->display._obj->fillRect(
        _x0,
        _y0,
        FONT_WIDTH,
        FONT_HEIGHT,
        BLACK
    );
}
