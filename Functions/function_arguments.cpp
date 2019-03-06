#include "function_arguments.h"
#include <iostream>
#include <QDebug>

int sumit(int num)
{
    int sum = 0;
    for (; num; --num)
    {
        sum += num;
    }
    return sum;
}

void testSumit(void)
{
    using namespace std;
    int n = 10;
    cout << n << endl;
    cout << sumit(n) << endl;
    cout << n << endl;
}

void messAround(int* ptr)
{
    *ptr = 34;
    ptr = 0;
}

void testMessAround(void)
{
    int n(12);
    int *pn = &n;
    std::cout << "n = " << n << "\tpn = " << pn << std::endl;
    messAround(pn);
    std::cout << "n = " << n << "\tpn = " << pn << std::endl;
}

void swap(int& a, int& b)
{
    int temp = a;
    std::cout << "Inside the swap() function:\n"
              << "address of a : " << &a << "\n"
              << "address of b : " << &b << "\n"
              << "address of temp : " << &temp << "\n"
              << std::endl;
    a = b;
    b = temp;
}

void testSwap(void)
{
    int n1 = 25;
    int n2 = 38;
    int n3 = 71;
    int n4 = 82;

    std::cout << "Initial values : \n"
              << "address of n1 : " << &n1 << "\n"
              << "address of n2 : " << &n2 << "\n"
              << "value of n1 : " << n1 << "\n"
              << "value of n2 : " << n2 << "\n\n"
              << "address of n3 : " << &n3 << "\n"
              << "address of n4 : " << &n4 << "\n"
              << "value of n3 : " << n3 << "\n"
              << "value of n4 : " << n4 << "\n"
              << "Making the first call to swap()\n" << std::endl;
    swap(n1, n2);
    std::cout << "After the first call to swap() : \n"
              << "address of n1 : " << &n1 << "\n"
              << "address of n2 : " << &n2 << "\n"
              << "value of n1 : " << n1 << "\n"
              << "value of n2 : " << n2 << "\n"
              << "Making the second call to swap()\n" << std::endl;
    swap(n3, n4);
    std::cout << "After the second call to swap() : \n"
              << "address of n3 : " << &n3 << "\n"
              << "address of n4 : " << &n4 << "\n"
              << "value of n3 : " << n3 << "\n"
              << "value of n4 : " << n4 << "\n" << std::endl;
}

void Person::setNameV(QString newName)
{
    newName += " Smith";
    m_Name = newName;
}

void Person::setNameCR(const QString &newName)
{
    // newName += " Python";
    m_Name = newName;
}

void Person::setNameR(QString &newName)
{
    newName += " Dobbs";
    m_Name = newName;
}

void testConstReference(void)
{
    Person p;
    QString name("Bob");
    p.setNameCR(name);
    // p.setNameR("Monty");    /* cannot bind non-const lvalue reference of type 'QString&' to an rvalue of type 'QString'. */
    p.setNameCR("Monty");
    p.setNameV("Connie");
    p.setNameV(name);
    qDebug() << name;
}

int& maxi(int& x, int& y)
{
#if 0
    int ret = ((x > y) ? x : y);
    return ret;     /* 错误警告：不要让函数返回一个指向临时局部对象的引用. */
#else
    return ((x > y) ? x : y);
#endif
}

void testMaxi(void)
{
    int a = 10, b = 20;
    maxi(a, b) = 5;
    maxi(a, b) += 6;
    ++maxi(a, b);
    std::cout << "a = " << a << ", \tb = " << b << std::endl;
}

/*================================================================================================*/

inline static double& zero(int index)
{
    static double _zero = 0.00;
    _zero = 0;
    std::cerr << "index out of bounds: " << index << std::endl;
    return _zero;
}
Point3D::Point3D(double x, double y, double z)
{
    m_Coordinate[0] = x;
    m_Coordinate[1] = y;
    m_Coordinate[2] = z;
}

double& Point3D::operator[](int index)
{
    if ((index >= 0) && (index < 3))
        return m_Coordinate[index];
    else
    {
        return zero(index);
    }
}

const double& Point3D::operator[](int index) const
{
    if ((index >= 0) && (index < 3))
        return m_Coordinate[index];
    else
        return zero(index);
}

std::ostream& operator<<(std::ostream& out, const Point3D& vertex)
{
    out << "(" << vertex[0] << ", " << vertex[1] << ", " << vertex[2] << ")";
    return out;
}

void testConstOverload(void)
{
    Point3D pt1(1.2, 3.4, 5.6);
    const Point3D pt2(7.8, 9.4, 0.65);
    double d;
    d = pt2[2];
    std::cout << d << std::endl;

    d = pt1[0];
    std::cout << d << std::endl;

    d = pt1[3];
    std::cout << d << std::endl;

    pt1[1] = 18.45;
    std::cout << pt1 << std::endl;

    // pt2[2] = 'd';       /* cannot assign to return value because function 'operator[]' returns a const value. */
    std::cout << pt2 << std::endl;
}
