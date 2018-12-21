# GeeGrow_ILI9341

This library is specially written to provide communication with board GeeGrow
2.4" SPI TFT 240x320 Display (ILI9341). The display can be purchased in our
store https://geegrow.ru . The board consists a jack for SD card, so there is
an implementation of appropriate functionality, which needs a separate library
for SD card SdFat (https://github.com/greiman/SdFat). Also there is an
implemented opportunity to create objects on the screen with simple management.

For more information you can visit https://github.com/geegrow/GeeGrow_ILI9341

--------------------------------------------------------------------

"___________________________________" <--   This is a place for very motivating
                                            and enthusiastic slogan!

Please visit our store https://geegrow.ru and check out for some cool stuff!



<!-- START COMPATIBILITY TABLE -->

## Compatibility

MCU                | Tested Works | Doesn't Work | Not Tested  | Notes
------------------ | :----------: | :----------: | :---------: | -----
Atmega328 @ 16MHz  |              |              |     X       |
Atmega328 @ 12MHz  |              |              |     X       |
Atmega32u4 @ 16MHz |      X       |              |             |  
ESP8266            |              |              |     X       |
Atmega2560 @ 16MHz |              |              |     X       |
ATSAM3X8E          |              |              |     X       |
ATSAM21D           |              |              |     X       |
Intel Curie @ 32MHz|              |              |     X       |
STM32F2            |              |              |     X       |

  * ATmega328 @ 16MHz : Arduino UNO
  * ATmega328 @ 12MHz : Adafruit Pro Trinket 3V
  * ATmega32u4 @ 16MHz : Arduino Leonardo, Arduino Micro, Arduino Yun, Geegrow DaVinci
  * ESP8266 :
  * ATmega2560 @ 16MHz : Arduino Mega
  * ATSAM3X8E : Arduino Due
  * ATSAM21D : Arduino Zero, M0 Pro

<!-- END COMPATIBILITY TABLE -->
