#include <iostream>
#include "CursorList.h"
#include "Student.h"

int main() {
    CursorList<Student, 10> list;
    list.push_front(Student("Duc", "Mai", "23.1.97", 34634345));
    std::cout << list.front().GetMatrikelNr() << std::endl;
    return 0;
}