#include <Geegrow_ILI9341.h>

#define LED   A0
#define RESET A3
#define DC    A1
#define WR    A4
#define CS    A2
Geegrow_ILI9341 *display = new Geegrow_ILI9341();
Geegrow_ILI9341_objectCircle *circle = display->createCircleObj();

void setup() {
  // put your setup code here, to run once:
  display->init(LED, RESET, DC, WR, CS);
  display->setRotation(ROTATION_UP);
  display->attachLibs(LIB_NUMBERS_ASCII | LIB_LETTERS_ASCII | LIB_SYMBOLS_ASCII | LIB_LETTERS_CYRILLIC);
  circle->setColorBG(BLACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  display->fillDisplay(BLACK);

  uint8_t inc = 5;
  for (uint16_t i = 0; i < 160; i += inc)
    display->drawLine(i, 0, 320 - i, 239, RED);
  for (uint16_t i = 160; i < 320; i += inc)
    display->drawLine(i, 0, 320 - i, 239, GREEN);
  for (uint16_t i = 0; i < 120; i += inc)
    display->drawLine(319, i, 0, 240 - i, YELLOW);
  for (uint16_t i = 120; i < 240; i += inc)
    display->drawLine(319, i, 0, 240 - i, BLUE);

  display->fillDisplay(WHITE);
  
  display->printStr("GEEGROW", 104, 104, 2, RED);
  delay(2000);
  display->printStr("Дисплей ILI9341.", 100, 150, 1, BLUE);
  display->printStr("Приятного использования!", 65, 170, 1, PURPLE);
  delay(5000);

  display->fillDisplay(BLACK);
  display->fillRect(0, 0, 40, 180, BLUE);
  display->fillRect(0, 230, 320, 10, BLUE);
  display->fillRect(40, 0, 200, 80, BLUE);
  display->fillRect(290, 0, 30, 240, BLUE);
  display->fillRect(90, 130, 150, 50, BLUE);

  circle->moveTo(25, 205, 20, YELLOW);
  for (uint16_t i = 0; i < 240/inc; i++)
    circle->moveRight(inc);
  for (uint16_t i = 0; i < 100/inc; i++)
    circle->moveUp(inc);
  for (uint16_t i = 0; i < 200/inc; i++)
    circle->moveLeft(inc);
  for (uint16_t i = 0; i < 100/inc; i++)
    circle->moveDown(inc);
  for (uint16_t i = 0; i < 200/inc; i++)
    circle->moveRight(inc);
  for (uint16_t i = 0; i < 180/inc; i++)
    circle->moveUp(inc);
}
