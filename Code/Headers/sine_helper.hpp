#include <cmath>

#ifndef SINE_HELPER
#define SINE_HELPER

inline double sine_mirror_angle(double angle)
    {
        double abs_angle = std::abs(angle);
        if (abs_angle > M_PI)
        {
            while (abs_angle > M_PI)
            {
                abs_angle -= M_PI;
            }
        }
        if (abs_angle > M_PI/2)
        {
            abs_angle = M_PI - abs_angle;
        }

        return abs_angle;
    }

inline int sine_func_sign(double angle)
    {
        double abs_angle = std::abs(angle);
        int func_sign = 1;
        int div_result = abs_angle / M_PI;

        if (abs_angle > M_PI)
        {
            if (div_result % 2 == 0)
            {
                func_sign = 1;
            }
            else
            {
                func_sign = -1;
            }
        }
        return func_sign;
    }

#endif