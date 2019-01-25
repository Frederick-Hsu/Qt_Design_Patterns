#ifndef POINT_H
#define POINT_H

    class QString;

    class Point
    {
    public:
        Point(int px, int py);
        Point(const Point& other);
        ~Point();
        void set(int nx, int ny);
        QString toString() const;
    private:
        int m_X;
        int m_Y;
        mutable int m_Count;    /* this member can be changed in the const member function */
    };

    void verifyHowConstMemberFunctionWorks(void);

#endif  /* POINT_H */
