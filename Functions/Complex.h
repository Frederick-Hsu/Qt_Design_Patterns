#ifndef COMPLEX_H
#define COMPLEX_H

    #include <iostream>

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
        /* binary member function operators */
        Complex& operator+=(const Complex& cmp);
        Complex& operator-=(const Complex& cmp);

        Complex operator+(const Complex& cmp);
    private:
        double m_Real;
        double m_Imag;
    };

#endif  /* COMPLEX_H */
