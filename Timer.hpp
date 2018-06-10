#pragma once
#include <iostream>
#include <chrono>


// class Timer 
// {
//     typedef std::chrono::high_resolution_clock high_resolution_clock;
//     typedef std::chrono::milliseconds milliseconds;
// public:
//     Timer();
//     Timer(bool run);
//     void reset();
//     milliseconds elapsed() const;
// private:
//     high_resolution_clock::time_point _start;
// };

class Timer 
{
private:
    time_t timer;
protected:
public:
    Timer(Timer &other);
    Timer& operator=(const Timer& other);
    Timer();
    void reset();
    double elapsed() const;

    ~Timer();
};