#include "pbPlots.hpp"
#include "supportLib.hpp"
#include <vector>

void plot(std::vector<double> x, std::vector<double> y, double width, double high, std::string name)
{
    RGBABitmapImageReference* imageRef = CreateRGBABitmapImageReference();

    StringReference errorString{0};

    DrawScatterPlot(imageRef, width, high, &x, &y, &errorString);

    std::string full_name = "Images/" + name;

    std::vector<double> *pngData = ConvertToPNG(imageRef->image);
    WriteToFile(pngData, full_name);
    DeleteImage(imageRef->image);
}