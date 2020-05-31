#ifndef RESUME_H
#define RESUME_H

    #include "WorkExperience.h"
    #include "ICloneable.h"

    class Resume;

    class Resume : public ICloneable<Resume>
    {
    public:
        Resume();
        virtual ~Resume();
    public:
        void SetPersonalInfo(const string& name, const string& sex, int age);
        void SetWorkExperience(const string& company, const string& worktime);
        Resume* Clone() override;
        void PrintInfo();
    private:
        string m_strName;
        string m_strSex;
        int m_iAge;

        WorkExperience m_WorkExperience;
    };

#endif  /* RESUME_H */
