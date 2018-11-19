#include <iostream>
#include "CursorList.h"
#include "Student.h"


// TODO: Hier schreiben wir einfach die Aufgabe 5
int main() {
    CursorList<Student, 3> list;
    Student Duc = Student("Duc", "Mai", "23.1.97", 34634345);
    Student Raphi = Student("Raphael", "Colberg", "12.09.1994", 1);
    Student Dani = Student("Daniel", "Pittroff", "10.01.1995", 5);
    Student Max = Student("Max", "Mustermann", "10.01.1995", 6);

    list.push_front(Raphi);

    list.push_front(Dani);

    list.push_front(Duc);

    //Student second = list.front();
    CursorList<Student, 3>::iterator first = list.begin();
    Student a = first.operator*();

    for (int i = 0; i < 3; i++) {
        std::cout << a;
        ++first;
        a = first.operator*();
    }

    std::cout << "------Add Max to full List ";
    std::cout << "- So the first (Duc) will be replaced------" << std::endl;

    list.push_front(Max);

    CursorList<Student, 3>::iterator second = list.begin();
    a = second.operator*();

    for (int i = 0; i < 3; i++) {
        std::cout << a;
        ++second;
        a = second.operator*();
    }

    std::cout << "------Pop the First one (Max)------" << std::endl;

    list.pop_front();

    CursorList<Student, 3>::iterator third = list.begin();
    a = third.operator*();

    for (int i = 0; i < 2; i++) {
        std::cout << a;
        ++third;
        a = third.operator*();
    }

    std::cout << "------Insert Max with iterator------" << std::endl;

    CursorList<Student, 3>::iterator it1 = list.insert(list.begin(), Max);

    a = it1.operator*();

    for (int i = 0; i < 3; i++) {
        std::cout << a;
        ++it1;
        a = it1.operator*();
    }

    std::cout << "------Erase Raphael with iterator------" << std::endl;
    CursorList<Student, 3>::iterator tmp = list.end();
    CursorList<Student, 3>::iterator it2 = list.erase(tmp);
    a = it2.operator*();

    for (int i = 0; i < 3; i++) {
        std::cout << a;
        ++it2;
        a = it2.operator*();
    }

    std::cout << "------Erase All Students of the List with the iterator------" << std::endl;

    CursorList<Student, 3>::iterator start = list.begin();
    CursorList<Student, 3>::iterator end = list.end();

    CursorList<Student, 3>::iterator empty = list.erase(start, end);

    std::cout << "Empty? " << list.empty() << std::endl;
    //std::cout << Raphi << std::endl;
    /*std::cout << list.front() << std::endl;
    std::cout << list.front() << std::endl;*/
    return 0;
}