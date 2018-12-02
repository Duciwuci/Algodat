#include <iostream>
#include "CursorList.h"
#include "Student.h"

const int N = 10;

void addStudent(CursorList<Student, N> *list);

void searchWithMatrikel(CursorList<Student, N> list);

void deleteStudentWithMatrikelNumber(CursorList<Student, N> *list);

void testOtherFunctions(CursorList<Student, 3> list);

void listMen();

int main() {
    CursorList<Student, 10> list;
    CursorList<Student, 3> otherList;

    std::string answer = "";

    while(answer != "5") {
        std::cout << "Was wollen Sie tun? (Menüpunkte --> 0)" << std::endl;


        std::cin >> answer;

        switch (std::stoi(answer)) {
            case 0: listMen();
                break;
            case 1: addStudent(&list);
                break;
            case 2: searchWithMatrikel(list);
                break;
            case 3: deleteStudentWithMatrikelNumber(&list);
                break;
            case 4: testOtherFunctions(otherList);
                break;
            case 5: break;
            default: std::cout << answer << " ist kein Menüpunkt";
                break;
        }

        /*if (answer == "nein") {
            break;
        }
        searchWithMatrikel(list);*/
    }

    // TODO: teste alle anderen Methoden

    std::cout << "Programm beendet" << std::endl;
    return 0;
}

void addStudent(CursorList<Student, N> *list) {
    std::string prename;
    std::string name;
    std::string geburtstag;
    int matrikel;

    std::cout << "Name des Studenten" << std::endl;
    std::cin >> prename;
    std::cout << "Nachname des Studenten" << std::endl;
    std::cin >> name;
    std::cout << "Geburtstag des Studenten" << std::endl;
    std::cin >> geburtstag;
    std::cout << "Matrikel des Studenten" << std::endl;
    std::cin >> matrikel;

    Student newStudent = Student(prename, name, geburtstag, matrikel);

    list->push_front(newStudent);
}

void deleteStudentWithMatrikelNumber(CursorList<Student, N> *list) {
    std::cout << "Welchen Studenten soll ich löschen? (Matrikelnummer)" << std::endl;

    int answerMatrikel;
    std::cin >> answerMatrikel;
    bool found = false;

    CursorList<Student, N>::iterator findStudent = list->begin();

    while (findStudent.getIteratorIndex() != -1) {
        if (findStudent.operator*().GetMatrikelNr() == answerMatrikel) {
            found = true;
            break;
        }
        ++findStudent;
    }
    if (!found) {
        std::cout << "Ich konnte den Studenten mit der Matrikel Nummer '" << answerMatrikel << "' nicht finden" << std::endl;
    } else {
        list->erase(findStudent);
        std::cout << "Student gelöscht." << std::endl;
    }
}


void searchWithMatrikel(CursorList<Student, N> list) {
    std::cout << "Geben Sie mir eine Matrikelnummer, damit ich suchen kann" << std::endl;
    int answerMatrikel;
    std::cin >> answerMatrikel;
    bool found = false;
    Student founded;

    CursorList<Student, N>::iterator findStudent = list.begin();

    while (findStudent.getIteratorIndex() != -1) {
        if (findStudent.operator*().GetMatrikelNr() == answerMatrikel) {
            found = true;
            founded = findStudent.operator*();
            break;
        }
        ++findStudent;
    }
    if (!found) {
        std::cout << "Ich konnte den Studenten mit der Matrikel Nummer '" << answerMatrikel << "' nicht finden" << std::endl;
    } else {
        std::cout << founded << std::endl;
    }
}

void listMen() {
    std::cout << "Menü:" << std::endl;
    std::cout << " 0: Menü" << std::endl;
    std::cout << " 1: Add Student" << std::endl;
    std::cout << " 2: Search Student" << std::endl;
    std::cout << " 3: Delete Student" << std::endl;
    std::cout << " 4: Test Other Functions" << std::endl;
    std::cout << " 5: Exit Program" << std::endl;
}

void testOtherFunctions(CursorList<Student, 3> list) {

    Student Duc = Student("Duc", "Mai", "23.1.97", 34634345);
    Student Raphi = Student("Raphael", "Colberg", "12.09.1994", 1);
    Student Dani = Student("Daniel", "Pittroff", "10.01.1995", 5);
    Student Max = Student("Max", "Mustermann", "10.01.1994", 6);

    list.push_front(Raphi);

    list.push_front(Dani);

    list.push_front(Duc);

    //Student second = list.front();
    CursorList<Student, 3>::iterator first = list.begin();
    Student a;

    while(first.getIteratorIndex() != -1) {
        a = first.operator*();
        std::cout << a;
        ++first;
    }

    std::cout << "------Add Max to full List ";
    std::cout << "- So the first (Duc) will be replaced------" << std::endl;

    list.push_front(Max);

    CursorList<Student, 3>::iterator second = list.begin();

    while(second.getIteratorIndex() != -1) {
        a = second.operator*();
        std::cout << a;
        ++second;
    }

    std::cout << "------Pop the First one (Max)------" << std::endl;

    list.pop_front();

    CursorList<Student, 3>::iterator third = list.begin();

    while(third.getIteratorIndex() -1) {
        a = third.operator*();
        std::cout << a;
        ++third;
    }

    std::cout << "------Insert Max with iterator------" << std::endl;

    CursorList<Student, 3>::iterator it1 = list.insert(list.begin(), Max);

    while(it1.getIteratorIndex() != -1) {
        a = it1.operator*();
        std::cout << a;
        ++it1;
    }

    std::cout << "------Erase Raphael with iterator------" << std::endl;
    CursorList<Student, 3>::iterator tmp = list.end();
    CursorList<Student, 3>::iterator it2 = list.erase(tmp);

    while(it2.getIteratorIndex() != -1) {
        a = it2.operator*();
        std::cout << a;
        ++it2;
    }

    std::cout << "------Erase All Students of the List with the iterator------" << std::endl;

    CursorList<Student, 3>::iterator start = list.begin();
    CursorList<Student, 3>::iterator end = list.end();

    CursorList<Student, 3>::iterator empty = list.erase(start, end);

    std::cout << "Empty? " << list.empty() << std::endl;
    //std::cout << Raphi << std::endl;
    std::cout << list.front() << std::endl;
    std::cout << list.front() << std::endl;
}

