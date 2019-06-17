#include "Book.h"

Book::Book(QString type,
           QString isbn,
           QString title,
           QString author,
           QString pub,
           int year,
           int numCopies) : RefItem(type, isbn, title, numCopies)
{
    m_Author = author;
    m_Publisher = pub;
    m_CopyrightYear = year;
}

Book::Book(QStringList& proplist) : RefItem(proplist)
{
    m_Author = proplist.takeFirst();
    m_Publisher = proplist.takeFirst();
    m_CopyrightYear = proplist.takeFirst().toInt();
}

QString Book::toString(QString sep) const
{
    return QString("%1%2%3%4%5%6%7").arg(RefItem::toString(sep)).arg(sep)
                                    .arg(m_Author).arg(sep)
                                    .arg(m_Publisher).arg(sep)
                                    .arg(m_CopyrightYear);
}

QString Book::getAuthor() const
{
    return m_Author;
}

QString Book::getPublisher() const
{
    return m_Publisher;
}

int Book::getCopyrightYear() const
{
    return m_CopyrightYear;
}
