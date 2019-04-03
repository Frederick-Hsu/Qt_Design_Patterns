#include "GradStudent.h"
#include "../../qstd/qstd.h"

QString GradStudent::supportStr(Support sup)
{
    switch (sup)
    {
    case TA:
        return "Teaching assistant";
    case RA:
        return "Research assistant";
    case FellowShip:
        return "Fellow";
    default:
        return "Others";
    }
}

GradStudent::GradStudent(QString nm,
                         long id,
                         QString major,
                         int yr,
                         Support support) : Student(nm, id, major, yr), m_Support(support)
{
#if defined (DEBUG_INDICATOR)
    qstd::cout << "Call the GradStudent::GradStudent() constructor." << endl;
#endif
}

GradStudent::~GradStudent()
{
#if defined (DEBUG_INDICATOR)
    qstd::cout << "Call the GradStudent::~GradStudent() destructor." << endl;
#endif
}

QString GradStudent::getClassName() const
{
    return "GradStudent";
}

QString GradStudent::toString() const
{
    return QString("%1%2%3]\n").arg(Student::toString())
                                    .arg("[Support : ")
                                    .arg(supportStr(m_Support));
}
