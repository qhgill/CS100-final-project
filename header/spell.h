#ifndef SPELL_H
#define SPELL_H
#include <string>

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

        virtual void doSpell() = 0;
};
#endif // SPELL_H