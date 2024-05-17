#include <string>
#include "character.h"
using std::string;

class Warrior : public Character {
    public:
        Warrior();
        Warrior(int, int, int, int, string, spell*, spell*, spell*);    
};