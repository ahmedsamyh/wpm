#pragma once
#include "Vec.hpp"

namespace momo {

enum MOUSE_BTN { BTN_LEFT = 0, BTN_RIGHT, BTN_MIDDLE, BTN_COUNT };

struct Mouse {

  Vec2 pos;
  bool released[BTN_COUNT];
  bool pressed[BTN_COUNT];
  bool held[BTN_COUNT];
  float scroll;

  Mouse();

  void reset();
};
} // namespace momo
