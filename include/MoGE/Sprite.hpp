#pragma once
#include "Vec.hpp"
#include <MoGE/Color.hpp>
#include <SFML/Graphics.hpp>
#include <string>

namespace momo {
#define ORIGIN_MIDDLE(spr)                                                     \
  spr.setOrigin(spr.getLocalBounds().width / 2, spr.getLocalBounds().height / 2)

struct Sprite : public sf::Drawable {
  sf::Sprite spr;
  size_t hframe;
  size_t hframes;
  size_t vframe;
  size_t vframes;
  float accumulated;
  float timePerFrame;
  float speed;
  int width;
  int height;
  Vec2 *bindedPos;
  // constructor
  Sprite();

  // getters
  Vec2 getPosition() const;
  Vec2 getScale() const;
  float getRotation() const;
  Vec2 getOrigin() const;
  Vec2 getSize() const;

  // setters
  void setPosition(Vec2 pos);
  void setScale(Vec2 scl);
  void setRotation(float deg);
  void setColor(Color col);
  void setOrigin(Vec2 org = Vec2(0, 0));

  // methods
  void init(std::string _name, int _hframes = 1, int _vframes = 1);
  void update(float delta);
  void animate(float delta, size_t from = 0, int to = -1);
  void fromSpriteSheet(sf::Texture &tex, std::string name, Vec2 p, Vec2 s);
  void changeHFrame(size_t f);
  void changeVFrame(size_t f);
  void bind(Vec2 *b);
  // draw function to be drawable with sf::RenderWindow
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
}; // namespace momo
