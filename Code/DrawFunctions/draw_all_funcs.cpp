//sine funcs
#include "../Sine_functions/Headers/cordic_fixed_point.h"
#include "../Sine_functions/Headers/cordic.h"
#include "../Sine_functions/Headers/table_sine.h"
#include "../Sine_functions/Headers/taylor_series_sine.h"

//draw_func
#include "draw_func.cpp"


int main()
{
    draw_func(cordic_sine_FPN, 0.001, -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "CORDIC_fixed_point_number_sine");
    
    draw_func(cordic_sine, 0.001, -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "CORDIC_floating_point_number_sine");

    draw_func(table_sine, 0.001, -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "Table_sine");

    draw_func(table_sine_interp, 0.001, -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "table_sine_interp");

    draw_func(taylor_series_sine, 0.001,  -4 * M_PI, 4 * M_PI, 3840.0, 2160.0, "Taylor_series_sine");

    return 0;
}