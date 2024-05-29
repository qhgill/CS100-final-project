#pragma once
#include <string>
#include "item.h"

class Trinket : public Item 
{
    private:
        int pierce;
    public:
        Trinket();
        Trinket(const std::string& name, int level, int pierce);
        int getPierce();
        int calcValue();
};