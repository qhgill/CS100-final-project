#include <iostream>
#include "./enemy.h"
#include "./statsManager.h"

using namespace std;

class Boss : public Enemy{
    public:
        Boss() : Enemy(0, 0, 0, 0, 0, 0, false, "") {};
        virtual void calculatephase1turn(statsManager*) = 0;
        virtual void calculatephase2turn(statsManager*) = 0;
};