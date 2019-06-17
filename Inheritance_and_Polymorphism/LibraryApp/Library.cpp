#include "Library.h"
#include "RefItem.h"

#include <QDebug>

Library::Library()
{
}

Library::~Library()
{
    qDeleteAll(*this);
    clear();
}

Library::Library(const Library&) : QList<RefItem *>()
{
}

Library& Library::operator=(const Library&)
{
    return *this;
}

void Library::addRefItem(RefItem *&refitem)
{
    QString isbn(refitem->getISBN());
    RefItem* oldItem(findRefItem(isbn));
    if (oldItem == NULL)
    {
        append(refitem);
    }
    else
    {
        qDebug() << isbn << " already in the list: \n"
                 << oldItem->toString()
                 << "\nIncreasing number of copies and deleting new pointer.";
        int newNum = oldItem->getNumberOfCopies() + refitem->getNumberOfCopies();
        oldItem->setNumberOfCopies(newNum);
        delete refitem;
        refitem = 0;
    }
}

int Library::removeRefItem(QString isbn)
{
    RefItem* ref(findRefItem(isbn));
    int numCopies(-1);
    if (ref)
    {
        numCopies = (ref->getNumberOfCopies() - 1);
        if (numCopies == 0)
        {
            removeAll(ref);
            delete ref;
        }
        else
        {
            ref->setNumberOfCopies(numCopies);
        }
    }
    return numCopies;
}

RefItem* Library::findRefItem(QString isbn)
{
    for (int i = 0; i < size(); ++i)
    {
        if (at(i)->getISBN().trimmed() == isbn.trimmed())
        {
            return at(i);
        }
    }
    return nullptr;
}

bool Library::isInList(QString isbn)
{
    return findRefItem((isbn));
}

QString Library::toString(QString sep) const
{
    QStringList reflst;
    for (int i = 0; i < size(); ++i)
    {
         reflst << at(i)->toString();
    }
    return reflst.join(sep);
}

QString Library::getItemString(QString isbn)
{
    RefItem* ref(findRefItem(isbn));
    if (ref)
    {
        return ref->toString();
    }
    else
    {
        return QString();
    }
}
