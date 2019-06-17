#ifndef BOOK_H
#define BOOK_H

    #include "RefItem.h"

    class Book : public RefItem
    {
    public:
        Book(QString type,
             QString isbn,
             QString title,
             QString author,
             QString pub,
             int year,
             int numCopies = 1);
        Book(QStringList& proplist);

        virtual QString toString(QString sep = "[::]") const;
        QString getAuthor() const;
        QString getPublisher() const;
        int getCopyrightYear() const;
    private:
        QString m_Author;
        QString m_Publisher;
        int m_CopyrightYear;
    };

#endif  /* BOOK_H */
