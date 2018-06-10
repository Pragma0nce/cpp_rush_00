#include "Timer.hpp"

// Timer::Timer()
// {

// }

// Timer::Timer(bool run)
// {
//     if (run)
//         reset();
// }

// void Timer::reset()
// {
//     _start = high_resolution_clock::now();
// }

// std::chrono::milliseconds Timer::elapsed() const
// {
//     return std::chrono::duration_cast<milliseconds>(high_resolution_clock::now() - _start);
// }

Timer::Timer()
{

}

void Timer::reset()
{
    timer = std::time(0);
}

double Timer::elapsed() const
{
    return (std::time(0) - timer);
}