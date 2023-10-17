#include "Game.h"

#include <cmath>
#include <iostream>

#include "DamagingObstacle.h"
#include "Levels.h"
#include "Obstacle.h"
#include "PowerUpBlock.h"

Game::Game(sf::RenderWindow& window, Levels& levels)
    : window(window),
      levels(levels),
      mario(100, 300, 32, 32, 4.0, 100, 10, "Mario", window),
      boundingBoxMario(mario.getSprite()),
      playerStats(playerStats),
      showText(true) {
  playerStats.setKills(0);
  isLevelOver = false;
  secondLevelStart = false; 

  mario.set_texture("MarioIdle.png");
  mario.x = 0;

  if (!font.loadFromFile("ClassicalDiary.ttf")) {
    std::cout << "faield to load font" << std::endl;
  }

  // gives instructions to user
  text1.setFont(font);
  text1.setString("Press 'n' to progress");
  text1.setCharacterSize(50);
  text1.setFillColor(sf::Color::Transparent);
  text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
  text1.setPosition(0.f, -100.f);

  text2.setFont(font);
  text2.setString("Half way there!");
  text2.setCharacterSize(50);
  text2.setFillColor(sf::Color::Red);
  text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
  text2.setPosition(5000.f, 300.f);

  deathText.setFont(font);
  deathText.setCharacterSize(30);
  deathText.setFillColor(sf::Color::Red);
  deathText.setStyle(sf::Text::Bold | sf::Text::Underlined);
  deathText.setPosition(-450.f, -100.f);

  highScoreText.setFont(font);
  highScoreText.setCharacterSize(30);
  highScoreText.setFillColor(sf::Color::Red);
  highScoreText.setStyle(sf::Text::Bold | sf::Text::Underlined);
  highScoreText.setPosition(-450.f, -50.f);

  menu.setFont(font);
  menu.setString(
      " Instructions:\n arrow keys to move left/right\n space to jump\n Q to "
      "reset after dying\n H to print gamestats for last 10 games");
  menu.setCharacterSize(30);
  menu.setFillColor(sf::Color::Red);
  menu.setStyle(sf::Text::Bold);
  menu.setPosition(0.f, -100.f);

  for (int i = 0; i < 5; i++) {
    powerUpCollected[i] = false;
  }
}

void Game::run() {
  while (window.isOpen()) {
    handleInput();
    update();
    render();

    // Update the view's position to follow the character
    view.setCenter(mario.x + mario.getLocalBounds().width, 325);
    window.setView(view);
  }
}

void Game::handleInput() {
  sf::Event event;
  bool loadStats = false;

  while (window.pollEvent(event)) {
    MovingObstacle** movingObstacles = levels.getmovingObstacles();

    if (event.type == sf::Event::Closed) {
      endGame();
      window.close();
    }

    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::H) {
      loadStats = true;  // Set the flag when 'H' key is pressed
    }

    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::P) {
      showText = !showText;
    }

    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::N && isLevelOver == true) {
      std::cout << "Deaths on level: " << playerStats.getDeaths() << std::endl;

      levels.ClearLevel();
      levels.LoadLevel2();
      mario.reset();
      secondLevelStart = true;
    }

    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Q && mario.isDead == true) {
      levels.ClearLevel();
      if (isLevelOver == false) {
        levels.LoadLevel1();
      }

      else {
        levels.LoadLevel2();
      }

      mario.reset();
    }
  }

  // Handle input for player and other game entities.
  mario.handleInput();

  if (loadStats) {
    loadPlayerStats();  // Call loadPlayerStats here if the flag is set
  }
}

void Game::update() {
  // Update game logic here.
  // Update player, enemies, power-ups, etc.
  mario.update();

  boundingBoxMario.update(mario.getSprite());

  levels.Update(mario.x);

  if (secondLevelStart == false){ 
     playerStats.update_high_score(mario.x);
  }

  else {
    playerStats.update_high_score(10000 + mario.x);
  }


 

  deathText.setPosition(mario.x - 450, -100.f);
  deathText.setString("Deaths: " + std::to_string(playerStats.getDeaths()));

  highScoreText.setPosition(mario.x - 450, -50.f);
  highScoreText.setString("High Score: " + std::to_string(static_cast<int>(
                                               playerStats.getScore())));

  handleCollisions();
}

