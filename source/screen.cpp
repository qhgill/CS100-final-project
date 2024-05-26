#include "../header/screens/screen.h"

Screen::Screen(std::string dispFile, User* user)
: filename(dispFile), currentUser(user)
{}

void Screen::displayFromFile()
{
    std::ifstream fileStream("./source/res/" + this->filename);
    if (!fileStream) {
        std::cerr << "Error opening file: " << this->filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fileStream, line)) {
        std::cout << line << std::endl;
    }

    fileStream.close();
}