#include "account.h"

void verifyAccount(void)
{
    InsecureAccount acct(12345, 321.98, "Luke Skywalker");
    // acct.deposite(6.23);     /* Error! no matching function, hidden by InsecureAccount::deposite(double, QDate) */
    // acct.m_Balance += 6.23;  /* Error! member is protected, inaccessible */

    /* Hidden does not mean inaccessible, you can still access hidden public methods of base class,
     * via the scope resolution.
     */
    acct.Account::deposite(6.23);
}
