#include <cmath>

#pragma once

template<typename T>
int Sign(T Value)
{
    if (Value < 0) return -1;
    if (Value == 0) return 0;

    return 1;
}

unsigned Factorial(unsigned x)
{
    unsigned fac = 1;
    for (unsigned i = 1; i <= x; i++)
    {
        fac *= i;
    }
    return fac;
}

constexpr double Radians(double AngleInDegrees)
{
    return AngleInDegrees * M_PI / 180 ; 
}

constexpr double Degrees(double AngleInRadians)
{
    return AngleInRadians * 180 / M_PI; 
}