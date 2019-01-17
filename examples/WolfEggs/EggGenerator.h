#ifndef EGGGENERATOR_H
#define EGGGENERATOR_H

#include "Drawer.h"
#include "Egg.h"

class EggGenerator {
    public:
        EggGenerator();
        void tryLaunchEgg();
        uint8_t selectSlide();
        void update();
        void killAll();

        Egg *egg_list = nullptr;

    private:
        uint8_t previous_slide = 4;
        uint8_t eggs_pos = 0;
};



#endif /* EGGGENERATOR_H */
