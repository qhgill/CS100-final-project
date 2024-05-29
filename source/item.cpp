#include "../header/item.h"

Item::Item() 
: name(""), level(1), itemType("")
{}
Item::Item(std::string name, int level, std::string type)
: name(name), level(level), itemType(type) 
{}
std::string Item::getName() 
{
    return name;
}
int Item::getLevel() 
{
    return level;
}
std::string Item::getType() 
{
    return itemType;
}