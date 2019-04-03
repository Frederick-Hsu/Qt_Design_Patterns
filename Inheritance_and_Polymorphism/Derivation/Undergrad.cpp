#include "Undergrad.h"
#include "../../qstd/qstd.h"

Undergrad::Undergrad(QString name,
                     long id,
                     QString major,
                     int year,
                     int sat) : Student(name, id, major, year), m_SAT(sat)
{
#if defined (DEBUG_INDICATOR)
    qstd::cout << "Call the Undergrad::Undergrad() constructor." << endl;
#endif
}

Undergrad::~Undergrad()
{
#if defined (DEBUG_INDICATOR)
    qstd::cout << "Call the Undergrad::~Undergrad() destructor." << endl;
#endif
}

QString Undergrad::getClassName() const
{
    return "Undergrad";
}

QString Undergrad::toString() const
{
    QString result;
    QTextStream os(&result);
    os << Student::toString()
       << "[SAT : " << m_SAT << "]"
       << endl;
    return result;
}
