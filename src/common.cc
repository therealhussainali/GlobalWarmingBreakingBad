#include "../include/common.h"

#include <iostream>
#include <locale>

namespace proj {

Resolution getScreenResolution() {
  return Resolution{sf::VideoMode::getDesktopMode().width,
                    sf::VideoMode::getDesktopMode().height};
}

std::string getAssetPath(const std::string &filename) {
  return std::string(kAssetsPath) + filename;
}

std::atomic_bool threads_terminate = false;
bool change_scene = false;

} /* namespace proj */
