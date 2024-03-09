#include "Headers/taylor_series_sine.h"
#include <cmath>
#include "../Utilities/Headers/basic_math.h"
#include "../Utilities/Headers/sine_helper.h"//range reduction

double taylor_series_sine(double x)
{
    unsigned n = 9;

    //range reduction
    double reduced_x = reduce_angle(x);

    //siries is an infinite sum. Here sum of n elements
    double series_value = 0.0;
    for (unsigned i = 0; i < n; i++)
    {
        double a = std::pow(-1, i);
        double b = std::pow(reduced_x, 2 * i + 1);
        double c = Factorial(2 * i + 1);
        series_value += a * b / c;
    }

    return series_value * sine_sign(x); 
}


double taylor_series_sine(double x, unsigned n = 9)
{
    //range reduction
    double reduced_x = reduce_angle(x);

    //siries is an infinite sum. Here sum of n elements
    
    double series_value = 0.0;
    for (unsigned i = 0; i < n; i++)
    {
        double a = std::pow(-1, i);
        double b = std::pow(reduced_x, 2 * i + 1);
        double c = Factorial(2 * i + 1);
        series_value += a * b / c;
    }

    return series_value * sine_sign(x); 
}
