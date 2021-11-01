#include "acidprot.h"

AcidProt::AcidProt()
{
    this->fullName = "";
}

AcidProt::AcidProt(string fullName) :
    fullName(fullName){}

void AcidProt::setFullName(string fullName) {
    AcidProt::fullName = fullName;
}

AcidProt::~AcidProt()
{
    //Это должен быть деструктор
}
