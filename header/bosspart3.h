#include <./boss.h>

class BossPart3 : public Boss{
    public:
        virtual void calculatephase1turn(statsManager*) {return;};
        virtual void calculatephase2turn(statsManager*) {return;};
};