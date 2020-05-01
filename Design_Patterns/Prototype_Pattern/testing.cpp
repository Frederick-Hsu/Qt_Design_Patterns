#include "testing.h"

#include "Resume.h"
#include "shadow_deep_copy.h"

#include <iostream>
using namespace std;

void execute_test_items(void)
{
    TestResume();
    cout << "\n" << endl;

    TestResume2();
    cout << "\n" << endl;
}

void TestResume(void)
{
    Resume rs;
    rs.SetPersonalInfo("Frederique Hsu", "Male", 37);
    rs.SetWorkExperience("Shanghai Amphenol Airwave", "2016/09 --- 2019/09");
    rs.PrintInfo();

    Resume* pclone = rs.Clone();
    pclone->SetPersonalInfo("Lily Luo", "Female", 35);
    pclone->SetWorkExperience("Shanghai Amphenol Airwave", "2016/11 --- Present");
    pclone->PrintInfo();

    delete pclone;
}

void TestResume2(void)
{
#if (COPY == SHADOW_COPY)
    WorkExperience* pworkexpr = new WorkExperience("Hella Shanghai Electronics", "2011/10 --- Present");
    Resume2 resume(pworkexpr);
#elif (COPY == DEEP_COPY)
    WorkExperience2* pworkexpr = new WorkExperience2("Hella Shanghai Electronics", "2011/10 --- Present");
    Resume2 resume(pworkexpr);
#endif
    resume.SetPersonalInfo("Henry Xing", "Male", 45);
    resume.PrintInfo();

    Resume2 *pclone = resume.Clone();

    pclone->SetPersonalInfo("Kevin Shan", "Male", 38);
    pclone->SetWorkExperience("Hella", "2011/08 --- 2019/05");
    pclone->PrintInfo();

    resume.PrintInfo();

    delete pclone;
    delete pworkexpr;
}
