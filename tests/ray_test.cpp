#include <gtest/gtest.h>
#include <list>
#include <raytracing/ray.hpp>

template <typename T> class RayTest : public testing::Test {
public:
  using List = std::list<T>;
  static T shared_;
  T value_;
};
using MyTypes = ::testing::Types<float, double>;
TYPED_TEST_SUITE(RayTest, MyTypes);

TYPED_TEST(RayTest, CreateRay) {
  RT::Point3<TypeParam> origin{0, 0, 0};
  RT::Vector3<TypeParam> direction{1, 0, 0};
  RT::Ray<TypeParam> ray(origin, direction);
  RT::Point3<TypeParam> location = ray.at(1);
  ASSERT_EQ(location, RT::Point3<TypeParam>(1, 0, 0));
  location = ray.at(2);
  ASSERT_EQ(location, RT::Point3<TypeParam>(2, 0, 0));
}