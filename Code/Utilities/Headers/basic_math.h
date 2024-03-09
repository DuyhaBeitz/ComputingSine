#pragma once

template<typename T>
int Sign(T Value)
{
    if (Value < 0) return -1;
    if (Value == 0) return 0;

    return 1;
}

double Factorial(unsigned x);

double Radians(double AngleInDegrees);

double Degrees(double AngleInRadians);