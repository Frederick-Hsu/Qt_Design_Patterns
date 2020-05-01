#include "ResumePtr.h"

ResumePtr::ResumePtr() {}

ResumePtr::ResumePtr(WorkExperience2* pworkexpr)
{
    m_workexpr2.reset(pworkexpr);
}

ResumePtr::ResumePtr(const ResumePtr& other)
{
    m_strName = other.m_strName;
    m_strSex = other.m_strSex;
    m_iAge = other.m_iAge;
    /* deep copy, move the ownership of m_workexpr2 pointer */
    m_workexpr2.reset(other.m_workexpr2->Clone());
}

ResumePtr::~ResumePtr()
{
    cout << "ResumePtr's name: " << m_strName << endl
         << "Destruct this ResumePtr" << endl;
}

ResumePtr& ResumePtr::operator=(const ResumePtr &other)
{
    m_strName = other.m_strName;
    m_strSex = other.m_strSex;
    m_iAge = other.m_iAge;
    m_workexpr2.reset(other.m_workexpr2->Clone());
    return *this;
}

ResumePtr* ResumePtr::Clone()
{
    ResumePtr* one = new ResumePtr(*this);
    return one;
}

void ResumePtr::SetPersonalInfo(const string &name, const string &gender, int age)
{
    m_strName = name;
    m_strSex = gender;
    m_iAge = age;
}

void ResumePtr::SetWorkExperience(const string &company, const string &worktime)
{
    m_workexpr2->SetCompany(company);
    m_workexpr2->SetWorkTime(worktime);
}

void ResumePtr::PrintInfo()
{
    cout << "Name: " << m_strName << ", " << endl
         << "Gender: " << m_strSex << ", " << endl
         << "Age: " << m_iAge << ", " << endl;
    m_workexpr2->PrintInfo();
}
