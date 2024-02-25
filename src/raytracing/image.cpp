#include "raytracing/image.hpp"
#include <fstream>
#include <iostream>
namespace RT
{
    bool savePPMImage(const Image &image, const std::string &filePath)
    {
        std::ofstream ostrm(filePath, std::ios::out);
        if (!ostrm.is_open())
        {
            return false;
        }
        ostrm << "P3\n"
              << image.width << ' ' << image.height << "\n255\n";
        for (const auto &pixel : image.data)
        {
            ostrm << static_cast<unsigned>(pixel.r) << ' ' << static_cast<unsigned>(pixel.g) << ' ' << static_cast<unsigned>(pixel.b) << '\n';
        }
        return true;
    }
} // namespace RT
