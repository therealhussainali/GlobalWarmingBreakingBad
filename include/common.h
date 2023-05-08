#ifndef COMMON_H_
#define COMMON_H_

#include <string>
#include <system_error>
#include <atomic>

#include <SFML/Graphics.hpp>

namespace proj {

struct Resolution final {
  unsigned int width = 0;
  unsigned int height = 0;
};

extern Resolution getScreenResolution();

extern std::string getAssetPath(const std::string &filename);

template<class T>
inline T loadAsset(const std::string &filename) {
  T asset;
  if (!asset.template loadFromFile(getAssetPath(filename))) {
    throw std::runtime_error("LoadAsset: failed to load asset!");
  }
  return asset;
}

constexpr thread_local const char *kAssetsPath = "assets/";
constexpr thread_local const char *kProjTitle = "Chemistry Project";
constexpr thread_local const unsigned int kFrameRate = 15;
extern std::atomic_bool threads_terminate;
extern bool change_scene;

} /* namespace proj */

#endif /* COMMON_H_ */
