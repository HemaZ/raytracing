#ifndef __RAYTRACING_IMAGE_HPP__
#define __RAYTRACING_IMAGE_HPP__
#include <cstdint>
#include <vector>
#include <string>
namespace RT
{
    struct Pixel
    {
        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
    };

    /**
     * @brief Struct which reperesent a RGB image.
     *
     */
    struct Image
    {
        std::vector<Pixel> data;
        int width;
        int height;
    };

    /**
     * @brief Save an Image as .ppm format.
     *
     * @param image Input image to save.
     * @param filePath Fie path including the filename.ppm
     * @return bool True/False If success.
     */
    bool savePPMImage(const Image &image, const std::string &filePath);

} // namespace RT

#endif