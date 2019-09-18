#ifndef COMPLEX_H
#define COMPLEX_H

    #include <iostream>

    // #define FRIEND_OPERATOR_OVERLOAD    1

    class Complex
    {
        /* binary non-member friend function declaration */
        friend std::ostream& operator<<(std::ostream& out, const Complex& cmp);
        friend Complex operator+(const Complex& c1, const Complex& c2);
        friend Complex operator-(const Complex& c1, const Complex& c2);
        friend Complex operator*(const Complex& c1, const Complex& c2);
        friend Complex operator/(const Complex& c1, const Complex& c2);

    public:
        Complex(double real = 0.0, double imag = 0.0);
        Complex(const Complex& other);
        Complex& operator=(const Complex& other);

        /* binary member function operators */
        Complex& operator+=(const Complex& cmp);
        Complex& operator-=(const Complex& cmp);

        Complex operator+(const Complex& cmp);
    private:
        double m_Real;
        double m_Imag;
    };

    void testOperatorOverload(void);

#endif  /* COMPLEX_H */
