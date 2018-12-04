#include "Game.h"
Game *game;
bool buttonLeftPressed = false;
bool buttonRightPressed = false;

void moveLeft();
void moveRight();

void setup(){
    game = new Game();
    uint8_t speed = 2;
    game->setSpeed(speed);
    // Buttons
    attachInterrupt(BUTTON_LEFT_IRQ, moveLeft, FALLING);
    attachInterrupt(BUTTON_RIGHT_IRQ, moveRight, FALLING);

    game->setInterface(GREEN);
}

void loop(){
    if (buttonLeftPressed){
        buttonLeftPressed = false;
        game->moveCatcherLeft();
    }
    if (buttonRightPressed){
        buttonRightPressed = false;
        game->moveCatcherRight();
    }
    game->refresh();
}

void moveLeft(){
    if (game->catcher.x0 - game->catcher.step >= 0)
        buttonLeftPressed = true;
}

void moveRight(){
    if (game->catcher.x0 + game->catcher.width + game->catcher.step - 1
        < game->display.width
    ){
        buttonRightPressed = true;
    }
}
