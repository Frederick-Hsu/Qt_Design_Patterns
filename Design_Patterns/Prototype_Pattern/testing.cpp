#include "testing.h"

#include "Resume.h"
#include "shadow_deep_copy.h"
#include "ResumePtr.h"

#include <iostream>
#include <cassert>
using namespace std;

void execute_test_items(void)
{
//    TestPointer();
//    cout << "\n" << endl;

//    TestResume();
//    cout << "\n" << endl;

//    TestResume2();
//    cout << "\n" << endl;

    TestResumePtr();
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

#if (COPY == DEEP_COPY)
    WorkExperience2* pworke = pclone->GetWorkExperience();
    if (pworke)
    {
        delete pworke;
        pworke = nullptr;
    }
#endif

    delete pclone;
    delete pworkexpr;
}

void TestPointer(void)
{
    int *a = new int(100);
    int *pA = a;
    int *pB = pA;       /* pA, pB and a, all of them pointed to a */

    delete a;
    a = NULL;

    assert(pA != NULL); /* although a had been freed, but the pointer pA value does not equal to NULL */
    pA = NULL;

    assert(pA == NULL);
    assert(pB != NULL);     /* pointer to a dynamically-allocated object, pointer itself was stored
                             * in stack, only the dynamically-allocated object was stored in heap.
                             */
}

void TestResumePtr(void)
{
    ResumePtr rs(new WorkExperience2("HelloBike", "2019/11 --- 2020/03"));
    rs.SetPersonalInfo("Jacky", "Male", 35);
    rs.PrintInfo();
    cout << endl;

    shared_ptr<ResumePtr> pclone(rs.Clone());
    pclone->SetPersonalInfo("Mary", "Female", 28);
    pclone->SetWorkExperience("Schindler", "2015/09 --- 2016/06");
    pclone->PrintInfo();
    cout << endl;

    shared_ptr<ResumePtr> pclone2(pclone->Clone());
    pclone2->SetPersonalInfo("Bjorn Cederberg", "Male", 42);
    pclone2->SetWorkExperience("Shanghai Amphenol Airwave", "2009/10 --- 2018/09");
    pclone2->PrintInfo();
    cout << endl;

    pclone->PrintInfo();    /* To check the deep-copy */
    cout << endl;
    rs.PrintInfo();         /* Print once again to observe whether deep-copy had succeeded */
    cout << endl;
}
