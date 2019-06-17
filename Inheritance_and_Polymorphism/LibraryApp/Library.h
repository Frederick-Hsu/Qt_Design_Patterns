#ifndef LIBRARY_H
#define LIBRARY_H

    #include <QList>
    class RefItem;

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

#endif  /* LIBRARY_H */
