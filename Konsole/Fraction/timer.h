/**************************************************************************************************
 * File name    : timer.h
 * Description  : Define a new class Timer, which includes the friend.
 * Creator      : Frederick Hsu
 * Creation date: Thu.  24 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef TIMER_H
#define TIMER_H

    #include <iostream>

    class Time;
    class Timer;

    class Timer
    {
        friend class Clock;
        friend void Time::toString();
        friend std::ostream& operator<<(std::ostream& os, const Timer& obj);

    private:
        long m_Elasped;
    };

    class Time
    {
    public:
        // void toString() const;
    };

#endif  /* TIMER_H */
