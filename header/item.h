#pragma once

class Item 
{
    protected:
        std::string name;
        std::string itemType;
        int level;
    public:
        Item();
        Item(std::string name, int level, std::string type);
        std::string getName() {return name;}
        int getLevel() {return level;}
        std::string getType() {return itemType;}
        virtual int calcValue() = 0;
};