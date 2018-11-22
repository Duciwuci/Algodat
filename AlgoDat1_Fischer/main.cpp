#include <iostream>
#include "CursorList.h"
#include "Student.h"

void addStudent(CursorList<Student, 10> list);

void searchWithMatrikel(CursorList<Student, 10> list);

// TODO: Hier schreiben wir einfach die Aufgabe 5
int main() {
    /*Student Duc = Student("Duc", "Mai", "23.1.97", 34634345);
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
    std::cout << list.front() << std::endl;
    std::cout << list.front() << std::endl;*/
    CursorList<Student, 10> list;

    std::cout << "fügen Sie den ersten Studenten zu" << std::endl;

    addStudent(list);

    while(1) {
        std::cout << "Wollen Sie weitere Studenten hinzufügen? ja / nein" << std::endl;

        std::string answer;
        std::cin >> answer;
        if (answer == "nein") {
            break;
        }
        addStudent(list);
    }

    while(1) {
        std::cout << "Wollen Sie Studenten anhand von der Matrikelnummer suchen? ja / nein" << std::endl;

        std::string answer;
        std::cin >> answer;

        if (answer == "nein") {
            break;
        }
        searchWithMatrikel(list);
    }

    // TODO: teste alle anderen Methoden

    std::cout << "Programm beendet" << std::endl;
    return 0;
}

void addStudent(CursorList<Student, 10> list) {
    std::string prename;
    std::string name;
    std::string geburtstag;
    int matrikel;

    std::cout << "Name des Studenten" << std::endl;
    std::cin >> prename;
    std::cout << "Nachmane des Studenten" << std::endl;
    std::cin >> name;
    std::cout << "Geburtstag des Studenten" << std::endl;
    std::cin >> geburtstag;
    std::cout << "Matrikel des Studenten" << std::endl;
    std::cin >> matrikel;

    Student newStudent = Student(prename, name, geburtstag, matrikel);

    list.push_front(newStudent);
}

void searchWithMatrikel(CursorList<Student, 10> list) {
    std::cout << "Geben Sie mir eine Matrikelnummer, damit ich suchen kann" << std::endl;
    int answerMatrikel;
    std::cin >> answerMatrikel;
    bool found = false;
    Student founded;

    CursorList<Student, 10>::iterator findStudent = list.begin();
    for (int i = 0; i < 10; i++) {
        std::cout << findStudent.operator*().GetMatrikelNr() << std::endl;
        std::cout << answerMatrikel << std::endl;
        if(findStudent.operator*().GetMatrikelNr() == answerMatrikel) {
            found = true;
            founded = findStudent.operator*();
            break;
        }
        ++findStudent;
    }
    if(found) {
        std::cout << founded << std::endl;
    } else {
        std::cout << "nicht gefunden" << std::endl;
    }
}