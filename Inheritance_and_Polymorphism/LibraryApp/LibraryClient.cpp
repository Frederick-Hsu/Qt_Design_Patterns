#include "LibraryClient.h"
#include "RefItem.h"
#include "Book.h"
#include "Library.h"
#include "ReferenceBook.h"
#include "qstd.h"

#include <QDebug>
#include <QFile>
#include <QDate>


Choices nextTask()
{
    int choice;
    QString response;
    do
    {
        qstd::cout << READ << ". Read data from a file.\n"
             << ADD << ". Add items to the library.\n"
             << FIND << ". Find and display an item.\n"
             << REMOVE << ". Remove an item from the library.\n"
             << SAVE << ". Save the library list to a file.\n"
             << LIST << ". Brief listing of library items.\n"
             << QUIT << ". Exit from this program.\n"
             << "Your choice : " << flush;
        response = qstd::cin.readLine();
        choice = response.toInt();
    }
    while (choice < READ or choice > QUIT);
    return static_cast<Choices>(choice);
}

void add(Library& lib, QStringList objdata)
{
    qstd::cout << objdata.join("[::]") << endl;
    QString type = objdata.first();
    RefItem* ref;
    switch (static_cast<Types>(TYPES.indexOf(type)))
    {
    case BOOK:
        ref = new Book(objdata);
        lib.addRefItem(ref);
        break;
    case REFERENCEBOOK:
        ref = new ReferenceBook(objdata);
        lib.addRefItem(ref);
        break;
    case TEXTBOOK:
    case DVD:
    case FILM:
    case DATADVD:
        break;
    default:
        qDebug() << "Bad type in add() function.";
        break;
    }
}

void save(Library& lib)
{
    QFile outf("libfile");
    outf.open(QIODevice::WriteOnly);
    QTextStream outstr(&outf);
    outstr << lib.toString();
    outf.close();
}

void find(Library& lib)
{

}

void remove(Library& lib)
{

}

void list(Library& lib)
{

}

void prepareToQuit(Library& lib)
{

}

void read(Library& lib)
{
    const QString sep("[::]");
    const int BADLIMIT = 5;
    QString line, type;
    QStringList objdata;
    QFile inf("libfile");
    inf.open(QIODevice::ReadOnly);
    QTextStream instr(&inf);
    int badlines = 0;

    while (not instr.atEnd())
    {
        if (badlines >= BADLIMIT)
        {
            qDebug() << "Too many bad lines! Aborting.";
            return;
        }
        line = instr.readLine();
        objdata = line.split(sep);
        if (objdata.isEmpty())
        {
            qDebug() << "Empty line in file!";
            ++badlines;
        }
        else if (not TYPES.contains(objdata.first()))
        {
            qDebug() << "Bad type in line: " << objdata.join(";;;");
            ++badlines;
        }
        else
        {
            add(lib, objdata);
        }
    }
}

QStringList promptRefItem()
{
    const int MAXCOPIES = 10;
    const int ISBNLEN(13);
    int copies;
    QString str;
    QStringList retval;
    while (1)
    {
        qstd::cout << "ISBN (" << ISBNLEN << " digits( : " << flush;
        str = qstd::cin.readLine();
        if (str.length() == ISBNLEN)
        {
            retval << str;
            break;
        }
    }
    qstd::cout << "Title : " << flush;
    retval << qstd::cin.readLine();
    while (1)
    {
        qstd::cout << "Number of copies : " << flush;
        copies = qstd::cin.readLine().toInt();
        if (copies > 0 and copies <= MAXCOPIES)
        {
            str.setNum(copies);
            break;
        }
    }
    retval << str;
    return retval;
}

QStringList promptBook()
{
    static const int MINYEAR(1900), MAXYEAR(QDate::currentDate().year());
    int year;
    QStringList retval(promptRefItem());
    QString str;
    qstd::cout << "Author: " << flush;
    retval << qstd::cin.readLine();
    qstd::cout << "Publisher : " << flush;
    retval << qstd::cin.readLine();
    while (1)
    {
        qstd::cout << "Copyright year: " << flush;
        year = qstd::cin.readLine().toInt();
        if ((year >= MINYEAR) and (year <= MAXYEAR))
        {
            str.setNum(year);
            break;
        }
    }
    retval << str;
    return retval;
}

QStringList promptReferenceBook()
{
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(promptBook());
    QStringList cats(ReferenceBook::getRefCategories());
    while (1)
    {
        qstd::cout << "Enter the index of the correct Reference Category: ";

        for (int i = 0; i < cats.size(); ++i)
        {
            qstd::cout << "\n\t(" << i << ") " << cats.at(i);
        }
        qstd::cout << "\n\t(-1)None of these\t:::" << flush;
        idx = qstd::cin.readLine().toInt(&ok);
        if (ok)
        {
            retval << str.setNum(idx);
            break;
        }
    }
    return retval;
}

void enterData(Library& lib)
{
    QString typestr;
    while (1)
    {
        qstd::cout << "Library item type: " << flush;
        typestr = qstd::cin.readLine();
        if (not TYPES.contains(typestr))
        {
            qstd::cout << "Please enter one of the following types:\n"
                 << TYPES.join(" ,")
                 << endl;
            continue;
        }
        break;
    }
    QStringList objdata;
    switch (TYPES.indexOf(typestr))
    {
    case BOOK:
        objdata = promptBook();
        break;
    case REFERENCEBOOK:
        objdata = promptReferenceBook();
        break;
    default:
        qDebug() << "Bad type in enterData()";
        break;
    }
    objdata.prepend(typestr);
    add(lib, objdata);
}
