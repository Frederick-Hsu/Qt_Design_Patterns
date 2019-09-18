#include "Position.h"
#include <sstream>

Position::Position(std::string name, std::string description) : m_Name(name),
                                                                m_Description(description)
{
}

Position::Position(const Position& pos)
{
    m_Name = pos.m_Name;
    m_Description = pos.m_Description;
}

Position& Position::operator=(const Position& pos)
{
    if (this != &pos)
    {
        m_Name = pos.m_Name;
        m_Description = pos.m_Description;
    }
    return *this;
}

std::string Position::toString()
{
    std::stringstream strbuf;
    strbuf << "Name : " << m_Name << "\nDescription : " << m_Description << std::endl;
    return strbuf.str();
}
