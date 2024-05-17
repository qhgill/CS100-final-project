#include "item.h"


class Trinket : public Item {
    private:
        int pierce;
    public:
        Trinket(int name, int level, int pierce) : name(name), level(level), pierce(pierce) {};
        int getPierce() {return pierce};
        int calcValue(return pierce*level;);
};