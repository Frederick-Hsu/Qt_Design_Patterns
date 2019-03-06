#ifndef FUNCTION_ARGUMENTS_H
#define FUNCTION_ARGUMENTS_H

    #include <QString>

    /* 按值传递参数 */
    int sumit(int num);
    void testSumit(void);

    /* 按指针传递参数 */
    void messAround(int* ptr);
    void testMessAround(void);

    /* 按引用传递参数 */
    void swap(int& a, int& b);
    void testSwap(void);

    /* const引用 */
    class Person
    {
    public:
        void setNameV(QString newName);
        void setNameCR(const QString& newName);
        void setNameR(QString& newName);
    private:
        QString m_Name;
    };
    void testConstReference(void);

    /* 从函数返回引用 */
    int& maxi(int& x, int& y);
    void testMaxi(void);

    /* 对const重载 */
    class Point3D
    {
    public:
        friend std::ostream& operator<<(std::ostream& out, const Point3D& vertex);

        Point3D(double x = 0, double y = 0, double z = 0);
        double& operator[](int index);
        const double& operator[](int index) const;

        Point3D operator+(const Point3D& vertex) const;
        Point3D operator-(const Point3D& vertex) const;
        Point3D operator*(double s) const;
    private:
        static const int cm_Dim = 3;
        double m_Coordinate[cm_Dim];
    };
    void testConstOverload(void);

#endif  /* FUNCTION_ARGUMENTS_H */
