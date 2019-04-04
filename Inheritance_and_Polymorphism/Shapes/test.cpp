#include "test.h"
#include <QDebug>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Bank.h"

static QTextStream cout(stdout);

void showNameAndArea(Shape* pshp)
{
    qDebug() << pshp->getName() << ", \t"
             << pshp->getDimension() << ", \t"
             << "area = " << pshp->area()
             << endl;
}

void executeTestCases(void)
{
    testCase_verifyPolymorphism();
    cout << "\n" << endl;
    testCase_verifyCopyAssignConstructor();
}

void testCase_verifyPolymorphism(void)
{
    // Shape shp;
    Rectangle rectangle(4.0, 5.5);
    Square square(8.0);
    Circle circle(6.4);

    qDebug() << "This program uses hierarchies for Shapes";
    showNameAndArea(&rectangle);
    showNameAndArea(&square);
    showNameAndArea(&circle);
}

void testCase_verifyCopyAssignConstructor()
{
    testBank();
}
