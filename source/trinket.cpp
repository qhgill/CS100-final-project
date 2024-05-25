#include "../header/trinket.h"

Trinket::Trinket() 
: Item("a", 0, "trinket"), pierce(0) 
{}
Trinket::Trinket(const std::string& name, int level, int pierce) : Item(name, level, "trinket"), pierce(pierce) 
{}
int Trinket::getPierce() 
{
    return pierce;
}
int Trinket::calcValue() 
{
    return pierce*level;
};