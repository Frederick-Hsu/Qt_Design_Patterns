#include "LibraryClient.h"
#include "RefItem.h"
#include "Book.h"
#include "Library.h"
#include "ReferenceBook.h"
#include <QDebug>
#include <QFile>

Choices nextTask()
{
    int choice;
    QString response;
    do
    {
        cout << READ << ". Read data from a file.\n"
             << ADD << ". Add items to the library.\n"
             << FIND << ". Find and display an item.\n"
             << REMOVE << ". Remove an item from the library.\n"
             << SAVE << ". Save the library list to a file.\n"
             << LIST << ". Brief listing of library items.\n"
             << QUIT << ". Exit from this program.\n"
             << "Your choice : " << flush;
        response = cin.readLine();
        choice = response.toInt();
    }
    while (choice < READ or choice > QUIT);
    return static_cast<Choices>(choice);
}

void add(Library& lib, QStringList objdata)
{
    cout << objdata.join("[::]") << endl;
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
