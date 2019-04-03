#include "Circle.h"
#include <cmath>
#include <QString>

using namespace std;

Circle::Circle(double radius) : m_Radius(radius)
{
}

double Circle::area()
{
    return (M_PI * m_Radius * m_Radius);
}

QString Circle::getName()
{
    return "Circle";
}

QString Circle::getDimension()
{
    return QString("Dimension : radius = %1").arg(m_Radius);
}
