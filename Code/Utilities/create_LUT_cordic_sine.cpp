#include <ios>
#include <iostream>
#include <cmath>

int main()
{
    double k = 1;

    std::cout.precision(30);
    std::cout << std::fixed;
    for (int i = 0; i < 15; i++)
    {
        double angle = std::atan(std::pow(2, -i));

        std::cout << angle << ",\n";

        k *= std::cos(angle);
    }

    std::cout << "\nk = " << k << '\n';
}