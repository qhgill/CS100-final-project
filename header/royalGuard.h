#include "./enemy.h"
#include "./statsManager.h"

class RoyalGuard {
    public:
        RoyalGuard();
        RoyalGuard(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isdead, std::string name);

        void calculateTurn(StatsManager*);
};