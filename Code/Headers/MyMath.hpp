#ifndef MY_MATH
#define MY_MATH
#include <cmath>

template<typename T>
int Sign(T Value)
{
    if (Value < 0) return -1;
    if (Value == 0) return 0;

    return 1;
}

inline unsigned Factorial(unsigned x)
{
    unsigned fac = 1;
    for (unsigned i = 1; i <= x; i++)
    {
        fac *= i;
    }
    return fac;
}

constexpr inline double Radians(double AngleInDegrees)
{
    return AngleInDegrees * M_PI / 180 ; 
}

constexpr inline double Degrees(double AngleInRadians)
{
    return AngleInRadians * 180 / M_PI; 
}

#endif