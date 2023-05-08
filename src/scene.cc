#include "../include/scene.h"

namespace proj {

Scene::Scene(sf::RenderWindow &window, SceneManager &manager, const std::string &image)
    : window_(window), manager_(manager), image_(image) {}

void Scene::update() {
  if (proj::change_scene) {
    proj::change_scene = false;
    manager_.issueSceneChange();
  }
}

void Scene::draw() {
  window_.clear();
  window_.draw(image_);
  window_.display();
}

} /* namespace proj */
