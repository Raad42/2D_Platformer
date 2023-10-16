#include "Levels.h"
#include "MovingObstacle.h"
#include <iostream>

Levels::Levels(sf::RenderWindow& window) : window(window) {
    // Populate the vector with level loading functions
    levelLoadFunctions.push_back(std::bind(&Levels::LoadLevel1, this));
    levelLoadFunctions.push_back(std::bind(&Levels::LoadLevel2, this));

    movingObstacles = nullptr; // Initialize the movingObstacles pointer
    movingObstacleBoundingbox = nullptr; // Initialize the movingObstacleBoundingbox pointer
}



void Levels::LoadLevel1() {

    Obstacle* brick1 = new Obstacle(400, 600, 64, 64, window);
    Obstacle* brick2 = new Obstacle(400, 600, 64, 64, window);
    Obstacle* brick3 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick4 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick5 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick6 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* flag = new Obstacle(400, 600, 64, 64, window);

    DamagingObstacle* spike1 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* lava1 = new DamagingObstacle(400, 600, 64, 64, window, 10);

    PowerUpBlock* powerUpBlock = new PowerUpBlock(1500, 600, 64, 64, window, 99);

    movingObstacles = new MovingObstacle*[2];
    movingObstacles[0] = new MovingObstacle(700, 500, 64, 64, window, 2, 0, 90, 600);
    movingObstacles[1] = new MovingObstacle(700, 500, 64, 64, window, 0, 0, 100, 800);

    movingObstacleBoundingbox = new BoundingBox*[2];
    movingObstacleBoundingbox[0] = new BoundingBox(movingObstacles[0]->getSprite());
    movingObstacleBoundingbox[1] = new BoundingBox(movingObstacles[1]->getSprite());

    // goomba = Enemy(1000, 300, 32, 32, 100, 10, "Goomba", "goomba.png");

    obstacles.push_back(brick1);
    obstacles.push_back(brick2);
    obstacles.push_back(brick3);
    obstacles.push_back(brick4);
    obstacles.push_back(flag);
    obstacles.push_back(powerUpBlock);
    obstacles.push_back(brick5);
    obstacles.push_back(brick6);

    damagingObstacles.push_back(spike1);
    damagingObstacles.push_back(lava1);
    obstacles.push_back(flag);
    PowerUpBlocks.push_back(powerUpBlock);
    

    // Create BoundingBox objects for each obstacle and add them to BoundingBoxes vector
    for (auto obstacle : obstacles) {
        BoundingBoxes.push_back(new BoundingBox(obstacle->getSprite()));
    }

    for (auto obstacle : damagingObstacles) {
        BoundingBoxesDamagingObstacles.push_back(new BoundingBox(obstacle->getSprite()));
    }

    for (auto obstacle : PowerUpBlocks) {
        BoundingBoxesPowerUpBlocks.push_back(new BoundingBox(obstacle->getSprite()));
    }
    
    brick1->set_texture("Bricks.png");
    brick2->set_texture("Bricks.png");
    brick3->set_texture("Bricks.png");
    brick4->set_texture("Bricks.png");
    // brick5->set_texture("Bricks.png");
    brick5->set_texture("Bricks.png");
    brick6->set_texture("Bricks.png");
    movingObstacles[0]->set_texture("Bricks.png");
    movingObstacles[1]->set_texture("Bricks.png");

    spike1->set_texture("Thwomp.png");
    lava1->set_texture("lava.png");
    flag->set_texture("pole.png");
    powerUpBlock->set_texture("QuestionBlock.png");

    //Testing with making top brick layer really thin
    brick1->getSprite().setScale(0.4f, 0.20f);
    brick1->getSprite().setPosition(400, 606);
    
    brick2->getSprite().setScale(0.4f, 0.01f);
    brick2->getSprite().setPosition(400, 605);

    brick3->getSprite().setScale(0.4f, 0.20f);
    brick3->getSprite().setPosition(600, 376);
    
    brick4->getSprite().setScale(0.4f, 0.01f);
    brick4->getSprite().setPosition(600, 375);

    brick5->getSprite().setScale(0.4f, 0.20f);
    brick5->getSprite().setPosition(1000, 376);

    brick6->getSprite().setScale(0.4f, 0.01f);
    brick6->getSprite().setPosition(1000, 375);

    movingObstacles[0]->getSprite().setPosition(640, 515);
    movingObstacles[0]->getSprite().setScale(0.4f, 0.01f);
    
    movingObstacles[1]->getSprite().setScale(0.4f, 0.20f);
    movingObstacles[1]->getSprite().setPosition(640, 520);

    spike1->getSprite().setScale(1.f, 1.f);
    spike1->getSprite().setPosition(700, 700);

    lava1->getSprite().setScale(1.f, 1.f);
    lava1->getSprite().setPosition(700, 790);

    flag->getSprite().setPosition(1000, 530);
    
    powerUpBlock->getSprite().setScale(3.0f, 3.0f);
    powerUpBlock->getSprite().setPosition(1500, 600);

    
    if (!backgroundTexture.loadFromFile("Level2BG.png")) {
        std::cout << "Background load failed for level 1" << std::endl;
    }


    backgroundSprite.setTexture(backgroundTexture);

    backgroundSprite.setPosition(-500, -200);

}

