#include <cmath>
#include "MyMath.cpp"

#pragma once

double sine_mirror_angle(double angle)
    {
        double abs_angle = std::abs(angle);

        while (abs_angle > M_PI)
        {
            abs_angle -= M_PI;
        }

        if (abs_angle > M_PI/2)
        {
            abs_angle = M_PI - abs_angle;
        }
        return abs_angle;
    }

int sine_func_sign(double angle)
    {
        double abs_angle = std::abs(angle);
        int func_sign = 1;
        int period_even = (int(abs_angle / M_PI) % 2 == 0);

        if (!period_even)
        {
            func_sign = -1;
        }

        return func_sign * Sign(angle);
    }