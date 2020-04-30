#ifndef WORK_EXPERIENCE_H
#define WORK_EXPERIENCE_H

    #include <string>
    using namespace std;

    class WorkExperience;
    template<class ElemType> class ICloneable;

    class WorkExperience
    {
    public:
        WorkExperience();
        WorkExperience(const string& company, const string& workTime);
        WorkExperience(const WorkExperience& other);
        WorkExperience& operator=(const WorkExperience& other);
        ~WorkExperience();
    public:
        void SetCompany(const string& company);
        const string& GetCompany() const;
        void SetWorkTime(const string& worktime);
        const string& GetWorkTime() const;
        void PrintInfo();
    private:
        string m_strCompany;
        string m_strWorkTime;
    };

    template<class ElemType> class ICloneable
    {
    public:
        virtual ElemType* Clone() = 0;
    };

#endif  /* WORK_EXPERIENCE_H */
