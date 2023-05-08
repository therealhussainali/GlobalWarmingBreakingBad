#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>

#include <SFML/Graphics.hpp>

namespace proj {

class Image final : public sf::Sprite {
 public:
  explicit Image(const std::string &texture);
  ~Image() = default;

 private:
  sf::Texture texture_;
};

} /* namespace proj */

#endif
