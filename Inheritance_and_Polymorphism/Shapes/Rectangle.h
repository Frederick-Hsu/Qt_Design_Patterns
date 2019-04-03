#ifndef RECTANGLE_H
#define RECTANGLE_H

    #include "Shape.h"

    class Rectangle : public Shape
    {
    public:
        Rectangle(double height, double width);
    protected:
        double m_Height;
        double m_Width;
    public:
        double area();
        QString getName();
        QString getDimension();
    };

#endif  /* RECTANGLE_H */
