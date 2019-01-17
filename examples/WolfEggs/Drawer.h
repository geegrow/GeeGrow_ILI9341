#ifndef DRAWER_H
#define DRAWER_H

#include <GeeGrow_ILI9341.h>
#include <avr/pgmspace.h>
#include "tools.h"

#undef  SWAP_WR(num)
#define SWAP_WR(num)    {   PORTF &= ~_BV(PF1); \
                            __asm__("nop\n\t"); \
                            PORTF |= _BV(PF1);  \
                        }

class Drawer : public GeeGrow_ILI9341{
    public:
        static Drawer& instance() {
            static Drawer instance;
            return instance;
        }

        void writeMemoryCustom(uint8_t pos, const uint8_t *_buf, uint8_t raws, uint8_t columns);
        void castSelectedRangeCustom(int16_t _x0, int16_t _y0, int16_t _x1, int16_t _y1);

    private:
        Drawer();
        ~Drawer();
        Drawer(const Drawer&);
        Drawer& operator=(Drawer&);
};

#endif /* DRAWER_H */
