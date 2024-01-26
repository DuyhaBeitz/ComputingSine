//sine funcs
#include "../Sine_functions/cordic_fixed_point.cpp"
#include "../Sine_functions/cordic.cpp"
#include "../Sine_functions/table_sine.cpp"
#include "../Sine_functions/taylor_series_sine.cpp"

//draw_func
#include "../Headers/pbPlots/draw_func.cpp"

int main()
{
    double pi = 3.141592654;
    draw_func(CordicSineFPN, 0.001, -2 * pi, 2 * pi, 3840.0, 2160.0, "CORDIC_fixed_point_number_sine");
    
    draw_func(cordic_sine, 0.001, -2 * pi, 2 * pi, 3840.0, 2160.0, "CORDIC_floating_point_number_sine");

    draw_func(table_sine_rad, 0.001, -2 * pi, 2 * pi, 3840.0, 2160.0, "Table_sine");

    draw_func(taylor_sin_one_arg, 0.001, -2 * pi, 2 * pi, 3840.0, 2160.0, "Taylor_series_sine");

    return 0;
}