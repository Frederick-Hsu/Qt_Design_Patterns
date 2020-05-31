#include "Resume.h"

#include <iostream>
using namespace std;

Resume::Resume() {}
Resume::~Resume()
{
    cout << "destruct the Resume." << endl;
}

void Resume::SetPersonalInfo(const string &name, const string &sex, int age)
{
    m_strName = name;
    m_strSex = sex;
    m_iAge = age;
}

void Resume::SetWorkExperience(const string &company, const string &worktime)
{
    m_WorkExperience.SetCompany(company);
    m_WorkExperience.SetWorkTime(worktime);
}

Resume* Resume::Clone()
{
    Resume* ptr_resume = new Resume;
    ptr_resume->SetPersonalInfo(m_strName, m_strSex, m_iAge);
    ptr_resume->SetWorkExperience(m_WorkExperience.GetCompany(), m_WorkExperience.GetWorkTime());
    return ptr_resume;
}

void Resume::PrintInfo()
{
    cout << "Name: " << m_strName << endl
         << "Sex: " << m_strSex << endl
         << "Age: " << m_iAge << endl
         << "Work experience: ";
    m_WorkExperience.PrintInfo();
    cout << "\n" << endl;
}
