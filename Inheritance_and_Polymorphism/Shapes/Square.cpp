#include "Square.h"
#include <QString>

Square::Square(double height) : Rectangle(height, height)
{
}

double Square::area()
{
    return Rectangle::area();
}

QString Square::getName()
{
    return "Square";
}

QString Square::getDimension()
{
    return QString("Dimension : side length = %1").arg(m_Height);
}
