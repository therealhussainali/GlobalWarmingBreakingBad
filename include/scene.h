#ifndef SCENE_H_
#define SCENE_H_

#include <string>
#include <initializer_list>

#include <SFML/Graphics.hpp>

#include "common.h"
#include "image.h"

namespace proj {

class SceneManager;

class Scene : sf::Sprite {
 public:
  explicit Scene(sf::RenderWindow &window, SceneManager &manager, const std::string &image);
  ~Scene() = default;

  void update();
  void draw();

 private:
  sf::RenderWindow &window_;
  SceneManager &manager_;
  proj::Image image_;
};

class SceneManager final {
 public:
  explicit SceneManager();
  explicit SceneManager(std::initializer_list<Scene> scenes);
  ~SceneManager() = default;

  void update();
  void addScene(const Scene &scene);
  void addScenes(std::initializer_list<proj::Scene> scenes);
  void playCurrentScene();
  void issueSceneChange();

 private:
  std::vector<Scene> scenes_;
  unsigned int current_scene_;
  bool change_scene_;
};

} /* namespace proj */

#endif
