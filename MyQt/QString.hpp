#ifndef QSTRING_HPP
#define QSTRING_HPP

    #include "QChar.hpp"
    #include "QStringLiteral.hpp"

    class QString;

    class QString
    {
    public:
        typedef QStringData Data;

        inline QString() noexcept;
        explicit QString(const QChar* unicode, int size = -1);
        QString(QChar c);
        QString(int size, QChar c);
        inline QString(const QString&) noexcept;
        inline ~QString();
        QString& operator=(QChar c);
        QString& operator=(const QString&) noexcept;
        inline QString(QString&& other) noexcept : d(other.d)
        {
            other.d = Data::sharedNull();
        }
    private:
        Data* d;
    private:
        friend inline bool operator==(QChar, const QString&) noexcept;
        friend inline bool operator< (QChar, const QString&) noexcept;
    };

#endif  /* QSTRING_HPP */
