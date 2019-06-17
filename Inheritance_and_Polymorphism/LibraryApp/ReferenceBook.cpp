#include "ReferenceBook.h"

QStringList ReferenceBook::getRefCategories()
{
    QStringList slist;
    slist.append(QString("%1 = %2").arg("NONE").arg(NONE));
    slist.append(QString("%1 = %2").arg("Art").arg(Art));
    slist.append(QString("%1 = %2").arg("Architecture").arg(Architecture));
    slist.append(QString("%1 = %2").arg("ComputerScience").arg(ComputerScience));
    slist.append(QString("%1 = %2").arg("Literatur").arg(Literature));
    slist.append(QString("%1 = %2").arg("Math").arg(Math));
    slist.append(QString("%1 = %2").arg("Music").arg(Music));
    slist.append(QString("%1 = %2").arg("Science").arg(Science));
    return slist;
}

ReferenceBook::ReferenceBook(QString type,
                             QString isbn,
                             QString title,
                             QString author,
                             QString pub,
                             int year,
                             RefCategory refcat,
                             int numCopies) : Book(type, isbn, title, author, pub, year, numCopies)
{
    m_Category = refcat;
}

ReferenceBook::ReferenceBook(QStringList& proplist) : Book(proplist)
{
    m_Category = static_cast<RefCategory>(proplist.takeFirst().toInt());
}

QString ReferenceBook::toString(QString sep) const
{
    return QString("%1%2%3").arg(Book::toString(sep)).arg(sep).arg(categoryString());
}

ReferenceBook::RefCategory ReferenceBook::getCategory() const
{
    return m_Category;
}

QString ReferenceBook::categoryString() const
{
    switch (m_Category)
    {
    case Art:
        return "Art";
    case Architecture:
        return "Architecture";
    case ComputerScience:
        return "Computer Science";
    case Literature:
        return "Literature";
    case Math:
        return "Math";
    case Music:
        return "Music";
    case Science:
        return "Science";
    default:
        return "None";
    }
}
