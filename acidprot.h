#ifndef ACIDPROT_H
#define ACIDPROT_H
#include <string>
using namespace std;

class AcidProt
{
public:
    AcidProt();
    AcidProt(string fullName);
    AcidProt(const AcidProt& other) = default;
    inline string getFullName() const { return fullName; }
    void setFullName(string fullName);
    ~AcidProt();
    virtual int getType() const { return 1; }
private:
    string fullName;
};

#endif // ACIDPROT_H
