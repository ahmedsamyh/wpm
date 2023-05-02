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
namespace Data {
extern sf::RenderWindow *win;
extern sf::RenderTexture *renTex;
extern Vec2 screenSize;
extern Vec2 actualSize;
extern bool isFullscreen;
extern bool isVsync;
extern bool running;
extern std::string title;
extern float delta;
extern std::vector<scene_ptr> scenes;
extern size_t currentScene;
extern Mouse mouse;
extern Mouse prevMouse;
extern std::vector<Key> keys;
extern std::vector<Key> prevKeys;
extern AssetManager assets;
extern sf::VertexArray line;
extern sf::VertexArray triangle;
extern sf::Vertex point;
extern sf::RectangleShape rect;
extern sf::CircleShape circle;
extern float time;
extern sf::Text text;
extern VA textVAlignment;
extern HA textHAlignment;
extern sf::BlendMode blendMode;
extern std::stack<std::pair<VA, HA>> alignStack;
extern std::stack<sf::BlendMode> blendStack;
extern size_t charSize;
}; // namespace Data

} // namespace momo
