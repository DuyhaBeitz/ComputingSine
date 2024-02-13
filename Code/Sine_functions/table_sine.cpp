#include <cmath>
#include <iostream>
#include "../Utilities/sine_helper.cpp"//Sign()

//accept angles from 0 to 90
double table[91] = {
    0.0,
    0.0174524,
    0.0348995,
    0.052336,
    0.0697565,
    0.0871557,
    0.104528,
    0.121869,
    0.139173,
    0.156434,
    0.173648,
    0.190809,
    0.207912,
    0.224951,
    0.241922,
    0.258819,
    0.275637,
    0.292372,
    0.309017,
    0.325568,
    0.34202,
    0.358368,
    0.374607,
    0.390731,
    0.406737,
    0.422618,
    0.438371,
    0.45399,
    0.469472,
    0.48481,
    0.5,
    0.515038,
    0.529919,
    0.544639,
    0.559193,
    0.573576,
    0.587785,
    0.601815,
    0.615661,
    0.62932,
    0.642788,
    0.656059,
    0.669131,
    0.681998,
    0.694658,
    0.707107,
    0.71934,
    0.731354,
    0.743145,
    0.75471,
    0.766044,
    0.777146,
    0.788011,
    0.798636,
    0.809017,
    0.819152,
    0.829038,
    0.838671,
    0.848048,
    0.857167,
    0.866025,
    0.87462,
    0.882948,
    0.891007,
    0.898794,
    0.906308,
    0.913545,
    0.920505,
    0.927184,
    0.93358,
    0.939693,
    0.945519,
    0.951057,
    0.956305,
    0.961262,
    0.965926,
    0.970296,
    0.97437,
    0.978148,
    0.981627,
    0.984808,
    0.987688,
    0.990268,
    0.992546,
    0.994522,
    0.996195,
    0.997564,
    0.99863,
    0.999391,
    0.999848,
    1.0
};

double table_sine(double x)
{
    int reduced_x = Degrees(reduce_angle(x));
    
    return table[reduced_x] * sine_sign(x);
}

double table_sine_interp(double x)
{
    double reduced_x = reduce_angle(x);

    double x1 = Radians(int(Degrees(reduced_x)));
    double x2 = Radians(int(Degrees(reduced_x) + 1));

    double y_change = table_sine(reduced_x + Radians(1)) - table_sine(reduced_x);
    double k = (reduced_x - x1) / Radians(1);

    return sine_sign(x) * (table_sine(reduced_x) + y_change * k);
}