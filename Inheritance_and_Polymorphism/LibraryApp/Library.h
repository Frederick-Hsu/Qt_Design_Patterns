#ifndef LIBRARY_H
#define LIBRARY_H

    #include <QList>
    #include <QMap>

    #define QLIST_INHERITANCE   1
    #define QMAP_INHERITANCE    2
    #define INHERITANCE_PARADIGM    QLIST_INHERITANCE

    class RefItem;

#if (INHERITANCE_PARADIGM == QLIST_INHERITANCE)
    class Library : public QList<RefItem*>
    {
    public:
        Library();
        ~Library();

        void addRefItem(RefItem*& refitem);
        int removeRefItem(QString isbn);
        QString toString(QString sep = "\n") const;
        bool isInList(QString isbn);
        QString getItemString(QString isbn);
    private:
        Library(const Library&);                /* copy constructor */
        Library& operator=(const Library&);     /* copy assignment constructor */
        RefItem* findRefItem(QString isbn);
    };
#elif (INHERITANCE_PARADIGM == QMAP_INHERITANCE)
    class Library : public QMap<QString, RefItem*>
    {
    public:
        Library();
        ~Library();
    };
#endif

#endif  /* LIBRARY_H */
