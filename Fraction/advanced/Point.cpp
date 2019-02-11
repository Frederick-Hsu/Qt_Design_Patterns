#include "Point.h"
#include <QString>
#include <QTextStream>

Point::Point(int px, int py) : m_X(px), m_Y(py)
{
}

Point::Point(const Point& other) : m_X(other.m_X), m_Y(other.m_Y)
{
}

Point::~Point()
{
    QTextStream qout(stdout);
    qout << "point destroyed: (" << m_X << ", " << m_Y << ")" << endl;
}

void Point::set(int nx, int ny)
/* _Point_set_int_int(Point* this, int nx, int ny) */
{
    m_X = nx;
    m_Y = ny;
}

QString Point::toString() const
/* _Point_toString_string_const(const Point* this) */
{
    /* cannot assign to non-static data member with const member function 'toString'
     */
    // m_X = 5;
    m_Count++;
    return QString("[%1, %2]").arg(m_X).arg(m_Y);
}

void verifyHowConstMemberFunctionWorks(void)
{
    QTextStream qout(stdout);

    Point p(1, 1);
    const Point q(2, 2);
    p.set(4, 4);
    qout << p.toString() << endl;

    /* 'this' argument to member function 'set' has type 'const Point', but function is
     * not marked const.
     */
    // q.set(5, 5);     /* const object cannot call non-const member function */
}
