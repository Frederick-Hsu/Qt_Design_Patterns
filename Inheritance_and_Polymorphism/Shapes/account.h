#ifndef ACCOUNT_H
#define ACCOUNT_H

    #include <QString>
    #include <QDate>

    class Account
    {
    public:
        Account(unsigned acctno, double balance, QString owner);
        virtual ~Account();
    protected:
        unsigned m_AccountNo;
        double m_Balance;
        QString m_Owner;
    public:
        virtual void deposite(double amt);
        virtual QString toString() const;
        virtual QString toString(char delimiter);       /* overload */
        virtual QString getName() const;
    };

    class InsecureAccount : public Account
    {
    public:
        InsecureAccount(unsigned acctno, double balance, QString owner);
        QString toString() const;       /* override base method and hide toString(char) */

        /* Does NOT override any method, but hide all Account::deposite() methods. */
        void deposite(double amt, QDate postDate);
    };

    class JointAccount : public Account
    {
    public:
        JointAccount(unsigned acctNum, double balance, QString owner, QString jointowner);
        JointAccount(const Account& acct, QString jointowner);
        ~JointAccount();
    private:
        QString m_JointOwner;
    public:
        QString getName() const;
    };

#endif  /* ACCOUNT_H */
