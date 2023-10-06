#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

namespace momo {
#define BGM_PREFIX "res/bgm/"
#define BGM_SUFFIX ".wav"
#define SFX_PREFIX "res/sfx/"
#define TEX_PREFIX "res/gfx/"
#define TEX_SUFFIX ".png"

struct Sound {
  std::string bus;
  sf::Sound snd;
};

struct Music {
  sf::Music msc;
  bool paused;
};

struct AssetManager {
  void loadAllSounds();
  void loadAllTextures();

  std::map<std::string, sf::Texture> textureMap;
  std::unordered_map<std::string, sf::SoundBuffer> soundBuffs;
  std::unordered_map<std::string, momo::Sound> sounds;
  std::unordered_map<std::string, momo::Music> musics;
  std::unordered_map<std::string, sf::Font> fonts;

  sf::Texture &loadTexture(const std::string &name);
  sf::Texture &getTexture(const std::string &name) const;
  void freeTextures();
  sf::SoundBuffer &loadSBuff(const std::string &filename,
                             const std::string &prefix = "res/sfx/",
                             const std::string &suffix = ".wav");
  sf::SoundBuffer &getSBuff(const std::string &name);
  sf::Sound &loadSound(const std::string &filename, const std::string &bus,
                       const std::string &suffix = ".wav");
  sf::Sound &getSound(const std::string &name);

  sf::Font &loadFont(const std::string &filename,
                     const std::string &prefix = "res/fonts/",
                     const std::string &suffix = ".ttf");
  sf::Font &getFont(const std::string &name);
};

}; // namespace momo
