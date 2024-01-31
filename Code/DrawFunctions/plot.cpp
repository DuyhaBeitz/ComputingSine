#include "../pbPlots/pbPlots.hpp"
#include "../pbPlots/supportLib.hpp"
#include <streambuf>
#include <vector>

#include <filesystem>

namespace fs = std::filesystem;

void plot(std::vector<double> x, std::vector<double> y, double width, double high, std::string name)
{
    RGBABitmapImageReference* imageRef = CreateRGBABitmapImageReference();

    StringReference errorString{0};

    DrawScatterPlot(imageRef, width, high, &x, &y, &errorString);

    fs::path newDirectoryPath = "Images";

    // Create the directory
    if (!fs::exists(newDirectoryPath))
    {
        fs::create_directories(newDirectoryPath);
        std::cout << "Directory created successfully.\n";
    }

    std::string full_name = "Images/" + name;

    std::vector<double> *pngData = ConvertToPNG(imageRef->image);

    WriteToFile(pngData, full_name);
    DeleteImage(imageRef->image);
}