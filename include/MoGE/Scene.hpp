#pragma once
#include <SFML/Graphics.hpp>

namespace momo {

struct Scene {
  size_t id = 0;
  virtual void init();
  virtual void update(float dt);
  virtual void draw();
  virtual void input();
  virtual void clean();
};
} // namespace momo
