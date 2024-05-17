#pragma once
#include <string>
#include "./user.h"
using std::string;

class Screen {
    protected:
        string filename;
        User* currentUser;
    public:
        Screen(string dispFile, User* cUser);
        virtual Screen* processOption(int) = 0;
        virtual void displayScreen() = 0;
};