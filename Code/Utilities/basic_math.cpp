#include "Headers/basic_math.h"
#include <cmath>

double Factorial(unsigned x)
{
    double fac = 1;
    for (unsigned i = 1; i <= x; i++)
    {
        fac *= i;
    }
    return fac;
}

double Radians(double AngleInDegrees)
{
    return AngleInDegrees * M_PI / 180 ; 
}

double Degrees(double AngleInRadians)
{
    return AngleInRadians * 180 / M_PI; 
}