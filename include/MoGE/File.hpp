#pragma once
#include <vector>

namespace momo {

void readAllBytes(char const *filename, std::vector<char> &data);
void readBytes(char const *filename, size_t bytes, std::vector<char> &data);
void readBytesFromData(const char *filename,
                       std::vector<std::vector<char>> &datas);
void writeAllBytes(const char *filename, std::vector<char> &data);
void writeBytesToData(const char *filename,
                      std::vector<std::vector<char>> &datas);

} // namespace momo
