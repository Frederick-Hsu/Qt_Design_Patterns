#include "Date.h"
#include <QDate>
#include <iostream>

Date::Date(int day, int month, int year) : m_Day(day), m_Month(month), m_Year(year)
{
    static QDate currentDate = QDate::currentDate();

    if (m_Day == 0)
        m_Day = currentDate.day();
    if (m_Month == 0)
        m_Month = currentDate.month();
    if (m_Year == 0)
        m_Year = currentDate.year();
}

void Date::display(bool eoln) const
{
    std::cout << m_Year << "/" << m_Month << "/" << m_Day << std::endl;
    if (eoln)
        std::cout << std::endl;
}

void passOptionalArguments(void)
{
    Date d1;
    Date d2(15);
    Date d3(23, 9);
    Date d4(19, 12, 2018);

    d1.display(false);
    std::cout << "\t";
    d2.display();
    d3.display(false);
    std::cout << "\t";
    d4.display();
}
