#ifndef LIBRARY_UI_H
#define LIBRARY_UI_H

    #include <QStringList>

    class Library;

    class LibraryUI
    {
    public:
        enum Choices
        {
            READ,
            ADD,
            FIND,
            REMOVE,
            SAVE,
            LIST,
            QUIT
        };
    private:
        Library* m_Lib;
    public:
        LibraryUI(Library* lib);
        void add(QStringList objdata);
        void read();
        void enterData();
        void remove();
        void save();
        void list();
        QStringList promptRefItem();
        QStringList promptBook();
        QStringList promptReferenceBook();
        QStringList promptTextBook();
        QStringList promptDvd();
        QStringList promptFilm();
        QStringList promptDataBase();
        Choices nextTask();
        void prepareToQuit(bool saved);
    };

#endif  /* LIBRARY_UI_H */
