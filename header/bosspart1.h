#include <./boss.h>

class BossPart1 : public Boss {
    public:
        BossPart1();
        virtual void calculatephase1turn(statsManager*) {return;};
        virtual void calculatephase2turn(statsManager*) {return;};
};