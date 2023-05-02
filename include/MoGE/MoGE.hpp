#pragma once
#include "3D.hpp"
#include "Collision.hpp"
#include "Color.hpp"
#include "File.hpp"
#include "GameData.hpp"
#include "Sprite.hpp"
#include "Timer.hpp"
#include "Vec.hpp"

namespace momo {
// convenient macros --------------------------------------------------
#define SW screenWidth()
#define SH screenHeight()
#define SS2 screenSize2()
#define SS3 screenSize3()
#define AW actualWidth()
#define AH actualHeight()
#define AS2 actualSize2()
#define AS3 actualSize3()
#define M2 mousePos2()
#define M3 mousePos3()
#define MAIN(scn) addMainScene(std::make_shared<scn>())
#define SCENE(scn) addScene(std::make_shared<scn>())
#define SF_COLOR(col)                                                          \
  sf::Color(sf::Uint8(col.r), sf::Uint8(col.g), sf::Uint8(col.b),              \
            sf::Uint8(col.a))
#define SF_VEC2F(vec2) sf::Vector2f(vec2.x, vec2.y)
#define SF_VEC2I(vec2) sf::Vector2i((int)vec2.x, (int)vec2.y)
#define SF_VEC2(vec2) SF_VEC2F(vec2)
#define SF_VEC2U(vec2) sf::Vector2u((unsigned int)vec2.x, (unsigned int)vec2.y)
#define MOGE_VEC2(sfVec2) momo::Vec2((float)sfVec2.x, (float)sfVec2.y)
#define MOGE_ERROR(msg)                                                        \
  {                                                                            \
    std::cout << LOC() << "ERROR: " << msg << "\n";                            \
    exit(66);                                                                  \
  }
#define PRINT_VAR(var) std::cout << #var << " = " << var << "\n"
#define PRINT_ASSETS                                                           \
  std::cout << "-- ASSETS --\n";                                               \
  std::cout << "\tTextures: " << Data::assets.textures.size() << "\n";         \
  std::cout << "\tSoundBuffs: " << Data::assets.soundBuffs.size() << "\n";     \
  std::cout << "\tSounds: " << Data::assets.sounds.size() << "\n";             \
  std::cout << "\tBgms: " << Data::assets.musics.size() << "\n"
#define REMOVE_IF(type, vector, condition)                                     \
  auto I = std::remove_if(vector.begin(), vector.end(),                        \
                          [](type e) { return condition; });                   \
  if (I != vector.end())                                                       \
  vector.erase(I, vector.end())
#define SMOOTH_TO(from, to, rate) from += (to - from) / rate
#define LOC() __FILE__ << ":" << __LINE__ << ":0 "
#define UNIMPLEMENTED()                                                        \
  std::cout << LOC() << __func__ << " is unimplemented!\n";                    \
  exit(66)
#define UNREACHABLE()                                                          \
  std::cout << LOC() << __func__ << " is unreachable!\n";                      \
  exit(66)
#define ASSERT(condition, msg)                                                 \
  if ((condition)) {                                                           \
    std::cerr << LOC() << msg << "\n";                                         \
    exit(1);                                                                   \
  }
#define EXC(body)                                                              \
  try {                                                                        \
    { body }                                                                   \
  } catch (std::exception & e) {                                               \
    std::cerr << __FILE__ << ":" << __LINE__ - 1 << ":0: " << e.what()         \
              << "\n";                                                         \
  }

// main game functions --------------------------------------------------
void create(std::string title = "MoGE", float width = 1280.f,
            float height = 720.f, float aWidth = -1.f, float aHeight = -1.f,
            bool vsync = true, std::string iconName = "icon");
void run();
void clean();
void quit();

// scene functions --------------------------------------------------
void addScene(scene_ptr scn);
void changeScene(size_t to);
void addMainScene(scene_ptr scn);

// screen functions --------------------------------------------------
void clear(Color col = BLACK);
Vec2 screenSize2();
Vec3 screenSize3();
float screenWidth();
float screenHeight();
Vec2 actualSize2();
Vec3 actualSize3();
float actualWidth();
float actualHeight();
void setIcon(std::string icon, std::string prefix = "res/gfx/",
             std::string suffix = ".png");
void fullscreen();
Vec2 screenToWorld(const Vec2 p);
Vec2 worldToScreen(const Vec2 p);
// drawing functions --------------------------------------------------
void drawLine(Vec2 v1, Vec2 v2, Color col = WHITE);
void drawLine2(Vec2 v1, Vec2 v2, Color col1 = WHITE, Color col2 = WHITE);
void drawTri(Vec2 v1, Vec2 v2, Vec2 v3, Color col = WHITE);
void drawTri2(Vec2 v1, Vec2 v2, Vec2 v3, Color col1 = WHITE, Color col2 = WHITE,
              Color col3 = WHITE);
void fillTri(Vec2 v1, Vec2 v2, Vec2 v3, Color col = WHITE);
void fillTri2(Vec2 v1, Vec2 v2, Vec2 v3, Color col1 = WHITE, Color col2 = WHITE,
              Color col3 = WHITE);
void drawCircle(Vec2 v1, float rad, Color col = WHITE);
void fillCircle(Vec2 v1, float rad, Color col = WHITE, Color outCol = WHITE);
void drawRect(Vec2 v1, Vec2 size, Color col = WHITE);
void fillRect(Vec2 v1, Vec2 size, Color col1 = WHITE, Color outCol = WHITE);
void drawSprite(Sprite &spr);
void drawSpriteAt(Vec2 pos, Sprite &spr);
void drawPoint(Vec2 v1, Color col = WHITE);
void drawPolygon(std::vector<Vec2> &points, Color col = WHITE,
                 Color outCol = WHITE);
void setBlendMode(const sf::BlendMode bl = sf::BlendAlpha);
sf::BlendMode &getBlendMode();
void pushBlend();
void popBlend();
// text functions --------------------------------------------------
void drawText(Vec2 v1, std::string text, size_t charSize = 16,
              Color col = WHITE);
void setTextAlign(VA v = VA::Top, HA h = HA::Left);
void pushAlign();
void popAlign();
void setCharSize(size_t size = 16);
size_t getCharSize();
Vec2 getCharSizeVec();
Vec2 getTextSize(std::string text, size_t charSize);

// keyboard functions --------------------------------------------------
bool keyPressed(size_t k);
bool keyReleased(size_t k);
bool keyHeld(size_t k);
void handleKeys();
void hotkeys();

// mouse functions --------------------------------------------------
bool mousePressed(size_t btn);
bool mouseReleased(size_t btn);
bool mouseHeld(size_t btn);
Vec2 mousePos2();
Vec3 mousePos3();
Vec2 nmousePos2();
Vec3 nmousePos3();
void handleMouse();
float mouseScroll();

// assets functions --------------------------------------------------
sf::Texture &loadTexture(std::string filename, std::string prefix = "res/gfx/",
                         std::string suffix = ".png");
sf::Texture &getTexture(std::string name);
sf::SoundBuffer &loadSBuff(std::string filename,
                           std::string prefix = "res/sfx/",
                           std::string suffix = ".wav");
sf::SoundBuffer &getSBuff(std::string name);
sf::Sound &loadSound(std::string filename, std::string prefix = "res/sfx/",
                     std::string suffix = ".wav");
sf::Sound &getSound(std::string name);
sf::Font &loadFont(std::string filename, std::string prefix = "res/fonts/",
                   std::string suffix = ".ttf");
sf::Font &getFont(std::string name);
// sound functions --------------------------------------------------
void playSound(std::string name, std::string bus, bool waitUntilFinish = false);
void playBgm(std::string name, bool loop = true);
void stopBgm(std::string name);
void pauseBgm(std::string name, bool toggle = true);
void setBgmVolume(std::string name, float vol);
void setBusVolume(std::string bus, float vol);
float getBusVolume(std::string bus);

}; // namespace momo
