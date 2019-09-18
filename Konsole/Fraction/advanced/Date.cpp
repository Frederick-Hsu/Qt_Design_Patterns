#include "Date.h"

#include <time.h>

void Date::setToToday()
{
    struct tm *tp = 0;
    time_t now = time(0);
    tp = localtime(&now);
    set(1900+tp->tm_year, 1+tp->tm_mon, tp->tm_mday);
}

void Date::set(int year, int month, int day)
{

}
