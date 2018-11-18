//
// Created by Reawelq on 08.11.2018.
//
#include <iostream>
#include <cstring>
#include <ostream>
#include <istream>
using std::ostream;
using std::istream;

class Student {

    int matrikelnr;
    char prename [10];
    char surname [10];
    char birthday [9];

public:

    friend bool operator== (const Student &a, const Student &b);
    friend bool operator< (const Student &a, const Student &b);

    friend bool operator!= (const Student &a, const Student &b);
    friend bool operator> (const Student &a, const Student &b);
    friend bool operator<= (const Student &a, const Student &b);
    friend bool operator>= (const Student &a, const Student &b);

    friend istream& operator >> (istream& istr, Student& stud);
    friend ostream& operator << (ostream& ostr, const Student& stud);

    void write(ostream& ostr)const;
    void read(istream& istr);

    Student(char * prename, char * surname, char * birthday, int matrikelnr);

    Student();
    int GetMatrikelNr();
    void SetMatrikelNr(int matrikelnr);
    char * GetPrename();
    void SetPrename(char* prename);
    char * GetSurname();
    void SetSurname(char* surname);
    char * GetBirthday();
    void SetBirthday(char* birthday);
};



