#include "Rectangle.h"
#include <QString>

Rectangle::Rectangle(double height, double width) : m_Height(height), m_Width(width)
{
}

double Rectangle::area()
{
    return (m_Height * m_Width);
}

QString Rectangle::getName()
{
    return "Rectangle";
}

QString Rectangle::getDimension()
{
    return QString("Dimension : height = %1, width = %2").arg(m_Height).arg(m_Width);
}
