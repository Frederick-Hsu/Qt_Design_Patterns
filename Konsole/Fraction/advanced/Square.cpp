#include "Square.h"

Square::Square(int ulx, int uly, int lrx, int lry) : m_UpperLeft(ulx, uly),
                                                     m_LowerRight(lrx, lry)
{
}

Square::Square(const Point& ul, const Point& lr) : m_UpperLeft(ul), m_LowerRight(lr)
{
}

void manageSubObjects(void)
{
    Square sq1(3, 4, 5, 6);
    Point p1(1, 2), p2(4, 5);
    Square sq2(p1, p2);
}
