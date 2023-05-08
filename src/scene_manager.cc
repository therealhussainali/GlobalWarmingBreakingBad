#include "../include/scene.h"

namespace proj {

SceneManager::SceneManager(std::initializer_list<Scene> scenes)
    : current_scene_(0), change_scene_(false), scenes_(scenes) {}

SceneManager::SceneManager()
    : current_scene_(0), change_scene_(false) {}

void SceneManager::update() {
  if (change_scene_) {
    (current_scene_ + 1 == scenes_.size()) ? current_scene_ = 0 : ++current_scene_;
    change_scene_ = false;
  }
}

void SceneManager::addScene(const Scene &scene) {
  scenes_.emplace_back(scene);
}

void SceneManager::addScenes(std::initializer_list<Scene> scenes) {
  for (const auto &scene : scenes) {
    this->addScene(scene);
  }
}

void SceneManager::playCurrentScene() {
  scenes_[current_scene_].update();
  scenes_[current_scene_].draw();
}

void SceneManager::issueSceneChange() {
  change_scene_ = true;
}

} /* namespace proj */
