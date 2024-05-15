#ifndef SPELL_H
#define SPELL_H
#include <string>
#include "./user.h"
#include "./enemy.h"
class Spell {
    private:
        std::string* spellClass;
        int spellLevelThreshold;
    public:
        Spell();
        Spell(const std::string& sc, int slt);

        ~Spell();

        std::string getSpellClass() const;
        int getSpellLevelThreshold() const;

        void setSpellClass(const std::string& sc);
        void setSpellLevelThreshold(int slt);

        virtual void doSpell(User*, enemy*) = 0;
};
#endif // SPELL_H