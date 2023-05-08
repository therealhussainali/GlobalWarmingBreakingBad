#include "../include/image.h"

#include "../include/common.h"

namespace proj {

Image::Image(const std::string &texture) {
  auto [screen_width, screen_height] = proj::getScreenResolution();
  texture_ = proj::loadAsset<sf::Texture>(texture);
  texture_.setSmooth(true);
  this->setTexture(texture_);
  this->setScale(screen_width / this->getLocalBounds().width,
                 screen_height / this->getLocalBounds().height);
}

} /* namespace proj */
