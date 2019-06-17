#ifndef REFERENCEBOOK_H
#define REFERENCEBOOK_H

    #include "Book.h"

    class ReferenceBook : public Book
    {
    public:
        enum RefCategory
        {
            NONE = -1,
            Art,
            Architecture,
            ComputerScience,
            Literature,
            Math,
            Music,
            Science
        };
        ReferenceBook(QString type,
                      QString isbn,
                      QString title,
                      QString author,
                      QString pub,
                      int year,
                      RefCategory refcat,
                      int numCopies = 1);
        ReferenceBook(QStringList& proplist);
        QString toString(QString sep = "[::]") const;
        RefCategory getCategory() const;
        QString categoryString() const;
        static QStringList getRefCategories();
    private:
        RefCategory m_Category;
    };

#endif  /* REFERENCEBOOK_H */
