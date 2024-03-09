#include "../test_accuracy/Headers/abs_error.h"
#include "../Sine_functions/Headers/taylor_series_sine.h"
#include "draw_func.cpp"

void error_from_n(double increment, double start, double end, double width, double high, std::string name)
{
    std::vector<double> x = {};
    std::vector<double> y = {};

    for(double i = start; i <= end; i+=increment)
    {
        x.push_back(i);
        y.push_back(avg_abs_sine_error(unsigned(i), taylor_series_sine, 0.0001, -200.0, 200.0));
    }

    plot(x, y, width, high, name);
}

int main()
{
    //std::cout.precision(25);
    //std::cout << std::fixed;
    //std::cout << max_abs_sine_error(9, taylor_series_sine, 0.0001, -200.0, 200.0);
    
    /*
    for (int n = 1; n < 11; n++)
    {
        std::cout << '(' << n << ", " << avg_abs_sine_error(n, taylor_series_sine, 0.0001, -200.0, 200.0) << "), ";;
    }
    */
    
    
    error_from_n(1.0, 12.0, 15.0, 3840.0 / 2, 2160.0 / 2, "Taylor_error");
}