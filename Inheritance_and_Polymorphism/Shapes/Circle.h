#ifndef CIRCLE_H
#define CIRCLE_H

    #include "Shape.h"

    class Circle : public Shape
    {
    public:
        Circle(double radius);
    private:
        double m_Radius;
    public:
        double area();
        QString getName();
        QString getDimension();
    };

#endif  /* CIRCLE_H */
