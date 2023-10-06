#pragma once
#include "AssetManager.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
#include <string>
#include <vector>

namespace momo {
typedef std::shared_ptr<Scene> scene_ptr;

// text enum
enum class HA { Center = 0, Right, Left };
enum class VA { Center = 0, Top, Bottom };

// Game Data --------------------------------------------------
struct Data {
  static sf::RenderWindow *win;
  static sf::RenderTexture *renTex;
  static Vec2 screenSize;
  static Vec2 actualSize;
  static bool isFullscreen;
  static bool isVsync;
  static bool running;
  static std::string title;
  static float delta;
  static std::vector<scene_ptr> scenes;
  static size_t currentScene;
  static Mouse mouse;
  static Mouse prevMouse;
  static std::vector<Key> keys;
  static AssetManager assets;
  static sf::VertexArray line;
  static sf::VertexArray triangle;
  static sf::Vertex point;
  static sf::RectangleShape rect;
  static sf::CircleShape circle;
  static float time;
  static sf::Text text;
  static VA textVAlignment;
  static HA textHAlignment;
  static sf::BlendMode blendMode;
  static std::stack<std::pair<VA, HA>> alignStack;
  static std::stack<sf::BlendMode> blendStack;
  static size_t charSize;
  static int lastCharEntered;
};

} // namespace momo
