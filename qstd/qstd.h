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
        /**
         * yes/no prompt
         * interactive stdin UI - prompts user with a yes/no question. 
         * Repeatedly-asks until user provides a avalid answer.
         * 
         * @param yesNoQuestion - the yes/no question
         * @return true/false - dependeing on what the user responded.
         */
        bool yes(QString yesNoQuestion);
        /**
         * Convenience function that needs a specific question to the yes() function.
         * @usage do {......} while(more("foobar"));
         * so that user sees the question: "Another foobar (y/n)?"
         * 
         * @param name of the item being handled by the loop.
         */
        bool more(QString prompt);
        /**
         * A function for safely taking an int from the keyboard.
         * Takes data into QString and tests to make sure it can be converted to int
         * before returning.
         * 
         * @param base - allows choice of number base
         * @return validated int.
         */
        int promptInt(int base = 10);
        /**
         * A function for safely taking a double from the keyboard, takes data into a 
         * QString and tests to make sure it can be converted to double before returning.
         * 
         * @return validated double.
         */
        double promptDouble();
        /**
         * Complete dialog for opening a file for output. Asks user for file name, checks 
         * to see whether file already exists and, if so, asks the user if it is okay to 
         * overwrite.
         * 
         * @param reference QFile parameter is set to point to the (eventually) opened file.
         * @short Dialog for a output file prompt.
         */
        void promptOutputFile(QFile& outfile);
        /**
         * @short Dialog for input file prompt.
         */
        void promptInputFile(QFile& infile);
    };

#endif  /* QSTD_H */