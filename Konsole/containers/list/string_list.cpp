#include "string_list.h"

#include <QString>
#include <QStringList>
#include <QDebug>
#include <QListIterator>

void ManipulateStringList(void)
{
    QString winter = "December, January, February";
    QString spring = "March, April, May";
    QString summer = "June, July, August";
    QString autumn = "September, October, November";

    QStringList list;
    list << winter;
    list += spring;
    list.append(summer);
    list << autumn;

    qDebug() << "The Spring months are : " << list[1];

    QString allMonths = list.join(",");
    qDebug() << allMonths;

    /* Split is the opposite of join. Each month will have its own element. */
    QStringList monthList = allMonths.split(",");
    Q_ASSERT(monthList.size() == 12);

    foreach (const QString& str, monthList)     /* Qt foreach loop */
    {
        qDebug() << QString(" [%1] ").arg(str);
    }
    for (QStringList::iterator it = monthList.begin(); it != monthList.end(); ++it)     /* iterator : C++ STL style */
    {
        QString current = *it;
        qDebug() << "[[" << current << "]]";
    }
    QListIterator<QString> itor(monthList);     /* iterator : Java 1.2 style */
    while (itor.hasNext())
    {
        QString current = itor.next();
        qDebug() << "{" << current << "}";
    }
}
