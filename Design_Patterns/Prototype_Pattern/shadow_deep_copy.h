#ifndef SHADOW_DEEP_COPY_H
#define SHADOW_DEEP_COPY_H

    #include "WorkExperience.h"
    #include "ICloneable.h"

    #define SHADOW_COPY     1
    #define DEEP_COPY       2
    #define COPY            DEEP_COPY


    class Resume2;
    class WorkExperience2;

    /* Shadow copy */
    class Resume2 : public ICloneable<Resume2>
    {
    private:
        string m_strName;
        string m_strSex;
        int m_iAge;
#if (COPY == SHADOW_COPY)
        WorkExperience* m_WorkExperience;   /* pointer is the aggregate mode */
#elif (COPY == DEEP_COPY)
        WorkExperience2* m_WorkExperience;
#endif
    private:
        Resume2();
    public:
#if (COPY == SHADOW_COPY)
        Resume2(WorkExperience* pworkexp);
#elif (COPY == DEEP_COPY)
        Resume2(WorkExperience2* pworkexp);
#endif
        Resume2(const Resume2& other);
        virtual ~Resume2();
    public:
        void SetPersonalInfo(const string& name, const string& sex, int age);
        void SetWorkExperience(const string& company, const string& worktime);
        Resume2* Clone() override;
        void PrintInfo();
#if (COPY == DEEP_COPY)
        WorkExperience2* GetWorkExperience();
#endif
    };

    /* Deep copy */
    class WorkExperience2 : public ICloneable<WorkExperience2>
    {
    public:
        WorkExperience2() {}
        WorkExperience2(const string& company, const string& worktime);
        WorkExperience2(const WorkExperience2& other);
        WorkExperience2& operator=(const WorkExperience2& other);
        virtual ~WorkExperience2();
    public:
        WorkExperience2* Clone() override;
        void SetCompany(const string& company);
        const string& GetCompany() const;
        void SetWorkTime(const string& worktime);
        const string& GetWorkTime() const;
        void PrintInfo();
    private:
        string m_strCompany;
        string m_strWorkTime;
    };

#endif  /* SHADOW_DEEP_COPY_H */
