#include "ArgumentList.h"
#include <QDebug>
#include <QCoreApplication>


ArgumentList::ArgumentList()
{
    if (qApp != NULL)
    {
        // *this = qApp->arguments();
    }
}

ArgumentList::ArgumentList(int argc, char* argv[])
{
    argsToStringList(argc, argv);
}

ArgumentList::ArgumentList(const ArgumentList& arglist) : QStringList(arglist)
{
}

void ArgumentList::argsToStringList(int argc, char* argv[])
{
    for (int index = 0; index < argc; ++index)
    {
        *this += argv[index];
    }
}

bool ArgumentList::getSwitch(QString option)
{
    QMutableStringListIterator itr(*this);
    while (itr.hasNext())
    {
        if (option == itr.next())
        {
            itr.remove();
            return true;
        }
    }
    return false;
}

QString ArgumentList::getSwitchArg(QString option, QString defaultRetVal)
{
    if (isEmpty())
    {
        return defaultRetVal;
    }
    QMutableStringListIterator itr(*this);
    while (itr.hasNext())
    {
        if (option == itr.next())
        {
            itr.remove();
            if (itr.hasNext())
            {
                QString retval = itr.next();
                itr.remove();
                return retval;
            }
            else
            {
                qDebug() << "Missing argument for " << option;
                return QString();
            }
        }
    }
    return defaultRetVal;
}

void processFile(QString filename, bool verbose)
{
    if (verbose)
    {
        qDebug() << QString("Do something chatty with %1.").arg(filename);
    }
    else
    {
        qDebug() << filename;
    }
}

void runTestOnly(QStringList& listOfFiles, bool verbose)
{
    foreach(const QString& current, listOfFiles)
    {
        processFile(current, verbose);
    }
}
