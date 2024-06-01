#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../user.h"

class Screen {
    protected:
        std::string filename;
        User* currentUser;
    public:
        Screen(std::string dispFile, User* user);
        void displayFromFile();
        virtual Screen* processOption(int option, bool isRunning) = 0;
        virtual void displayScreen() = 0;
};