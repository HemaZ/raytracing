#ifndef __RAYTRACING_GEOMETRY_HPP__
#define __RAYTRACING_GEOMETRY_HPP__
#include <cmath>
#include <iostream>
namespace RT {
template <typename Type> class Vector3 {
private:
  Type data_[3];

public:
  Vector3(Type x, Type y, Type z) : data_{x, y, z} {}
  Vector3() : Vector3(0, 0, 0) {}
  Type x() const { return data_[0]; }
  Type y() const { return data_[1]; }
  Type z() const { return data_[2]; }
  Vector3<Type> operator-() const {
    return Vector3<Type>(-data_[0], -data_[1], -data_[2]);
  }
  Type operator[](int i) const { return data_[i]; }
  Type &operator[](int i) { return data_[i]; }
  Vector3<Type> &operator+=(const Vector3<Type> &rhs) {
    data_[0] += rhs.x();
    data_[1] += rhs.y();
    data_[2] += rhs.z();
    return *this;
  }
  Vector3<Type> &operator*=(const Vector3<Type> &rhs) {
    data_[0] *= rhs.x();
    data_[1] *= rhs.y();
    data_[2] *= rhs.z();
    return *this;
  }
  Vector3<Type> &operator*=(Type rhs) {
    data_[0] *= rhs;
    data_[1] *= rhs;
    data_[2] *= rhs;
    return *this;
  }
  Vector3<Type> &operator/=(Type rhs) { return *this *= 1 / rhs; }
  Type length() const { return sqrt(lengthSquared()); }
  Type lengthSquared() const {
    return data_[0] * data_[0] + data_[1] * data_[1] + data_[2] * data_[2];
  }
  Type dot(const Vector3<Type> &rhs) {
    return data_[0] * rhs.x() + data_[1] * rhs.y() + data_[2] * rhs.z();
  }
  Vector3<Type> cross(const Vector3<Type> &rhs) {
    Type i = data_[1] * rhs.z() - rhs.y() * data_[2];
    Type j = data_[2] * rhs.x() - data_[0] * rhs.z();
    Type k = data_[0] * rhs.y() - data_[1] * rhs.x();
    return Vector3<Type>(i, j, k);
  }
  Vector3<Type> unitVector() const { return *this / this->length(); }
};

template <typename T>
inline bool operator==(const Vector3<T> &lhs, const Vector3<T> &rhs) {
  return (lhs.x() == rhs.x() && lhs.y() == rhs.y() && lhs.z() == rhs.z());
}

template <typename T>
inline std::ostream &operator<<(std::ostream &out, const Vector3<T> &v) {
  return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

template <typename T>
inline Vector3<T> operator+(const Vector3<T> &lhs, const Vector3<T> &rhs) {
  return Vector3<T>(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

template <typename T>
inline Vector3<T> operator-(const Vector3<T> &lhs, const Vector3<T> &rhs) {
  return Vector3<T>(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

template <typename T>
inline Vector3<T> operator*(const Vector3<T> &lhs, const Vector3<T> &rhs) {
  return Vector3<T>(lhs.x() * rhs.x(), lhs.y() * rhs.y(), lhs.z() * rhs.z());
}

template <typename T>
inline Vector3<T> operator*(T lhs, const Vector3<T> &rhs) {
  return Vector3<T>(lhs * rhs.x(), lhs * rhs.y(), lhs * rhs.z());
}

template <typename T>
inline Vector3<T> operator*(const Vector3<T> &lhs, T rhs) {
  return rhs * lhs;
}

template <typename T>
inline Vector3<T> operator/(const Vector3<T> &lhs, T rhs) {
  return (1 / rhs) * lhs;
}

template <typename T> T dot(const Vector3<T> &lhs, const Vector3<T> &rhs) {
  return lhs.dot(rhs);
}

template <typename T>
Vector3<T> cross(const Vector3<T> &lhs, const Vector3<T> &rhs) {
  return lhs.cross(rhs);
}

using Vector3F = Vector3<float>;
using Vector3D = Vector3<double>;
template <typename T> using Point3 = Vector3<T>;

} // namespace RT

#endif