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

Student::Student(std::string vor, std::string nach, std::string geb, int matrikel) {
    strncpy(prename, vor.c_str(),10);  //strncpy und c_str zur konvertierung des Strings.
    strncpy(surname, nach.c_str(),10);
    matrikelnr = matrikel;
    strncpy(birthday, geb.c_str(), 10);
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
    ostr << surname << ", " << prename << " - Birthday: " << birthday << " - Matrikel NR.: " << matrikelnr << std::endl;
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

