#pragma once
#include <stdint.h>

namespace momo {
// COLORS
#define BLACK Color(0, 0, 0, 255)
#define WHITE Color(255, 255, 255, 255)
#define RED Color(255, 0, 0, 255)
#define GREEN Color(0, 255, 0, 255)
#define BLUE Color(0, 0, 255, 255)
#define BLANK Color(0, 0, 0, 0)
struct Color {
  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;
  uint8_t a = 0;

  Color(uint8_t _r = 0, uint8_t _g = 0, uint8_t _b = 0, uint8_t _a = 255.f);
  Color(uint32_t hexCol);

  // methods
  void interp(const Color &to, const float t);

  // statics
  static Color random(bool alpha = false);
  static Color fromHex(uint32_t hexCol);
};

} // namespace momo
