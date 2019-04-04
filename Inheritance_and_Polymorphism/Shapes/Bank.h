#ifndef BANK_H
#define BANK_H

    #include <QList>

    class Account;

    class Bank
    {
    public:
        Bank& operator<<(Account* acct);
        ~Bank();
    private:
        QList<Account*> m_Accounts;
    public:
        QString getAcctListing() const;
    };

    void testBank(void);

#endif  /* BANK_H */
