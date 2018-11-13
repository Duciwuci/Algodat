//
// Created by Reawelq on 08.11.2018.
//
#include <iostream>
#include <cstring>
#include <ostream>
#include <istream>
#include "Student.h"

using std::ostream;
using std::istream;

Student::Student() { }

Student::Student(char * prename, char * surname, char * birthday, int matrikelnr) {
    strcpy(this->prename, prename);
    strcpy(this->surname, surname);
    strcpy(this->birthday, birthday);
    this->matrikelnr = matrikelnr;
}

int Student::GetMatrikelNr() {
    return matrikelnr;
}

void Student::SetMatrikelNr(int matrikelnr) {
    this->matrikelnr = matrikelnr;
}

char* Student::GetPrename() {
    return prename;
}

void Student::SetPrename(char* prename) {
    strcpy(this->prename, prename);
}

char* Student::GetSurname() {
    return surname;
}

void Student::SetSurname(char * surname) {
    strcpy(this->surname, surname);
}

char* Student::GetBirthday() {
    return birthday;
}

void Student::SetBirthday(char * birthday) {
    strcpy(this->birthday, birthday);
}

void Student::read(istream& istr) {
    istr >> surname >> prename >> birthday >> matrikelnr;
}

void Student::write(ostream& ostr)const {
    ostr << surname << prename << birthday << matrikelnr;
}

ostream& operator << (ostream& ostr, const Student& stud) {
    stud.write(ostr);
    return ostr;
}

istream& operator >> (istream& istr, Student& stud) {
    stud.read(istr);
    return istr;
}

bool operator== (const Student &a, const Student &b) { return a.matrikelnr == b.matrikelnr; }
bool operator< (const Student &a, const Student &b) { return a.matrikelnr < b.matrikelnr; }

bool operator!= (const Student &a, const Student &b) { return !operator==(*&a, *&b); }
bool operator> (const Student &a, const Student &b) { return !operator<(*&a, *&b); }
bool operator<= (const Student &a, const Student &b) { return !operator>(*&a, *&b); }
bool operator>= (const Student &a, const Student &b) { return !operator<(*&a, *&b); }

