#pragma once
#include "Maths.hpp"
#include <iostream>
#include <string>

namespace momo {

struct Vec2 {
  float x = 0;
  float y = 0;

  // Constructor
  Vec2(float _x = 0.f, float _y = 0.f);
  Vec2(float _v);

  // Arithmetic operations with Vecs and scalars
  Vec2 operator+(const Vec2 rhs) const;
  Vec2 operator+(const float rhs) const;
  Vec2 operator-(const Vec2 rhs) const;
  Vec2 operator-(const float rhs) const;
  Vec2 operator*(const Vec2 rhs) const;
  Vec2 operator*(const float rhs) const;
  Vec2 operator/(const Vec2 rhs) const;
  Vec2 operator/(const float rhs) const;

  // Arithmetic operations with Vec2s and scalars {that change this Vec2}
  void operator+=(const Vec2 rhs);
  void operator+=(const float rhs);
  void operator-=(const Vec2 rhs);
  void operator-=(const float rhs);
  void operator*=(const Vec2 rhs);
  void operator*=(const float rhs);
  void operator/=(const Vec2 rhs);
  void operator/=(const float rhs);

  // comparers
  bool operator==(const Vec2 rhs);
  bool operator!=(const Vec2 rhs);
  bool operator>(const Vec2 rhs);
  bool operator<(const Vec2 rhs);
  bool operator>=(const Vec2 rhs);
  bool operator<=(const Vec2 rhs);

  /// Utility
  // to print to std::cout
  friend std::ostream &operator<<(std::ostream &os, Vec2 v) {
    return os << v.x << ", " << v.y;
  };

  std::string asStr() const;

  // Methods
  void clamp(Vec2 rangex, Vec2 rangey);

  float mag() const;
  float mag2() const;
  float dist() const;
  void normalize();
  Vec2 copy() const;
  Vec2 getNormalized() const;
  float radians() const;
  float degrees() const;
  // Static
  static Vec2 fromRadians(float rad);
  static Vec2 fromDegrees(float deg);
  static Vec2 random(float mag = 1);
}; // Vec2

struct Vec3 {
  float x = 0.f;
  float y = 0.f;
  float z = 0.f;

  // Constructor
  Vec3(float _x = 0.f, float _y = 0.f, float _z = 0.f);
  Vec3(float _v);

  // Arithmetic operations with Vecs and scalars
  Vec3 operator+(const Vec3 rhs) const;
  Vec3 operator+(const float rhs) const;
  Vec3 operator-(const Vec3 rhs) const;
  Vec3 operator-(const float rhs) const;
  Vec3 operator*(const Vec3 rhs) const;
  Vec3 operator*(const float rhs) const;
  Vec3 operator/(const Vec3 rhs) const;
  Vec3 operator/(const float rhs) const;

  // Arithmetic operations with Vec3s and scalars {that change this Vec3}
  void operator+=(const Vec3 rhs);
  void operator+=(const float rhs);
  void operator-=(const Vec3 rhs);
  void operator-=(const float rhs);
  void operator*=(const Vec3 rhs);
  void operator*=(const float rhs);
  void operator/=(const Vec3 rhs);
  void operator/=(const float rhs);

  /// Utility
  // to print to std::cout
  friend std::ostream &operator<<(std::ostream &os, Vec3 v) {
    return os << v.x << ", " << v.y << ", " << v.z;
  }
  std::string asStr() const;

  // Methods
  void clamp(Vec2 rangex, Vec2 rangey, Vec2 rangez);

  float mag() const;
  float mag2() const;
  float dist() const;
  void normalize();
  Vec3 copy() const;
  Vec3 getNormalized() const;
  float dot(const Vec3 &other);
}; // Vec3
} // namespace momo
