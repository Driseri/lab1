#include "acid.h"

Acid::Acid()
{
        this->letter = ' ';
}

Acid::Acid(string fullName, char letter) {
    this->setFullName(fullName);
    this->letter = letter;
}

Acid::~Acid()
{
    //Это должен быть деструктор
}

void Acid::setLetter(char letter)
{
    this->letter = letter;
}

char Acid::getLetter()const
{
    return letter;
}
