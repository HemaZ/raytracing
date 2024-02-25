#include <gtest/gtest.h>
#include <raytracing/image.hpp>
class TestImagePPM : public testing::Test
{
protected:
    void SetUp() override
    {
        image_.height = 480;
        image_.width = 640;
        for (int j = 0; j < image_.height; ++j)
        {
            for (int i = 0; i < image_.width; ++i)
            {
                auto r = double(i) / (image_.width - 1);
                auto g = double(j) / (image_.height - 1);
                auto b = 0;

                std::uint8_t ir = static_cast<std::uint8_t>(255.0 * r);
                std::uint8_t ig = static_cast<std::uint8_t>(255.0 * g);
                std::uint8_t ib = static_cast<std::uint8_t>(255.0 * b);

                image_.data.push_back({ir, ig, ib});
            }
        }
    }
    RT::Image image_;
};

TEST_F(TestImagePPM, BasicSaving)
{
    ASSERT_TRUE(RT::savePPMImage(image_, "test_image.ppm"));
}

TEST_F(TestImagePPM, BasicSavingNoPermissions)
{
    ASSERT_FALSE(RT::savePPMImage(image_, "/test_image.ppm"));
}
