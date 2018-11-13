#include <iostream>
#include "CursorList.h"
#include "Student.h"

int main() {
    CursorList<Student, 10> list;
    Student Duc = Student("Duc", "Mai", "23.1.97", 34634345);
    list.push_front(Duc);

    list.push_front(Duc);

    list.push_front(Duc);
    list.pop_front();
    list.pop_front();
    list.pop_front();
    std::cout << list.empty() << std::endl;
    return 0;
}