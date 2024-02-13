#include <cmath>
#include "../Utilities/sine_helper.cpp"//range reduction

double taylor_siries_sine(double x)
{
    unsigned n = 17;

    //range reduction
    double reduced_x = reduce_angle(x);

    //siries is an infinite sum. Here sum of n elements
    double siries_value = 0.0;
    for (unsigned i = 0; i < n; i++)
    {
        int a = std::pow(-1, i);
        double b = std::pow(reduced_x, 2 * i + 1);
        unsigned c = Factorial(2 * i + 1);
        siries_value += a * b / c;
    }

    return siries_value * sine_sign(x); 
}