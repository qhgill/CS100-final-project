#include <string>
using std::string;

class spellStub{
    int placeholder;
    void doSpell();
};

class Character {
    protected:
        int baseHP;
        int baseDamage;
        int basePhysicalResist;
        int baseMagicResist;
        string className;
        spellStub firstSpell;
        spellStub secondSpell;
        spellStub thirdSpell;
    public:
        Character();
        int getBaseHP();
        int getBaseDamage();
        int getBasePhysicalResist();
        int getBaseMagicResist();
        string getClassName();
        void useSpell(spellStub);
};