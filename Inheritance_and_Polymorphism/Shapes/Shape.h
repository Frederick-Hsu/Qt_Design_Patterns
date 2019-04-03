#ifndef SHAPE_H
#define SHAPE_H

    class QString;

    class Shape
    {
    public:
        virtual ~Shape();

        virtual double area() = 0;
        virtual QString getName() = 0;
        virtual QString getDimension() = 0;
    };

#endif  /* SHAPE_H */
