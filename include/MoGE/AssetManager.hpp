#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

namespace momo {
#define BGM_PREFIX "res/bgm/"
#define BGM_SUFFIX ".wav"
#define SFX_PREFIX "res/sfx/"

struct Sound {
  std::string bus;
  sf::Sound snd;
};

struct Music {
  sf::Music msc;
  bool paused;
};

struct AssetManager {
  void loadAllTextures();
  void loadAllSounds();

  std::map<std::string, sf::Texture *> textures;
  std::map<std::string, sf::SoundBuffer> soundBuffs;
  std::map<std::string, momo::Sound> sounds;
  std::map<std::string, momo::Music> musics;
  std::map<std::string, sf::Font> fonts;

  sf::Texture &loadTexture(std::string filename,
                           std::string prefix = "res/gfx/",
                           std::string suffix = ".png");
  sf::Texture &getTexture(std::string name);
  sf::SoundBuffer &loadSBuff(std::string filename,
                             std::string prefix = "res/sfx/",
                             std::string suffix = ".wav");
  sf::SoundBuffer &getSBuff(std::string name);
  sf::Sound &loadSound(std::string filename, std::string bus,
                       std::string suffix = ".wav");
  sf::Sound &getSound(std::string name);

  sf::Font &loadFont(std::string filename, std::string prefix = "res/fonts/",
                     std::string suffix = ".ttf");
  sf::Font &getFont(std::string name);
};

}; // namespace momo
