#include "../header/item.h"
Item::Item() : name(""), level(1), itemType(""){}
Item::Item(string name, int level, string type) : name(name), level(level), itemType(type) {}