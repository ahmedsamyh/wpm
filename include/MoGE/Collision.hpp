#pragma once
#include <MoGE/Vec.hpp>

namespace momo {
bool colRectRect(Vec2 p1, Vec2 s1, Vec2 p2, Vec2 s2);
bool colRectPoint(Vec2 p, Vec2 s, Vec2 p2);
}; // namespace momo
