#ifndef SETTING_H
#define SETTING_H

#include <Tweak.h>
#include "Drawer.h"
#include "EggGenerator.h"

class Setting {
    public:
        static Setting& instance() {
            static Setting instance;
            return instance;
        }

        void drawInterface();
        void launchEggs();
        static void timerHandler();
        void ticksHandler();

        bool gotTick = false;

    private:
        Setting();
        ~Setting();

        EggGenerator *_generator = nullptr;

        Setting(const Setting&);
        Setting& operator=(Setting&);
};

#endif /* SETTING_H */
