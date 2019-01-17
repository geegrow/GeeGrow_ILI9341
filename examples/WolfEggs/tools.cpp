#include "tools.h"

bool chance(uint8_t percent){
    if (percent > 50)
        return false;

    if (random(200) % (100/percent) == 1)
        return true;
    return false;
};
