#pragma once
#include <functional>
#include <string>
#include <vector>
namespace momo {
std::vector<std::string> wordsFromLine(std::string line);

// Sort
template <typename T>
void sortBubble(std::vector<T> &vec, std::function<float(T &)> comparer);
}; // namespace momo
