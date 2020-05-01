#include "shadow_deep_copy.h"

#include <iostream>
using namespace std;

Resume2::Resume2()
{
    m_WorkExperience = nullptr;
}

#if (COPY == SHADOW_COPY)
Resume2::Resume2(WorkExperience* pworkexp)
{
    m_WorkExperience = pworkexp;
}
#elif (COPY == DEEP_COPY)
Resume2::Resume2(WorkExperience2* pworkexp)
{
    m_WorkExperience = pworkexp->Clone();
}
#endif

Resume2::Resume2(const Resume2& other)
{
    m_strName = other.m_strName;
    m_strSex = other.m_strSex;
    m_iAge = other.m_iAge;
#if (COPY == SHADOW_COPY)
    /* Assign the pointer, shadow copy */
    m_WorkExperience = other.m_WorkExperience;
#elif (COPY == DEEP_COPY)
    /* deep copy */
    m_WorkExperience = other.m_WorkExperience->Clone();
#endif
}

Resume2::~Resume2()
{
    cout << "destruct Resume2" << endl;
}

void Resume2::SetPersonalInfo(const string &name, const string &sex, int age)
{
    m_strName = name;
    m_strSex = sex;
    m_iAge = age;
}

void Resume2::SetWorkExperience(const string &company, const string &worktime)
{
    m_WorkExperience->SetCompany(company);
    m_WorkExperience->SetWorkTime(worktime);
}

Resume2* Resume2::Clone()
{   /* call the copy constructor, shadown copy */
    Resume2* rsm = new Resume2(*this);
    return rsm;
}

void Resume2::PrintInfo()
{
    cout << "Name: " << m_strName << endl
         << "Sex: " << m_strSex << endl
         << "Age: " << m_iAge << endl
         << "Work experience: ";
    m_WorkExperience->PrintInfo();
    cout << "\n" << endl;
}

WorkExperience2::WorkExperience2(const string& company, const string& worktime)
{
    m_strCompany = company;
    m_strWorkTime = worktime;
}

WorkExperience2::WorkExperience2(const WorkExperience2& other)
{
    m_strCompany = other.m_strCompany;
    m_strWorkTime = other.m_strWorkTime;
}

WorkExperience2& WorkExperience2::operator=(const WorkExperience2 &other)
{
    m_strCompany = other.m_strCompany;
    m_strWorkTime = other.m_strWorkTime;
    return *this;
}

WorkExperience2::~WorkExperience2()
{
    cout << "destructs WorkExperience2" << endl;
    PrintInfo();
}

WorkExperience2* WorkExperience2::Clone()
{   /* deep copy */
    WorkExperience2* pclone = new WorkExperience2(*this);
    return pclone;
}

void WorkExperience2::SetCompany(const string &company)
{
    m_strCompany = company;
}

const string& WorkExperience2::GetCompany() const
{
    return m_strCompany;
}

void WorkExperience2::SetWorkTime(const string &worktime)
{
    m_strWorkTime = worktime;
}

const string& WorkExperience2::GetWorkTime() const
{
    return m_strWorkTime;
}

void WorkExperience2::PrintInfo()
{
    cout << "Company: " << m_strCompany << ", "
         << "Work time: " << m_strWorkTime
         << endl;
}
