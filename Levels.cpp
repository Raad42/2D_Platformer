#include "Levels.h"

Levels::Levels(sf::RenderWindow& window) : window(window) {

}

void Levels::LoadLevel1() {
    Obstacle* brick1 = new Obstacle(400, 600, 64, 64, window);
    Obstacle* brick2 = new Obstacle(400, 600, 64, 64, window);
    Obstacle* brick3 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick4 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* spike1 = new DamagingObstacle(400, 600, 64, 64, window, 10);

    obstacles.push_back(brick1);
    obstacles.push_back(brick2);
    obstacles.push_back(brick3);
    obstacles.push_back(brick4);
    obstacles.push_back(spike1);

    // Create BoundingBox objects for each obstacle and add them to BoundingBoxes vector
    for (auto obstacle : obstacles) {
        BoundingBoxes.push_back(new BoundingBox(obstacle->getSprite()));
    }
    
    brick1->set_texture("Bricks.png");
    brick2->set_texture("Bricks.png");
    brick3->set_texture("Bricks.png");
    brick4->set_texture("Bricks.png");
    spike1->set_texture("Thwomp.png");

    //Testing with making top brick layer really thin
    brick1->getSprite().setScale(0.4f, 0.20f);
    brick1->getSprite().setPosition(400, 610);
    
    brick2->getSprite().setScale(0.4f, 0.01f);
    brick2->getSprite().setPosition(400, 605);

    brick3->getSprite().setScale(0.4f, 0.1f);
    brick3->getSprite().setPosition(600, 380);
    
    brick4->getSprite().setScale(0.4f, 0.1f);
    brick4->getSprite().setPosition(600, 360);

    spike1->getSprite().setScale(1.f, 1.f);
    spike1->getSprite().setPosition(700, 700);
}

void Levels::Update() {
    // Update objects and handle game logic for this level
    for (size_t i = 0; i < obstacles.size(); ++i) {
        BoundingBoxes[i]->update(obstacles[i]->getSprite());
    }
}

void Levels::Render(sf::RenderWindow& window) {
    // Draw obstacles and their bounding boxes
    for (size_t i = 0; i < obstacles.size(); ++i) {
        window.draw(obstacles[i]->getSprite()); // Draw the obstacle sprite

        // Draw the bounding box using your BoundingBox class
        BoundingBoxes[i]->draw(window);
    }
}

Levels::~Levels(){
    for (auto obstacle : obstacles) {
        delete obstacle;
    }
    for (auto boundingBox : BoundingBoxes) {
        delete boundingBox;
    }
}