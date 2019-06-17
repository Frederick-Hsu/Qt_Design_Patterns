#include "RefItem.h"

RefItem::RefItem(QString type, QString isbn, QString title, int numCopies)
{
    m_ItemType = type;
    m_ISBN = isbn;
    m_Title = title;
    m_NumberOfCopies = numCopies;
}

RefItem::RefItem(QStringList& proplist)
{
    if (proplist.isEmpty() == false)
    {
        m_ItemType = proplist.takeFirst();
        m_ISBN = proplist.takeFirst();
        m_Title = proplist.takeFirst();
        m_NumberOfCopies = proplist.takeFirst().toInt();
    }
}

RefItem::~RefItem()
{
}

QString RefItem::getItemType() const
{
    return m_ItemType;
}

QString RefItem::getISBN() const
{
    return m_ISBN;
}

QString RefItem::getTitle() const
{
    return m_Title;
}

int RefItem::getNumberOfCopies() const
{
    return m_NumberOfCopies;
}

QString RefItem::toString(QString sep) const
{
    return QString("%1%2%3%4%5%6%7").arg(m_ItemType).arg(sep)
                                    .arg(m_ISBN).arg(sep)
                                    .arg(m_Title).arg(sep)
                                    .arg(m_NumberOfCopies);
}

void RefItem::setNumberOfCopies(int newVal)
{
    m_NumberOfCopies = newVal;
}
