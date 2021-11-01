#ifndef ACID_H
#define ACID_H
#include <string>
#include "acidprot.h"

using namespace std;

class Acid : public AcidProt {
public:
    Acid();
    Acid(string fullName, char letter);
    Acid(const Acid& other) = default;
    ~Acid();
    int getType() const override { return 2; }
    void setLetter(char letter);
    char getLetter()const;

private:
    char letter;
};

#endif // ACID_H
