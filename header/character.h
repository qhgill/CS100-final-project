#include <string>
using std::string;

class spell{ //stub
    public:
        void doSpell();
        spell(){}
};

class Character {
    protected:
        int baseHP;
        int baseDamage;
        int basePhysicalResist;
        int baseMagicResist;
        string className;
        spell* firstSpell;
        spell* secondSpell;
        spell* thirdSpell;
    public:
        Character(int, int, int, int, string, spell*, spell*, spell*);
        Character();
        int getBaseHP();
        int getBaseDamage();
        int getBasePhysicalResist();
        int getBaseMagicResist();
        string getClassName();
        void useSpell(spell*);
};