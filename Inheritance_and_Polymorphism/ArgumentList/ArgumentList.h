#ifndef ARGUMENTLIST_H
#define ARGUMENTLIST_H

    #include <QStringList>

    class ArgumentList : public QStringList
    {
    public:
        ArgumentList();
        ArgumentList(int argc, char* argv[]);
        ArgumentList(const ArgumentList& arglist);

        bool getSwitch(QString option);
        QString getSwitchArg(QString option, QString defaultRetVal = QString());
    private:
        void argsToStringList(int argc, char* argv[]);
    };

    void processFile(QString filename, bool verbose);
    void runTestOnly(QStringList& listOfFiles, bool verbose);

#endif  /* ARGUMENTLIST_H */
