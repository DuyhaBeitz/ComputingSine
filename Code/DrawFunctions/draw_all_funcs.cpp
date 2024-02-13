//sine funcs
#include "../Sine_functions/cordic_fixed_point.cpp"
#include "../Sine_functions/cordic.cpp"
#include "../Sine_functions/table_sine.cpp"
#include "../Sine_functions/taylor_series_sine.cpp"

#include <iostream>

//draw_func
#include "draw_func.cpp"


int main()
{
    draw_func(cordic_sine_FPN, 0.001, -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "CORDIC_fixed_point_number_sine");
    
    draw_func(cordic_sine, 0.001, -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "CORDIC_floating_point_number_sine");

    draw_func(table_sine, 0.001, -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "Table_sine");

    draw_func(table_sine_interp, 0.001, -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "table_sine_interp");

    draw_func(taylor_siries_sine, 0.001,  -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "Taylor_series_sine");

    return 0;
}