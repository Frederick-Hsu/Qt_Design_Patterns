#include "pointer_accessing_memory.h"
#include <QTextStream>

void newDeletePointers(void)
{
    QTextStream cout(stdout);

    const char tab = '\t';
    int n = 13;
    int* ip = new int(n + 3);
    double d = 3.14;
    double* dp = new double(d + 2.3);
    char c = 'K';
    char* cp = new char(c + 5);

    cout << *ip << tab << *dp << tab << *cp << endl;

    int* ip2 = ip;
    cout << ip << tab << ip2 << endl;

    *ip2 += 6;
    cout << *ip << endl;
    delete ip;
    cout << *ip2 << endl;
    cout << ip << tab << ip2 << endl;
}

void referenceVariable(void)
{
    QTextStream cout(stdout);

    int a = 10, b = 20;
    int& ra = a;        /* ra is an alias for a */
    cout << "a = " << a << "\t ra = " << ra << endl;

    ra = b;     /* this causes a to be assigned the value 20 */
    cout << "a = " << a << "\t ra = " << ra << "\t b = " << b << endl;

    /*=========================================================================*/

    const int c = 45;       /* c is a constant : its value is read-only. */
    const int& rc = c;      /* legal but probably not well usefull. */
    // rc = 10;                /* compiler error - constant data may not be changed. */
    cout << "c = " << c << "\t rc = " << rc << endl;
}

void constantPointerAndReference(void)
{
    QTextStream cout(stdout);

    char p = 'p';
    const char* x = &p;         /* x is a pointer to const char */
    cout << "p = " << p << "\t x = " << x << "\t *x = " << *x << "\t &p = " << &p << endl;

    char q = 'q';
    char* const y = &q;         /* y is a const pointer to char */
    cout << "q = " << q << "\t y = " << y << "\t *y = " << *y << "\t &q = " << &q << endl;

    char r = 'r';
    const char* const z = &r;   /* z is const pointer to a const char */
    cout << "r = " << r << "\t z = " << z << "\t *z = " << *z << "\t &r = " << &r << endl;
}
