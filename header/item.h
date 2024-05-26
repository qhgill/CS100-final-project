#pragma once
#include <string>

class Item 
{
    protected:
        std::string name;
        std::string itemType;
        int level;
    public:
        Item();
        Item(std::string name, int level, std::string type);
        std::string getName();
        int getLevel();
        std::string getType();
        virtual int calcValue() = 0;
};