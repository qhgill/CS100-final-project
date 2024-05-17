#include "item.h"


class Trinket : public Item {
    private:
        int pierce;
    public:
        TTrinket(int pierce) : pierce(pierce) {};
        int getPierce() {return pierce};
        int calcValue(return pierce*level;);
};