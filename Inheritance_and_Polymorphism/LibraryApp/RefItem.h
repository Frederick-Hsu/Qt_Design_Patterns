#ifndef REFITEM_H
#define REFITEM_H

    #include <QString>
    #include <QStringList>

    class RefItem
    {
    public:
        virtual ~RefItem();
    public:
        QString getItemType() const;
        QString getISBN() const;
        QString getTitle() const;
        int getNumberOfCopies() const;

        virtual QString toString(QString sep = "[::]") const;
        void setNumberOfCopies(int newVal);
    protected:
        /* Because RefItem's constructors are protected, client code cannot create
         * the objects of class RefItem. So RefItem is an abstract base class.
         */
        RefItem(QString type, QString isbn, QString title, int numCopies = 1);
        RefItem(QStringList& proplist);
    private:
        QString m_ItemType;
        QString m_ISBN;
        QString m_Title;
        int m_NumberOfCopies;
    };

#endif  /* REFITEM_H */
