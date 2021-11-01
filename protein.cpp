#include "protein.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Protein::Protein()
{
    Head = Tail = NULL;
}

Protein::~Protein()
{
    while (Head)
    {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
}

Protein::Protein(const Protein&P)
{
    Head = Tail = NULL;
    Count = 0;

    Node* temp = P.Head;

    while (temp != 0)
    {
        Add(*(temp->Prot));
        temp = temp->Next;
    }
}

int Protein::getCount()
{
    return Count;
}

AcidProt* Protein::IterPen(int index){
    Node* Itera = Head;
    for (int i = 0; i < Count-1; i++) {
        Itera = Itera->Next;
    }
    return Itera->Prot;
}

string* Protein::Show()
{
    string *mass = new string[100];
    int index = 0;
    Node* temp = Head;
    while (temp != NULL)
    {
        mass[index] = temp->Prot->getFullName();
        temp = temp->Next;
        index++;
    }
    return mass;
}

void Protein::DeleteOne(int index) {
    Node* temp = this->Head;
    for (int i = 0; i < index; i++) {
        temp = temp->Next;
    }
    if (temp->Next && !(temp->Prev)) {
        Node* PrevTemp = temp->Prev;
        temp->Next->Prev = PrevTemp;
        Head = temp->Next;
    }
    else {
        if (!(temp->Next)) {
            temp->Prev->Next = NULL;
            Tail = temp->Prev;
        }
        else {
            Node* PrevTemp = temp->Prev;
            temp->Next->Prev = PrevTemp;
        }
    }
    Count--;

}

void Protein::DeleteAll()
{
    Count = 0;
    Head = NULL;
    Tail = NULL;
}

void Protein::Add(AcidProt &New)
{
    Node* temp = new Node;
    temp->Next = NULL;
    temp->Prot = &New;

    if (Head != NULL)
    {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
        Count++;
    }
    else
    {
        temp->Prev = NULL;
        Head = Tail = temp;
        Count++;
    }
}

string Protein::Iter(int data)
{
    Node* Itera = Head;
    for (int i = 0; i < Count-1; i++) {
        Itera = Itera->Next;
    }
    return Itera->Prot->getFullName();
}

void Protein::Sum(Protein& Prot1, Protein& Prot2) {
    this->Head = Prot1.Head;
    Node* sec = Prot2.Head->Next;
    this->Tail = Prot1.Tail;
    this->Tail->Next = Prot2.Head->Next;
    Count += Prot2.getCount() - 1;
}

void Protein::importFromFile(std::string path)
{
    std::ifstream file;
    string Name;
    char Sname;
    int fileCount;
    int Type;
    file.open(path);
    file >> fileCount;
    if (file.is_open()) {
        int i = 0;
        while (i < fileCount && !file.eof()) {
                file >> Type;
                if (Type == 1) {
                    file >> Name;
                    this->Add(*(new AcidProt(Name)));
                }
                else {
                    file >> Name;
                    file >> Sname;
                    this->Add(*(new Acid(Name, Sname)));
                }
                i++;
        }
    }
    else {
        std::cout << "Файл не открылся!" << std::endl;
    }
    file.close();
}

void Protein::exportToFile(std::string path)
{
    std::ofstream file;
    file.open(path);
    Node* Iter = this->Head;
    file << this->Count << endl;
    for (int i = 0; i < Count; i++) {
        if (Iter->Prot->getType() == 1) {
            file << Iter->Prot->getFullName() << endl;
         }
        else {
            Acid* h = (Acid*)Iter->Prot;
            file << h->getFullName() << endl;
            file << h->getLetter() << endl;
        }
         Iter = Iter->Next;
    }
    file.close();
}
