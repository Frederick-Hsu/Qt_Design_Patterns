/**************************************************************************************************
 * File name    : qstd.h
 * Description  : Similar as the <iostream> in std namespace, define such streamized input / output
 *              : utility functions as cin, cout, cerr in qstd namespace.
 * Creator      : Frederique Hsu
 * Creation date: Wed.  30 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *  
 **************************************************************************************************/

#ifndef QSTD_H
#define QSTD_H

    #include <QTextStream>
    
    class QString;
    class QFile;
    
    namespace qstd
    {
        /* declared but not implemented */
        extern QTextStream cout;
        extern QTextStream cin;
        extern QTextStream cerr;

        /* function declarations */
        bool yes(QString yesNoQuestion);
        bool more(QString prompt);
        int promptInt(int base = 10);
        double promptDouble();
        void promptOutputFile(QFile& outfile);
        void promptInputFile(QFile& infile);
    };

#endif  /* QSTD_H */