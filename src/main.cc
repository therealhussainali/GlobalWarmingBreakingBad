/* CHEMISTRY PROJECT IN SFML */

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../include/common.h"
#include "../include/scene.h"
#include "../include/image.h"

static void handlePollEvents(sf::RenderWindow &window);
static void playMusic(const std::string &filename);

int main([[maybe_unused]] int argc, [[maybe_unused]] char *const argv[]) {
  /* get fullscreen resolution */
  sf::VideoMode screen_mode([]() -> sf::VideoMode {
    auto [screen_width, screen_height] = proj::getScreenResolution();
    return sf::VideoMode(screen_width, screen_height);
  }());

  /* create a window with our fullscreen res we got above */
  sf::RenderWindow window(screen_mode, proj::kProjTitle, sf::Style::Fullscreen);
  window.setFramerateLimit(proj::kFrameRate);
  window.setMouseCursorVisible(false);

  /* get window icon */
  auto window_icon = proj::loadAsset<sf::Image>("Icon.jpeg");
  window.setIcon(window_icon.getSize().x, window_icon.getSize().y,
                 window_icon.getPixelsPtr());

  proj::SceneManager scene_manager;

  /* project intro scene */
  const proj::Scene project_intro(window, scene_manager, "project_intro.jpeg");

  /* lydia scenes */
  const proj::Scene definition_intro(window, scene_manager, "definition_intro.jpeg");
  const proj::Scene definition_intro2(window, scene_manager, "definition_intro2.jpeg");
  const proj::Scene definition_p1(window, scene_manager, "definition_p1.jpeg");
  const proj::Scene definition_p2(window, scene_manager, "definition_p2.jpeg");
  const proj::Scene definition_image1(window, scene_manager, "th-2817142850.jpeg");
  const proj::Scene definition_p3(window, scene_manager, "definition_p3.jpeg");
  const proj::Scene definition_p4(window, scene_manager, "definition_p4.jpeg");
  const proj::Scene definition_image2(window, scene_manager, "th-1329528714.jpeg");

  /* maria scenes */
  const proj::Scene consequences_intro(window, scene_manager, "consequences_intro.jpeg");
  const proj::Scene consequences_p1(window, scene_manager, "consequences_p1.jpeg");
  const proj::Scene consequences_p2(window, scene_manager, "consequences_p2.jpeg");
  const proj::Scene consequences_p3(window, scene_manager, "consequences_p3.jpeg");
  const proj::Scene consequences_p4(window, scene_manager, "consequences_p4.jpeg");

  /* fourogatos scenes */
  const proj::Scene solutions_intro(window, scene_manager, "solutions_intro.jpeg");
  const proj::Scene solutions_p1(window, scene_manager, "solutions_p1.jpeg");
  const proj::Scene solutions_p2(window, scene_manager, "solutions_p2.jpeg");
  const proj::Scene solutions_p3(window, scene_manager, "solutions_p3.jpeg");
  const proj::Scene solutions_p4(window, scene_manager, "solutions_p4.jpeg");
  const proj::Scene solutions_p5(window, scene_manager, "solutions_p5.jpeg");
  const proj::Scene solutions_image1(window, scene_manager, "IMG_20230429_165613_017.jpg");
  const proj::Scene solutions_image2(window, scene_manager, "IMG_20230429_165243_009.jpg");

  /* project bibliography/outro scene */
  const proj::Scene bibliography(window, scene_manager, "bibliography.jpeg");
  const proj::Scene project_outro(window, scene_manager, "project_outro.jpeg");

  scene_manager.addScenes({
      /* project intro */
      project_intro,

      /* segment .lydia */
      definition_intro,
      definition_p1,
      definition_intro2,
      definition_p2,
      definition_image1,
      definition_p3,
      definition_p4,
      definition_image2,

      /* segment .maria */
      consequences_intro,
      consequences_p1,
      consequences_p2,
      consequences_p3,
      consequences_p4,

      /* segment .fourogatos */
      solutions_intro,
      solutions_p1,
      solutions_p2,
      solutions_p3,
      solutions_image1,
      solutions_p4,
      solutions_p5,
      solutions_image2,

      /* project outro */
      bibliography,
      project_outro
    });

  sf::Thread music_thread(playMusic, "Breaking_Bad.ogg");
  music_thread.launch();

  while (window.isOpen()) {
    handlePollEvents(window);
    scene_manager.update();
    scene_manager.playCurrentScene();
  }

  music_thread.wait();
  return EXIT_SUCCESS;
}

static void handlePollEvents(sf::RenderWindow &window) {
  sf::Event event;

  while (window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        proj::threads_terminate = true;
        window.close();
        break;

      /* make sure Escape key closes the application */
      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Key::Escape) {
          proj::threads_terminate = true;
          window.close();
        }
        break;

      case sf::Event::KeyReleased:
        if (event.key.code == sf::Keyboard::Key::Space) {
          proj::change_scene = true;
        }
        break;

      default:
        break;
    }
  }
}

static void playMusic(const std::string &filename) {
  sf::Music music;
  if (!music.openFromFile(proj::getAssetPath(filename))) {
    throw std::runtime_error("couldn't open music file");
  }

  music.setLoop(true);
  music.play();
  while (music.getStatus() == sf::Music::Status::Playing) {
    if (proj::threads_terminate) {
      break;
    }
    sf::sleep(sf::milliseconds(100));
  }
}
