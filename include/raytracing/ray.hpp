#ifndef __RAYTRACE_RAY_HPP_
#define __RAYTRACE_RAR_HPP_
#include "geometry.hpp"
namespace RT {

template <typename Type> class Ray {
public:
  explicit Ray(const Vector3<Type> &origin, const Vector3<Type> &direction)
      : origin_{origin}, direction_{direction} {}

  Point3<Type> origin() const { return origin_; }
  Vector3<Type> direction() const { return direction_; }
  Point3<Type> at(Type t) { return origin_ + t * direction_; }

private:
  Point3<Type> origin_;
  Vector3<Type> direction_;
};

} // namespace RT

#endif