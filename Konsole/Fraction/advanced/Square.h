#ifndef SQUARE_H
#define SQUARE_H

    #include "Point.h"      /* If there is Point data member, non Point pointer data member,
                             * you must include the "Point.h" header file.
                             * Only the data member is pointer object, you can use forward class declaration
                             * class Point;
                             */
    class Square
    {
    public:
        Square(int ulx, int uly, int lrx, int lry);
        Square(const Point& ul, const Point& lr);
    private:
        Point m_UpperLeft;
        Point m_LowerRight;
    };

    void manageSubObjects(void);

#endif  /* SQUARE_H */
