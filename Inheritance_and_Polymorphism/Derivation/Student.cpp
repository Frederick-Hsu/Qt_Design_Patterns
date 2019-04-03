#include "Student.h"
#include "../../qstd/qstd.h"

Student::Student(QString nm, long id, QString major, int year) : m_Name(nm),
                                                                 m_Major(major),
                                                                 m_StudentId(id),
                                                                 m_Year(year)
{
#if defined (DEBUG_INDICATOR)
    qstd::cout << "Call the Student::Student() constructor." << endl;
#endif
}

Student::~Student()
{
#if defined (DEBUG_INDICATOR)
    qstd::cout << "Call the Student::~Student() destructor." << endl;
#endif
}

QString Student::getClassName() const
{
    return "Student";
}

QString Student::toString() const
{
    QString retval;
    QTextStream os(&retval);
    os << "[" << getClassName() << "]" << endl
       << "Name : " << m_Name << endl
       << "ID : " << m_StudentId << endl
       << "Year : " << yearStr() << endl
       << "Major : " << m_Major << endl;
    return retval;
}

QString Student::yearStr() const
{
    QString str;
    QTextStream os(&str);
    os << m_Year;
    return str;
}
