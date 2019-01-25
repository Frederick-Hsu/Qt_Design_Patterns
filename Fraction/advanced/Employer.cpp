#include "Employer.h"
#include "Position.h"
#include "Person.h"
#include <sstream>

Employer::Employer(std::string name, std::string market) : m_Name(name), m_Market(market)
{
}

std::string Employer::toString()
{
    std::stringstream strbuf;
    strbuf << "Name : " << m_Name << "\nMarket : " << m_Market << std::endl;
    return strbuf.str();
}

Employer::Employer(const Employer& other)
{
    m_Name = other.m_Name;
    m_Market = other.m_Market;
}

Employer& Employer::operator=(const Employer &other)
{
    if (this != &other)
    {
        m_Name = other.m_Name;
        m_Market = other.m_Market;
    }
    return *this;
}

bool Employer::hire(Person &newHire, Position pos)
{
    return true;
}
