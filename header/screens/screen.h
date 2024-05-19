#pragma once
#include <string>
#include <fstream>
#include "./user.h"
using std::string;

class Screen {
    protected:
        string filename;
        User* currentUser;
    public:
        Screen(string dispFile, User* user);
        void displayFromFile();
        virtual Screen* processOption(int option, bool isRunning) = 0;
        virtual void displayScreen() = 0;
};