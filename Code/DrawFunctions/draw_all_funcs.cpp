//sine funcs
#include "../Sine_functions/cordic_fixed_point.cpp"
#include "../Sine_functions/cordic.cpp"
#include "../Sine_functions/table_sine.cpp"
#include "../Sine_functions/taylor_series_sine.cpp"

//draw_func
#include "draw_func.cpp"

float table_sine_rad(float x)
{
    return table_sine(int(Degrees(x)));
} 

double taylor_sin_one_arg(double x)
{
    return double(taylor_siries_sine(x, 6));
}

int main()
{
    double pi = 3.141592654;
    draw_func(CordicSineFPN, 0.001, -2 * pi, 2 * pi, 3840.0, 2160.0, "CORDIC_fixed_point_number_sine");
    
    draw_func(cordic_sine, 0.001, -2 * pi, 2 * pi, 3840.0, 2160.0, "CORDIC_floating_point_number_sine");

    draw_func(table_sine_rad, 0.001, -2 * pi, 2 * pi, 3840.0, 2160.0, "Table_sine");

    draw_func(table_sine_smooth, 0.001, -2 * pi, 2 * pi, 3840.0, 2160.0, "Table_sine_smooth");

    draw_func(taylor_sin_one_arg, 0.001, -2 * pi, 2 * pi, 3840.0, 2160.0, "Taylor_series_sine");

    return 0;
}