void Levels::LoadLevel2() {

    Obstacle* brick1 = new Obstacle(400, 600, 64, 64, window);
    Obstacle* brick2 = new Obstacle(400, 600, 64, 64, window);
    Obstacle* brick3 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick4 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick5 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick6 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* flag = new Obstacle(400, 600, 64, 64, window);

    DamagingObstacle* spike1 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* lava1 = new DamagingObstacle(400, 600, 64, 64, window, 10);

    PowerUpBlock* powerUpBlock = new PowerUpBlock(400, 600, 64, 64, window, 99);

    movingObstacles = new MovingObstacle*[2];
    movingObstacles[0] = new MovingObstacle(700, 500, 64, 64, window, 2, 0, 90, 600);
    movingObstacles[1] = new MovingObstacle(700, 500, 64, 64, window, 0, 0, 100, 800);

    movingObstacleBoundingbox = new BoundingBox*[2];
    movingObstacleBoundingbox[0] = new BoundingBox(movingObstacles[0]->getSprite());
    movingObstacleBoundingbox[1] = new BoundingBox(movingObstacles[1]->getSprite());

    // goomba = Enemy(1000, 300, 32, 32, 100, 10, "Goomba", "goomba.png");

    obstacles.push_back(brick1);
    obstacles.push_back(brick2);
    obstacles.push_back(brick3);
    obstacles.push_back(brick4);
    obstacles.push_back(flag);
    obstacles.push_back(powerUpBlock);
    obstacles.push_back(brick5);
    obstacles.push_back(brick6);

    damagingObstacles.push_back(spike1);
    damagingObstacles.push_back(lava1);
    obstacles.push_back(flag);
    PowerUpBlocks.push_back(powerUpBlock);
    

    // Create BoundingBox objects for each obstacle and add them to BoundingBoxes vector
    for (auto obstacle : obstacles) {
        BoundingBoxes.push_back(new BoundingBox(obstacle->getSprite()));
    }

    for (auto obstacle : damagingObstacles) {
        BoundingBoxesDamagingObstacles.push_back(new BoundingBox(obstacle->getSprite()));
    }

    for (auto obstacle : PowerUpBlocks) {
        BoundingBoxesPowerUpBlocks.push_back(new BoundingBox(obstacle->getSprite()));
    }
    
    brick1->set_texture("Bricks.png");
    brick2->set_texture("Bricks.png");
    brick3->set_texture("Bricks.png");
    brick4->set_texture("Bricks.png");
    // brick5->set_texture("Bricks.png");
    brick5->set_texture("Bricks.png");
    brick6->set_texture("Bricks.png");
    movingObstacles[0]->set_texture("Bricks.png");
    movingObstacles[1]->set_texture("Bricks.png");

    spike1->set_texture("Thwomp.png");
    lava1->set_texture("lava.png");
    flag->set_texture("pole.png");
    powerUpBlock->set_texture("QuestionBlock.png");

    //Testing with making top brick layer really thin
    brick1->getSprite().setScale(0.4f, 0.20f);
    brick1->getSprite().setPosition(400, 606);
    
    brick2->getSprite().setScale(0.4f, 0.01f);
    brick2->getSprite().setPosition(400, 605);

    brick3->getSprite().setScale(0.4f, 0.20f);
    brick3->getSprite().setPosition(600, 376);
    
    brick4->getSprite().setScale(0.4f, 0.01f);
    brick4->getSprite().setPosition(600, 375);

    brick5->getSprite().setScale(0.4f, 0.20f);
    brick5->getSprite().setPosition(1000, 376);

    brick6->getSprite().setScale(0.4f, 0.01f);
    brick6->getSprite().setPosition(1000, 375);

    movingObstacles[0]->getSprite().setPosition(640, 515);
    movingObstacles[0]->getSprite().setScale(0.4f, 0.01f);
    
    movingObstacles[1]->getSprite().setScale(0.4f, 0.20f);
    movingObstacles[1]->getSprite().setPosition(640, 520);

    spike1->getSprite().setScale(1.f, 1.f);
    spike1->getSprite().setPosition(700, 700);

    lava1->getSprite().setScale(1.f, 1.f);
    lava1->getSprite().setPosition(700, 790);

    flag->getSprite().setPosition(1000, 530);
    
    powerUpBlock->getSprite().setScale(3.0f, 3.0f);
    powerUpBlock->getSprite().setPosition(1000, 600);

    
    if (!backgroundTexture.loadFromFile("Level3BG.png")) {
        std::cout << "Background load failed for level 2" << std::endl;
    }


    backgroundSprite.setTexture(backgroundTexture);

    backgroundSprite.setPosition(-500, -200);
}



