#include "Headers/sine_helper.h"
#include "Headers/basic_math.h"
#include <cmath>

double reduce_angle(double angle)
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

int sine_sign(double angle)
    {
        double abs_angle = std::abs(angle);
        bool half_period_even = (int(abs_angle / M_PI) % 2 == 0);

        if (!half_period_even) return -Sign(angle);

        return Sign(angle);
    }