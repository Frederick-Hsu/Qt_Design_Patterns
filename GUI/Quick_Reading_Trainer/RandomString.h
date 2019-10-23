#ifndef RANDOM_STRING_H
#define RANDOM_STRING_H

    #include <QString>

    class RandomString
    {
    public:
        RandomString(int len = 0);
    private:
        int m_stringLength;
        QString m_randomString;
    public:
        QString generateString();
        QString generateString(int len);

        void setStringLength(int len);
        int getStringLength();
        bool isMatch(QString responseStr);
        int numCorrectChars(QString responseStr);
    };

#endif  /* RANDOM_STRING_H */
