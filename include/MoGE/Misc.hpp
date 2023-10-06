#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <vector>
namespace momo {
std::vector<std::string> wordsFromLine(std::string line);

void embedImgToHpp(sf::Image &img, const std::string &img_name,
                   const std::string &filename);

// Sort
template <typename T>
void sortBubble(std::vector<T> &vec, std::function<float(T &)> comparer);
}; // namespace momo