void Game::handleCollisions() {
  sf::FloatRect marioBounds = mario.getBoundingbox();
  MovingObstacle** movingObstacles = levels.getmovingObstacles();

  sf::FloatRect movingObstacleBounds1 = movingObstacles[0]->getBoundingbox();
  sf::FloatRect movingObstacleBounds2 = movingObstacles[1]->getBoundingbox();
  sf::FloatRect movingObstacleBounds3 = movingObstacles[2]->getBoundingbox();
  float movingX;

  // Access obstacles and their bounding boxes through levels
  std::vector<Obstacle*>& obstacles = levels.getObstacles();
  std::vector<BoundingBox*>& obstacleBoundingBoxes = levels.getBoundingBoxes();

  std::vector<DamagingObstacle*>& damagingObstacles =
      levels.getDamagingObstacles();
  std::vector<BoundingBox*>& BoundingBoxesDamagingObstacles =
      levels.getBoundingBoxesDamagingObstacles();

  std::vector<PowerUpBlock*>& PowerUpBlocks = levels.getPowerUpBlocks();
  std::vector<BoundingBox*>& BoundingBoxesPowerUpBlocks =
      levels.getBoundingBoxesPowerUpBlocks();

  // Calculate and add sf::FloatRect for each obstacle's bounding box
  for (auto obstacle : obstacles) {
    obstacleBounds.push_back(obstacle->getBoundingbox());
  }

  for (auto damagingObstacle : damagingObstacles) {
    damagingObstacleBounds.push_back(damagingObstacle->getBoundingbox());
  }

  for (auto PowerUpBlock : PowerUpBlocks) {
    powerUpBlocksBounds.push_back(PowerUpBlock->getBoundingbox());
  }

  if (movingObstacleBounds1.intersects(movingObstacleBounds2)) {
    movingObstacles[1]->set_y_position(movingObstacles[0]->get_y_position());
    movingObstacles[1]->set_x_position(movingObstacles[0]->get_x_position());
  }

  for (size_t i = 0; i < obstacles.size(); ++i) {
    if (i % 2 == 0) {
      if (marioBounds.intersects(obstacleBounds[i])) {
        mario.velocityY = 2;
      }
    } else {
      if (marioBounds.intersects(obstacleBounds[i])) {
        mario.isGrounded = true;
        mario.isJumping = false;
        float brickTopY;
        brickTopY = obstacleBounds[i].top + 1;
        // Set Mario's position to the top of the brick
        mario.y = brickTopY - marioBounds.height;
        mario.velocityY = -1;  // Oppose gravity
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    if (i % 2 != 0) {
      if (marioBounds.intersects(movingObstacles[i]->getBoundingbox())) {
        mario.velocityY = 2;
      }
    } else {
      if (marioBounds.intersects(movingObstacles[i]->getBoundingbox())) {
        mario.isGrounded = true;
        mario.isJumping = false;
        float brickTopY;
        brickTopY = movingObstacles[i]->getBoundingbox().top + 1;
        // Set Mario's position to the top of the brick
        mario.y = brickTopY - marioBounds.height;
        mario.velocityY = -1;  // Oppose gravity
      }
    }
  }

  if (marioBounds.intersects(movingObstacles[2]->getBoundingbox())) {
    if (mario.isPowerUp == false) {
      if (mario.deathAlreadyChecked == false) {
        playerStats.update_deaths();
        mario.deathAlreadyChecked = true;
      }

      mario.set_texture("MarioDeath.png");
      mario.isDead = true;
      
    }

    else { 
        movingObstacles[2]->die();
        playerStats.update_enemies_killed();

    }
  }
  for (size_t i = 0; i < damagingObstacles.size(); ++i) {
    if (marioBounds.intersects(damagingObstacleBounds[i])) {
      if (mario.deathAlreadyChecked == false) {
        playerStats.update_deaths();
        mario.deathAlreadyChecked = true;
      }

      mario.set_texture("MarioDeath.png");
      mario.isDead = true;
    }
  }

  for (size_t i = 0; i < PowerUpBlocks.size(); ++i) {
    if (marioBounds.intersects(powerUpBlocksBounds[i]) && PowerUpBlocks[i]->get_IsCollected() == false) {
      mario.velocityY = 2;
      mario.PowerUp();
      PowerUpBlocks[i]->dropPowerUp();
    }
  }

  text1.setFillColor(sf::Color::Transparent);
  if (marioBounds.intersects(obstacleBounds[31])) {
    text1.setPosition(9800.f, 250.f);
    text1.setFillColor(sf::Color::Red);
    isLevelOver = true;
  }
}

void Game::render() {
  window.clear();

  levels.Render(window);

  window.draw(mario.getSprite());

  boundingBoxMario.draw(window);

  window.draw(text1);
  window.draw(text2);

  if (showText) {
    window.draw(menu);
  }

  window.draw(deathText);
  window.draw(highScoreText);

  window.display();
}

void Game::savePlayerStats() { playerStats.saveToFile("player_stats.txt"); }

void Game::loadPlayerStats() {
  playerStats.printLast10GameStats("player_stats.txt");
}

void Game::endGame() {
  savePlayerStats();
  isGameEnded = true;
}