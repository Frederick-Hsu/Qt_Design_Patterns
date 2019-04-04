#include "account.h"
#include <QTextStream>
#include <QDebug>

Account::Account(unsigned acctno, double balance, QString owner) : m_AccountNo(acctno),
                                                                   m_Balance(balance),
                                                                   m_Owner(owner)
{
}

Account::~Account()
{
    qDebug() << "Closing Account - sending email to primary account holder: " << m_Owner << endl;
}

void Account::deposite(double amt)
{
    m_Balance += amt;
}

QString Account::toString() const
{
    return QString("Account No. = %1, Account name = %2, Balance = %3").arg(m_AccountNo)
                                                                       .arg(m_Owner)
                                                                       .arg(m_Balance);
}

QString Account::toString(char delimiter)
{
    QString str;
    QTextStream os(&str, QIODevice::ReadWrite);
    os << "Account No.: " << m_AccountNo << delimiter
       << "Account name: " << m_Owner << delimiter
       << "Account balance: " << m_Balance << delimiter
       << endl;
    return str;
}

QString Account::getName() const
{
    return m_Owner;
}

/*================================================================================================*/

InsecureAccount::InsecureAccount(unsigned acctno,
                                 double balance,
                                 QString owner) : Account(acctno, balance, owner)
{
}

QString InsecureAccount::toString() const
{
    return QString("This insecure account no = %1, name = %2, balance = %3").arg(m_AccountNo)
                                                                            .arg(m_Owner)
                                                                            .arg(m_Balance);
}

void InsecureAccount::deposite(double amt, QDate postDate)
{
    m_Balance += amt;
    qDebug() << "The owner " << m_Owner << " has deposited $" << amt << " into the account on "
             << postDate.toString() << endl;
}

/*================================================================================================*/
JointAccount::JointAccount(unsigned acctNum,
                           double balance,
                           QString owner,
                           QString jointowner) : Account(acctNum, balance, owner),
                                                 m_JointOwner(jointowner)
{
}

JointAccount::JointAccount(const Account& acct, QString jointowner) : Account(acct),
                                                                      m_JointOwner(jointowner)
{
}

JointAccount::~JointAccount()
{
    qDebug() << "Closing Joint Account - sending email to joint account holder: "
             << m_JointOwner << endl;
}

QString JointAccount::getName() const
{
    return QString("%1 and %2").arg(Account::getName()).arg(m_JointOwner);
}
