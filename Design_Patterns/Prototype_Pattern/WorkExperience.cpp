#include "WorkExperience.h"

#include <iostream>
using namespace std;

WorkExperience::WorkExperience()
{
    cout << "default constructor WorkExperience::WorkExperience()" << endl;
}

WorkExperience::WorkExperience(const string& company, const string& workTime)
{
    m_strCompany = company;
    m_strWorkTime = workTime;
}

WorkExperience::WorkExperience(const WorkExperience& other)
{
    m_strCompany = other.m_strCompany;
    m_strWorkTime = other.m_strWorkTime;
}

WorkExperience& WorkExperience::operator=(const WorkExperience &other)
{
    m_strCompany = other.m_strCompany;
    m_strWorkTime = other.m_strWorkTime;
    return *this;
}

WorkExperience::~WorkExperience()
{
    cout << "destruct WorkExperience." << endl;
    PrintInfo();
}

void WorkExperience::SetCompany(const string &company)
{
    m_strCompany = company;
}

const string& WorkExperience::GetCompany() const
{
    return m_strCompany;
}

void WorkExperience::SetWorkTime(const string &worktime)
{
    m_strWorkTime = worktime;
}

const string& WorkExperience::GetWorkTime() const
{
    return m_strWorkTime;
}

void WorkExperience::PrintInfo()
{
    cout << "Company: " << m_strCompany << ", Work time: " << m_strWorkTime << endl;
}
