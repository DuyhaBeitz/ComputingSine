#include <cmath>
#include "../Headers/MyMath.hpp"//Factorial()
#include "../Headers/sine_helper.hpp"//range reduction

double taylor_siries_sine(double x, unsigned n)
{
    //range reduction
    double limited_angle = sine_mirror_angle(x);
    int func_sign = sine_func_sign(x);

    //the best quadratic approx is also the best cubic approx
    if (n % 2 != 0)
    {
        return taylor_siries_sine(limited_angle, n - 1);
    }

    //siries is an infinite sum. Here sum of n elements
    double siries_value = 0.0;
    for (unsigned i = 0; i < n; i++)
    {
        double a = std::pow(-1, i);
        double b = std::pow(limited_angle, 2 * i + 1);
        unsigned c = Factorial(2 * i + 1);
        siries_value += a * b / c;
    }

    return siries_value * func_sign * Sign(x);
}

double taylor_sin_one_arg(double x)
{
    return double(taylor_siries_sine(x, 6));
}