#include "enemy.h"
#include "statsManager.h"

class Orc : public Enemy
{
    public:
        virtual void calculateTurn(StatsManager* sm);
};