void Levels::Update() {
    // Update objects and handle game logic for this level
    for (size_t i = 0; i < obstacles.size(); ++i) {
        BoundingBoxes[i]->update(obstacles[i]->getSprite());
    }

    for (size_t i = 0; i < damagingObstacles.size(); ++i) {
        BoundingBoxesDamagingObstacles[i]->update(damagingObstacles[i]->getSprite());
    }

    for (size_t i = 0; i < PowerUpBlocks.size(); ++i) {
        BoundingBoxesPowerUpBlocks[i]->update(PowerUpBlocks[i]->getSprite());
    }

    for (int i = 0; i < 2; i++){
        movingObstacles[i]->update();
        movingObstacleBoundingbox[i]->update(movingObstacles[i]->getSprite());
    }
    
    // goomba.move();

}

void Levels::Render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
    // Draw obstacles and their bounding boxes
    for (size_t i = 0; i < obstacles.size(); ++i) {
        window.draw(obstacles[i]->getSprite()); // Draw the obstacle sprite

        // Draw the bounding box using your BoundingBox class
        BoundingBoxes[i]->draw(window);

    }

    for (size_t i = 0; i < damagingObstacles.size(); ++i) {
        window.draw(damagingObstacles[i]->getSprite()); // Draw the obstacle sprite

        // Draw the bounding box using your BoundingBox class
        BoundingBoxesDamagingObstacles[i]->draw(window);
    }

    for (size_t i = 0; i < PowerUpBlocks.size(); ++i) {
        window.draw(PowerUpBlocks[i]->getSprite());
        BoundingBoxesPowerUpBlocks[i]->draw(window);
    }

    for (int i = 0; i < 2; i++){
        window.draw(movingObstacles[i]->getSprite());
        movingObstacleBoundingbox[i]->draw(window);
    }
    
    // goomba.draw(window);
}

Levels::~Levels(){
    for (auto obstacle : obstacles) {
        delete obstacle;
    }
    for (auto boundingBox : BoundingBoxes) {
        delete boundingBox;
    }

    for (int i = 0; i < 2; i++){
        delete movingObstacles[i];
        delete movingObstacleBoundingbox[i];
    }
}

void Levels::ClearLevel() {
    for (auto obstacle : obstacles) {
        delete obstacle;
    }
    obstacles.clear();

    for (auto boundingBox : BoundingBoxes) {
        delete boundingBox;
    }
    BoundingBoxes.clear();
}