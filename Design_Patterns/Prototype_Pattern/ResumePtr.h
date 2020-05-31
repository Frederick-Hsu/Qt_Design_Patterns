#ifndef RESUME_PTR_H
#define RESUME_PTR_H

    #include "ICloneable.h"
    #include "shadow_deep_copy.h"

    #include <memory>
    using namespace std;

    class ResumePtr;

    class ResumePtr : public ICloneable<ResumePtr>
    {
    protected:
        string m_strName;
        string m_strSex;
        int m_iAge;
        shared_ptr<WorkExperience2> m_workexpr2;
    private:
        ResumePtr();
    public:
        virtual ~ResumePtr();
        ResumePtr(WorkExperience2* pworkexpr);
        ResumePtr(const ResumePtr& other);
        ResumePtr& operator=(const ResumePtr& other);
    public:
        ResumePtr* Clone() override;
        void SetPersonalInfo(const string& name, const string& gender, int age);
        void SetWorkExperience(const string& company, const string& worktime);
        void PrintInfo();
    };

#endif  /* RESUME_PTR_H */
