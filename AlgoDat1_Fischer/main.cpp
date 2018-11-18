#include <iostream>
#include "CursorList.h"
#include "Student.h"

int main() {
    CursorList<Student, 10> list;
    Student Duc = Student("Duc", "Mai", "23.1.97", 34634345);
    Student Raphi = Student("Raphael", "Colberg", "12.09.1994", 1);
    Student Dani = Student("Daniel", "Pittroff", "10.01.1995", 5);
    list.push_front(Raphi);

    list.push_front(Dani);

    list.push_front(Duc);
    std::cout << list.front() << std::endl;
    std::cout << list.front() << std::endl;
    std::cout << list.front() << std::endl;
    return 0;
}