#include "Person.h"
#include <sstream>

Person::Person(std::string name) : m_Name(name), m_Position(name, ""), m_Employer(name, "")
{
    m_Emplyed = false;
    // m_Position = Position(name, "");     /* NOTICE : explicitly initializer is different from this */
    // m_Employer = Employer(name, "");     /*          assignment initializer.                       */
}

std::string Person::toString()
{
    std::stringstream strbuf;
    strbuf << "Name : " << m_Name << std::endl
           << "Employed : " << (m_Emplyed == true ? "true" : "false") << std::endl
           << "Position : " << m_Position.toString() << std::endl
           << "Employer : " << m_Employer.toString() << std::endl;
    return strbuf.str();
}

void Person::setPosition(Employer empl, Position pos)
{
    m_Position = pos;
    m_Employer = empl;
}

Position Person::getPositon()
{
    return m_Position;
}

Employer Person::getEmployer()
{
    return m_Employer;
}
