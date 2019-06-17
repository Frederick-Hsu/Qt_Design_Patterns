#ifndef LIBRARY_CLIENT_H
#define LIBRARY_CLIENT_H

    #include <QTextStream>

    class Library;

    QTextStream cout(stdout);
    QTextStream cin(stdin);

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
    Choices nextTask();
    void add(Library& lib, QStringList objdata);

#endif  /* LIBRARY_CLIENT_H */
