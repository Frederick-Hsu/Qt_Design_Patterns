/**************************************************************************************************
 * File name    : Thing.h
 * Description  : Define a class Thing, which contains static member.
 * Creator      : Frederick Hsu
 * Creation date: Thu.  24 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef THING_H
#define THING_H

    class Thing
    {
    public:
        Thing(int a, int b);
        ~Thing();

        void display() const;
        static void showCount();
    private:
        int m_First;
        int m_Second;
        static int s_Count;
    };

    long nextNumber(void);

#endif  /* THING_H */
