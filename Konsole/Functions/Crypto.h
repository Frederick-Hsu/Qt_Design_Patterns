#ifndef CRYPTO_H
#define CRYPTO_H

    #include <QString>
    #include <QVector>

    typedef unsigned short ushort;

    class Crypto
    {
    public:
        Crypto(ushort key, QString opsqe, ushort charsiz);
        QString encrypt(const QString& str);
        QString decrypt(const QString& str);
    private:
        QString shift(const QString& text, unsigned key);
        QString unshift(const QString& cryptext, unsigned key);
        QString permute(const QString& text, unsigned key);
        QString unpermit(const QString& scrtext, unsigned key);
        QVector<int> randomPerm(int n);
        static int limitedRand(int max);
    private:
        ushort m_Key;
        QString m_OpSequence;
        ushort m_CharSetSize;
        QVector<int> m_Perm;
    };

#endif  /* CRYPTO_H */
