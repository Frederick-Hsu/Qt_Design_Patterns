#ifndef DATE_H
#define DATE_H

    #include <string>

    class Date
    {
    private:
        int m_DaysSinceBaseDate;
    public:
        Date();
        Date(int year, int month, int day);
        void set(int year, int month, int day);
        std::string toString(bool brief);
        void setToToday();
        std::string getWeekDay();
        bool equals(const Date& date);
        Date addDays(int days);
        static bool leapYear(int year);
        static std::string monthName(int month);
        static int yearDays(int year);
        static int monthDays(int month, int year);
    private:
        static int ymd2dsbd(int year, int month, int day);
        void getYMD(int& year, int& month, int& day);
    };

#endif  /* DATE_H */
