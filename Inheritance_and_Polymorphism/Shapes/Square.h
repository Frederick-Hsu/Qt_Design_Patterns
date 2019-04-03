#ifndef SQUARE_H
#define SQUARE_H

    #include "Rectangle.h"

    class Square : public Rectangle
    {
    public:
        Square(double height);
        double area();
        QString getName();
        QString getDimension();
    };

#endif  /* SQUARE_H */
