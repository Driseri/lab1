#ifndef PROTEIN_H
#define PROTEIN_H
#include "acidprot.h"
#include "acid.h"

struct Node
{
    AcidProt *Prot;
    Node* Next, * Prev;
};

class Protein
{
private:
    int Count = 0;
    Node* Head, * Tail;
public:
    Protein();
    ~Protein();
    Protein(const Protein&);
    int getCount();
    string* Show();
    void Add(AcidProt &New);
    void DeleteOne(int index);
    void DeleteAll();
    string Iter(int data);
    void importFromFile(std::string path);
    void exportToFile(std::string path);
    void Sum(Protein &Prot1, Protein &Prot2);
    AcidProt* IterPen(int index);
};
#endif // PROTEIN_H
