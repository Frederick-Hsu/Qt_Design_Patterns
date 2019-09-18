#ifndef DATE_H
#define DATE_H

    class Date
    {
    public:
        Date(int day = 0, int month = 0, int year = 0);
        void display(bool eoln = true) const;
    private:
        int m_Day;
        int m_Month;
        int m_Year;
    };

    void passOptionalArguments(void);

#endif  /* DATE_H */
