#include "student_test.h"
#include "Student.h"
#include "Undergrad.h"
#include "GradStudent.h"
#include "../../qstd/qstd.h"

void finish(Student* student)
{
    qstd::cout << "\nThe following " << student->getClassName() << " has applied for graduation.\n"
               << student->toString() << "\n" << endl;
}


void testCase_Execute(void)
{
    Undergrad us("Frodo Baggins", 5562, "Ring theory", 2014, 1220);
    GradStudent gs("Bilbo Baggins", 3029, "History", 2016, GradStudent::FellowShip);
    qstd::cout << "Here is the data for two students:\n";
    qstd::cout << gs.toString() << endl;
    qstd::cout << us.toString() << endl;
    qstd::cout << "\nHere is what happens when they finish their studies:\n";
    finish(&us);
    finish(&gs);
}
