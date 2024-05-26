#include "./warrior.h"
#include "./bludgeon.h"
#include "./shatter.h"
#include "./slam.h"
#include <string>

Warrior::Warrior(int hp, int dmg, int pr, int mr, const std::string& cname, Spell* s1, Spell* s2, Spell* s3) 
: Character(hp, dmg, pr, mr, cname, s1, s2, s3) 
{}
Warrior::Warrior() 
: Character(15, 3, 1, 1, "Warrior", new Bludgeon(), new Shatter(), new Slam()) {}
