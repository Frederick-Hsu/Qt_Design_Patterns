#ifndef LIBRARY_CLIENT_H
#define LIBRARY_CLIENT_H

    #include <QStringList>

    #include "Library.h"

    enum Choices
    {
        READ = 1,
        ADD,
        FIND,
        REMOVE,
        SAVE,
        LIST,
        QUIT
    };

    enum Types
    {
        BOOK,
        REFERENCEBOOK,
        TEXTBOOK,
        DVD,
        FILM,
        DATADVD
    };

    const QStringList TYPES = (QStringList()
                               << "BOOK"
                               << "REFERENCEBOOK"
                               << "TEXTBOOK"
                               << "DVD"
                               << "FILM"
                               << "DATADVD");

    void save(Library& lib);
    void find(Library& lib);
    void remove(Library& lib);
    void list(Library& lib);
    void prepareToQuit(Library& lib);
    Choices nextTask();
    void add(Library& lib, QStringList objdata);
    void read(Library& lib);
    QStringList promptRefItem();
    QStringList promptBook();
    QStringList promptReferenceBook();
    void enterData(Library& lib);

#endif  /* LIBRARY_CLIENT_H */
