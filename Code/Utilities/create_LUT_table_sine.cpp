#include <iostream>
#include <cmath>

int main()
{
    for (int n = 0; n < 91; n++)
    {
        double angle = n * M_PI / 180.0;
        std::cout << std::sin(angle) << ",\n";
    }
}