#include "SignatureDemo.h"
#include "../qstd/qstd.h"

SignatureDemo::SignatureDemo(int val) : m_Val(val)
{
}

void SignatureDemo::demo(int n)
{
    qstd::cout << ++m_Val << "\tdemo(int " << n << ")" << endl;
}

void SignatureDemo::demo(int n) const
{
    qstd::cout << m_Val << "\tdemo(int " << n << ") const" << endl;
}

#if defined (FUNCTION_OVERLOAD)
    void SignatureDemo::demo(const int& n)
    {
        qstd::cout << ++m_Val << "\tdemo(const int& " << n << ")" << endl;
    }
#endif

void SignatureDemo::demo(short s)
{
    qstd::cout << ++m_Val << "\tdmo(short " << s << ")" << endl;
}

void SignatureDemo::demo(float f)
{
    qstd::cout << "\tdemo(float " << f << ")" << endl;
}

void SignatureDemo::demo(float f) const
{
    qstd::cout << m_Val << "\tdemo(float " << f << ") const" << endl;
}

void SignatureDemo::demo(double d)
{
    qstd::cout << ++m_Val << "\tdemo(double " << d << ")" << endl;
}

void testSignatureDemoFunctionOveload(void)
{
    SignatureDemo sd(5);
    const SignatureDemo csd(17);

    sd.demo(2);
    csd.demo(2);

    int i = 3;
    sd.demo(i);

    short s = 5;
    sd.demo(s);
    csd.demo(s);

    sd.demo(2.3);
    float f(4.5);
    sd.demo(f);
    csd.demo(f);
    // csd.demo(4.5);
}
