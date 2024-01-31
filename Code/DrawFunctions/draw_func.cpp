#include "plot.cpp"
#include <cmath>
#include <vector>

void draw_func(double(*func)(double), double increment, double start, double end, double width, double high, std::string name)
{
    std::vector<double> x = {};
    std::vector<double> y = {};

    for(double i = start; i <= end; i+=increment)
    {
        x.push_back(i);
        y.push_back(func(i));
    }

    plot(x, y, width, high, name);
}

void draw_func(float(*func)(float), float increment, float start, float end, double width, double high, std::string name)
{
    std::vector<float> x_f = {};
    std::vector<float> y_f = {};

    for(float i = start; i <= end; i+=increment)
    {
        x_f.push_back(i);
        y_f.push_back(func(i));
    }

    std::vector<double> x;
    std::vector<double> y;

    for (float i : x_f)
    {
        x.push_back(double(i));
    }
    for (float i : y_f)
    {
        y.push_back(double(i));
    }

    plot(x, y, width, high, name);
}