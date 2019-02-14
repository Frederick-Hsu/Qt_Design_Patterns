#include "Complex.h"

Complex::Complex(double real, double imag) : m_Real(real), m_Imag(imag)
{
}

Complex::Complex(const Complex& other)
{
    m_Real = other.m_Real;
    m_Imag = other.m_Imag;
}

Complex& Complex::operator=(const Complex& other)
{
    m_Real = other.m_Real;
    m_Imag = other.m_Imag;
    return *this;   /* If the returned type is object reference, you should "return *this;" */
}

Complex Complex::operator+(const Complex &cmp)
{
#if defined (FRIEND_OPERATOR_OVERLOAD)
    std::cout << "overload the non-friend operator +, member function. " << std::endl;
#endif
    return Complex(m_Real + cmp.m_Real, m_Imag + cmp.m_Imag);   /* If the returned type is object, you should "return object;" */
}

Complex& Complex::operator+=(const Complex& cmp)
{
#if defined (FRIEND_OPERATOR_OVERLOAD)
    std::cout << "overload the non-friend operator+=, member function." << std::endl;
#endif
    m_Real += cmp.m_Real;
    m_Imag += cmp.m_Imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& cmp)
{
#if defined (FRIEND_OPERATOR_OVERLOAD)
    std::cout << "overload the non-friend operator -=, member function." << std::endl;
#endif
    m_Real -= cmp.m_Real;
    m_Imag -= cmp.m_Imag;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Complex& cmp)
{
#if defined (FRIEND_OPERATOR_OVERLOAD)
    std::cout << "overload the friend operator <<, non-member function." << std::endl;
#endif
    out << "(" << cmp.m_Real << " + " << cmp.m_Imag << "i)";
    return out;
}

Complex operator+(const Complex& c1, const Complex& c2)
{
#if defined (FRIEND_OPERATOR_OVERLOAD)
    std::cout << "overload the friend operator +, non-member function." << std::endl;
#endif
    double real = c1.m_Real + c2.m_Real;
    double imag = c1.m_Imag + c2.m_Imag;
    return Complex(real, imag);
}

Complex operator-(const Complex& c1, const Complex& c2)
{
#if defined (FRIEND_OPERATOR_OVERLOAD)
    std::cout << "overload the friend operator -, non-member function." << std::endl;
#endif
    double real = c1.m_Real - c2.m_Real;
    double imag = c1.m_Imag - c2.m_Imag;
    return Complex(real, imag);
}

Complex operator*(const Complex& c1, const Complex& c2)
{
#if defined (FRIEND_OPERATOR_OVERLOAD)
    std::cout << "overload the friend operator *, non-member function." << std::endl;
#endif
    double real = c1.m_Real * c2.m_Real - c1.m_Imag * c2.m_Imag;
    double imag = c1.m_Real * c2.m_Imag + c1.m_Imag * c2.m_Real;
    return Complex(real, imag);
}

Complex operator/(const Complex& c1, const Complex& c2)
{
#if defined (FRIEND_OPERATOR_OVERLOAD)
    std::cout << "overload the friend operator /, non-member function." << std::endl;
#endif
    double denominator = c2.m_Real * c2.m_Real + c2.m_Imag * c2.m_Imag;
    double real = (c1.m_Real * c2.m_Real + c1.m_Imag * c2.m_Imag) / denominator;
    double imag = (c1.m_Imag * c2.m_Real - c1.m_Real * c2.m_Imag) / denominator;
    return Complex(real, imag);
}

void testOperatorOverload(void)
{
    Complex c1(3.4, 5.6), c2(7.8, 9.0);
    std::cout << c1 << " + " << c2 << " = " << c1 + c2 << std::endl;
    std::cout << c1 << " - " << c2 << " = " << c1 - c2 << std::endl;

    Complex c3 = c1 * c2;
    std::cout << c1 << " * " << c2 << " = " << c3 << std::endl;
    std::cout << c3 << " / " << c2 << " = " << c3 / c2 << std::endl;
    std::cout << c3 << " / " << c1 << " = " << c3 / c1 << std::endl;

    Complex c4 = c3 + c2;
    std::cout << "c4 = " << c4 << std::endl;
    Complex c5 = c3 + 1.4;
    std::cout << "c5 = " << c5 << std::endl;
    std::cout << 8.0 << " - " << c5 << " = " << (8.0 - c5) << std::endl;
    std::cout << 9.5 << " * " << c4 << " = " << (9.5 * c4) << std::endl;
}
