#include <gtest/gtest.h>
#include <raytracing/geometry.hpp>

TEST(Geometry, CreatingVec3) {
  RT::Vector3<double> v1;
  ASSERT_EQ(v1.x(), 0.0);
  ASSERT_EQ(v1.y(), 0.0);
  ASSERT_EQ(v1.z(), 0.0);

  RT::Vector3<double> v2(1.0, 2.1, 3.1);
  ASSERT_EQ(v2.x(), 1.0);
  ASSERT_EQ(v2.y(), 2.1);
  ASSERT_EQ(v2.z(), 3.1);
}

TEST(Geometry, Operators) {
  RT::Vector3<double> v1(1.0, 2.1, 3.1);
  const RT::Vector3<double> v1Const(1.0, 2.1, 3.1);
  // - operator
  auto v2 = -v1;
  ASSERT_DOUBLE_EQ(v2.x(), -1.0);
  ASSERT_DOUBLE_EQ(v2.y(), -2.1);
  ASSERT_DOUBLE_EQ(v2.z(), -3.1);

  // [] const operator
  ASSERT_DOUBLE_EQ(v1Const[0], 1.0);
  ASSERT_DOUBLE_EQ(v1Const[1], 2.1);
  ASSERT_DOUBLE_EQ(v1Const[2], 3.1);

  // [] operator
  ASSERT_DOUBLE_EQ(v1[0], 1.0);
  ASSERT_DOUBLE_EQ(v1[1], 2.1);
  ASSERT_DOUBLE_EQ(v1[2], 3.1);

  // +=
  v1 += RT::Vector3<double>(0.1, 0.2, 0.3);
  ASSERT_DOUBLE_EQ(v1[0], 1.1);
  ASSERT_DOUBLE_EQ(v1[1], 2.3);
  ASSERT_DOUBLE_EQ(v1[2], 3.4);

  // *=
  v1 *= RT::Vector3<double>();
  ASSERT_DOUBLE_EQ(v1[0], 0.0);
  ASSERT_DOUBLE_EQ(v1[1], 0.0);
  ASSERT_DOUBLE_EQ(v1[2], 0.0);
}

TEST(Geometry, Length) {
  RT::Vector3F v1{1, 2, 3};
  ASSERT_FLOAT_EQ(v1.length(), sqrt(14));
}

TEST(Geometry, DotProduct) {
  RT::Vector3F v1{1, 2, 3};
  RT::Vector3F v2{1, 2, 3};
  float dotVal = v1.dot(v2);
  ASSERT_FLOAT_EQ(dotVal, 14);
}

TEST(Geometry, CrossProduct) {
  RT::Vector3F v1{1, 2, 3};
  RT::Vector3F v2{3, 2, 1};
  auto crossV = v1.cross(v2);
  ASSERT_FLOAT_EQ(crossV.x(), -4);
  ASSERT_FLOAT_EQ(crossV.y(), 8);
  ASSERT_FLOAT_EQ(crossV.z(), -4);
}

TEST(Geometry, UnitVector) {
  RT::Vector3F v1{1, 2, 3};
  auto unitV = v1.unitVector();
  EXPECT_NEAR(unitV.x(), 0.267261, 1e-4);
  EXPECT_NEAR(unitV.y(), 0.534522, 1e-4);
  EXPECT_NEAR(unitV.z(), 0.801784, 1e-4);
}