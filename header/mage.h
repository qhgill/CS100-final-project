#include <string>
#include "character.h"
using std::string;

class Mage : public Character {
    public:
        Mage();
        Mage(int, int, int, int, string, spell*, spell*, spell*);
        
};