#include "Levels.h"
#include "MovingObstacle.h"
#include "Enemy.h"
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
    Obstacle* brick7 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick8 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick9 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick10 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick11 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick12 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick13 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick14 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick15 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick16 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick17 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick18 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick19 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick20 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick21 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick22 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick23 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick24 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick25 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick26 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick27 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick28 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick29 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick30 = new Obstacle(600, 500, 64, 64, window);

    Obstacle* flag = new Obstacle(10000, 600, 64, 64, window);

    DamagingObstacle* spike1 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* spike2 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* spike3 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* spike4 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* spike5 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* muncher1 = new DamagingObstacle(400, 600, 64, 64, window, 10);    
    DamagingObstacle* muncher2 = new DamagingObstacle(400, 600, 64, 64, window, 10);            
    DamagingObstacle* lava1 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* lava2 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava3 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava4 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava5 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava6 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava7 = new DamagingObstacle(400, 600, 10, 64, window, 10);

    PowerUpBlock* powerUpBlock = new PowerUpBlock(1500, 600, 64, 64, window, 99);

    movingObstacles = new MovingObstacle*[3];
    movingObstacles[0] = new MovingObstacle(8800, 250, 64, 64, window, 2, 0, 8400, 9300, false);
    movingObstacles[1] = new MovingObstacle(8800, 250, 64, 64, window, 0, 0, 8400, 9300, false);
    movingObstacles[2] = new MovingObstacle(5000, 730, 64, 64, window, 1, 0, 1000, 2000, true);

    movingObstacleBoundingbox = new BoundingBox*[3];
    movingObstacleBoundingbox[0] = new BoundingBox(movingObstacles[0]->getSprite());
    movingObstacleBoundingbox[1] = new BoundingBox(movingObstacles[1]->getSprite());
    movingObstacleBoundingbox[2] = new BoundingBox(movingObstacles[2]->getSprite());

    obstacles.push_back(brick1);
    obstacles.push_back(brick2);
    obstacles.push_back(brick3);
    obstacles.push_back(brick4);
    obstacles.push_back(brick5);
    obstacles.push_back(brick6);
    obstacles.push_back(brick7);
    obstacles.push_back(brick8);
    obstacles.push_back(brick9);
    obstacles.push_back(brick10);
    obstacles.push_back(brick11);
    obstacles.push_back(brick12);
    obstacles.push_back(brick13);
    obstacles.push_back(brick14);
    obstacles.push_back(brick15);
    obstacles.push_back(brick16);
    obstacles.push_back(brick17);
    obstacles.push_back(brick18);
    obstacles.push_back(brick19);
    obstacles.push_back(brick20);
    obstacles.push_back(brick21);
    obstacles.push_back(brick22);
    obstacles.push_back(brick23);
    obstacles.push_back(brick24);
    obstacles.push_back(brick25);
    obstacles.push_back(brick26);
    obstacles.push_back(brick27);
    obstacles.push_back(brick28);
    obstacles.push_back(brick29);
    obstacles.push_back(brick30);
    obstacles.push_back(flag);

    damagingObstacles.push_back(spike1);
    damagingObstacles.push_back(spike2);
    damagingObstacles.push_back(spike3);
    damagingObstacles.push_back(spike4);
    damagingObstacles.push_back(spike5);
    damagingObstacles.push_back(muncher1);
    damagingObstacles.push_back(muncher2);
    damagingObstacles.push_back(lava1);
    damagingObstacles.push_back(lava2);
    damagingObstacles.push_back(lava3);
    damagingObstacles.push_back(lava4);
    damagingObstacles.push_back(lava5);
    damagingObstacles.push_back(lava6);
    damagingObstacles.push_back(lava7);
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
    brick5->set_texture("Bricks.png");
    brick6->set_texture("Bricks.png");
    brick7->set_texture("Bricks.png");
    brick8->set_texture("Bricks.png");
    brick9->set_texture("Bricks.png");
    brick10->set_texture("Bricks.png");
    brick11->set_texture("Bricks.png");
    brick12->set_texture("Bricks.png");
    brick13->set_texture("Bricks.png");
    brick14->set_texture("Bricks.png");
    brick15->set_texture("Bricks.png");
    brick16->set_texture("Bricks.png");
    brick17->set_texture("Bricks.png");
    brick18->set_texture("Bricks.png");
    brick19->set_texture("Bricks.png");
    brick20->set_texture("Bricks.png");
    brick21->set_texture("Bricks.png");
    brick22->set_texture("Bricks.png");
    brick23->set_texture("Bricks.png");
    brick24->set_texture("Bricks.png");
    brick25->set_texture("Bricks.png");
    brick26->set_texture("Bricks.png");
    brick27->set_texture("Bricks.png");
    brick28->set_texture("Bricks.png");
    brick29->set_texture("Bricks.png");
    brick30->set_texture("Bricks.png");

    movingObstacles[0]->set_texture("Bricks.png");
    movingObstacles[1]->set_texture("Bricks.png");
    movingObstacles[2]->set_texture("goomba.png");

    spike1->set_texture("Thwomp.png");
    spike2->set_texture("spike.png");
    spike3->set_texture("spike.png");
    spike4->set_texture("spike.png");
    spike5->set_texture("spike.png");
    muncher1->set_texture("muncher.png");
    muncher2->set_texture("muncher.png");
    lava1->set_texture("lava.png");
    lava2->set_texture("lava.png");
    lava3->set_texture("lava.png");
    lava4->set_texture("lava.png");
    lava5->set_texture("lava.png");
    lava6->set_texture("lava.png");
    lava7->set_texture("lava.png");
    flag->set_texture("pole.png");
    powerUpBlock->set_texture("QuestionBlock.png");

    //Testing with making top brick layer really thin
    brick1->getSprite().setScale(0.4f, 0.20f);
    brick1->getSprite().setPosition(400, 608);
    
    brick2->getSprite().setScale(0.4f, 0.01f);
    brick2->getSprite().setPosition(400, 605);

    brick3->getSprite().setScale(0.4f, 0.20f);
    brick3->getSprite().setPosition(600, 378);
    
    brick4->getSprite().setScale(0.4f, 0.01f);
    brick4->getSprite().setPosition(600, 375);

    brick5->getSprite().setScale(0.4f, 0.20f);
    brick5->getSprite().setPosition(1000, 378);

    brick6->getSprite().setScale(0.4f, 0.01f);
    brick6->getSprite().setPosition(1000, 375);

    brick7->getSprite().setScale(0.4f, 0.20f);
    brick7->getSprite().setPosition(3000, 583);

    brick8->getSprite().setScale(0.4f, 0.01f);
    brick8->getSprite().setPosition(3000, 580);

    brick9->getSprite().setScale(0.4f, 0.20f);
    brick9->getSprite().setPosition(4000, 653);

    brick10->getSprite().setScale(0.4f, 0.01f);
    brick10->getSprite().setPosition(4000, 650);

    brick11->getSprite().setScale(0.4f, 0.20f);
    brick11->getSprite().setPosition(4200, 453);

    brick12->getSprite().setScale(0.4f, 0.01f);
    brick12->getSprite().setPosition(4200, 450);

    brick13->getSprite().setScale(0.2f, 0.20f);
    brick13->getSprite().setPosition(6000, 653);

    brick14->getSprite().setScale(0.2f, 0.01f);
    brick14->getSprite().setPosition(6000, 650);

    brick15->getSprite().setScale(0.15f, 0.20f);
    brick15->getSprite().setPosition(6250, 553);

    brick16->getSprite().setScale(0.15f, 0.01f);
    brick16->getSprite().setPosition(6250, 550);

    brick17->getSprite().setScale(0.10f, 0.20f);
    brick17->getSprite().setPosition(6450, 403);

    brick18->getSprite().setScale(0.10f, 0.01f);
    brick18->getSprite().setPosition(6450, 400);

    brick19->getSprite().setScale(0.15f, 0.20f);
    brick19->getSprite().setPosition(6650, 553);

    brick20->getSprite().setScale(0.15f, 0.01f);
    brick20->getSprite().setPosition(6650, 550);

    brick21->getSprite().setScale(0.2f, 0.20f);
    brick21->getSprite().setPosition(6900, 653);

    brick22->getSprite().setScale(0.2f, 0.01f);
    brick22->getSprite().setPosition(6900, 650);

    brick23->getSprite().setScale(0.4f, 0.20f);
    brick23->getSprite().setPosition(7500, 653);

    brick24->getSprite().setScale(0.4f, 0.01f);
    brick24->getSprite().setPosition(7500, 650);

    brick25->getSprite().setScale(0.4f, 0.20f);
    brick25->getSprite().setPosition(7800, 453);

    brick26->getSprite().setScale(0.4f, 0.01f);
    brick26->getSprite().setPosition(7800, 450);

    brick27->getSprite().setScale(0.4f, 0.20f);
    brick27->getSprite().setPosition(8100, 253);

    brick28->getSprite().setScale(0.4f, 0.01f);
    brick28->getSprite().setPosition(8100, 250);

    brick29->getSprite().setScale(0.4f, 0.20f);
    brick29->getSprite().setPosition(10800, 253);

    brick30->getSprite().setScale(0.4f, 0.01f);
    brick30->getSprite().setPosition(10800, 250);

    movingObstacles[0]->getSprite().setPosition(8800, 250);
    movingObstacles[0]->getSprite().setScale(0.4f, 0.01f);
    
    movingObstacles[1]->getSprite().setScale(0.4f, 0.20f);
    movingObstacles[1]->getSprite().setPosition(8800, 253);

    movingObstacles[2]->getSprite().setScale(0.3f, 0.3f);
    movingObstacles[2]->getSprite().setPosition(5000, 730);

    spike1->getSprite().setScale(1.f, 1.f);
    spike1->getSprite().setPosition(4500, 700);

    spike2->getSprite().setScale(3.f, 3.f);
    spike2->getSprite().setPosition(450, 750);
    
    spike3->getSprite().setScale(3.f, 3.f);
    spike3->getSprite().setPosition(540, 570);
    
    spike4->getSprite().setScale(3.f, 3.f);
    spike4->getSprite().setPosition(2300, 770);

    spike5->getSprite().setScale(3.f, 3.f);
    spike5->getSprite().setPosition(3000, 770);

    muncher1->getSprite().setScale(3.5f, 3.5f);
    muncher1->getSprite().setPosition(1700, 750);

    muncher2->getSprite().setScale(4.f, 4.f);
    muncher2->getSprite().setPosition(3200, 530);

    lava1->getSprite().setScale(1.f, 1.f);
    lava1->getSprite().setPosition(700, 790);

    lava2->getSprite().setScale(0.1f, 1.f);
    lava2->getSprite().setPosition(2000, 790);

    lava3->getSprite().setScale(1.f, 1.f);
    lava3->getSprite().setPosition(6200, 790);

    lava4->getSprite().setScale(1.f, 1.f);
    lava4->getSprite().setPosition(8000, 790);

    lava5->getSprite().setScale(1.f, 1.f);
    lava5->getSprite().setPosition(8800, 790);

    lava6->getSprite().setScale(0.15f, 1.f);
    lava6->getSprite().setPosition(2000, 790);

    lava7->getSprite().setScale(0.15f, 1.f);
    lava7->getSprite().setPosition(2000, 790);

    flag->getSprite().setPosition(9900, 530);
    
    powerUpBlock->getSprite().setScale(3.0f, 3.0f);
    powerUpBlock->getSprite().setPosition(1600, 600);

    
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
    Obstacle* brick7 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick8 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick9 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick10 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick11 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick12 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick13 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick14 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick15 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick16 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick17 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick18 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick19 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick20 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick21 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick22 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick23 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick24 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick25 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick26 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick27 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick28 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick29 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick30 = new Obstacle(600, 500, 64, 64, window);

    Obstacle* flag = new Obstacle(10000, 600, 64, 64, window);

    DamagingObstacle* spike1 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* spike2 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* spike3 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* spike4 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* spike5 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* muncher1 = new DamagingObstacle(400, 600, 64, 64, window, 10);    
    DamagingObstacle* muncher2 = new DamagingObstacle(400, 600, 64, 64, window, 10);            
    DamagingObstacle* lava1 = new DamagingObstacle(400, 600, 64, 64, window, 10);
    DamagingObstacle* lava2 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava3 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava4 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava5 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava6 = new DamagingObstacle(400, 600, 10, 64, window, 10);
    DamagingObstacle* lava7 = new DamagingObstacle(400, 600, 10, 64, window, 10);

    PowerUpBlock* powerUpBlock = new PowerUpBlock(1500, 600, 64, 64, window, 99);

    movingObstacles = new MovingObstacle*[3];
    movingObstacles[0] = new MovingObstacle(8800, 250, 64, 64, window, 2, 0, 8400, 9300, false);
    movingObstacles[1] = new MovingObstacle(8800, 250, 64, 64, window, 0, 0, 8400, 9300, false);
    movingObstacles[2] = new MovingObstacle(5000, 730, 64, 64, window, 1, 0, 1000, 2000, true);

    movingObstacleBoundingbox = new BoundingBox*[3];
    movingObstacleBoundingbox[0] = new BoundingBox(movingObstacles[0]->getSprite());
    movingObstacleBoundingbox[1] = new BoundingBox(movingObstacles[1]->getSprite());
    movingObstacleBoundingbox[2] = new BoundingBox(movingObstacles[2]->getSprite());

    obstacles.push_back(brick1);
    obstacles.push_back(brick2);
    obstacles.push_back(brick3);
    obstacles.push_back(brick4);
    obstacles.push_back(brick5);
    obstacles.push_back(brick6);
    obstacles.push_back(brick7);
    obstacles.push_back(brick8);
    obstacles.push_back(brick9);
    obstacles.push_back(brick10);
    obstacles.push_back(brick11);
    obstacles.push_back(brick12);
    obstacles.push_back(brick13);
    obstacles.push_back(brick14);
    obstacles.push_back(brick15);
    obstacles.push_back(brick16);
    obstacles.push_back(brick17);
    obstacles.push_back(brick18);
    obstacles.push_back(brick19);
    obstacles.push_back(brick20);
    obstacles.push_back(brick21);
    obstacles.push_back(brick22);
    obstacles.push_back(brick23);
    obstacles.push_back(brick24);
    obstacles.push_back(brick25);
    obstacles.push_back(brick26);
    obstacles.push_back(brick27);
    obstacles.push_back(brick28);
    obstacles.push_back(brick29);
    obstacles.push_back(brick30);
    obstacles.push_back(flag);

    damagingObstacles.push_back(spike1);
    damagingObstacles.push_back(spike2);
    damagingObstacles.push_back(spike3);
    damagingObstacles.push_back(spike4);
    damagingObstacles.push_back(spike5);
    damagingObstacles.push_back(muncher1);
    damagingObstacles.push_back(muncher2);
    damagingObstacles.push_back(lava1);
    damagingObstacles.push_back(lava2);
    damagingObstacles.push_back(lava3);
    damagingObstacles.push_back(lava4);
    damagingObstacles.push_back(lava5);
    damagingObstacles.push_back(lava6);
    damagingObstacles.push_back(lava7);
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
    brick5->set_texture("Bricks.png");
    brick6->set_texture("Bricks.png");
    brick7->set_texture("Bricks.png");
    brick8->set_texture("Bricks.png");
    brick9->set_texture("Bricks.png");
    brick10->set_texture("Bricks.png");
    brick11->set_texture("Bricks.png");
    brick12->set_texture("Bricks.png");
    brick13->set_texture("Bricks.png");
    brick14->set_texture("Bricks.png");
    brick15->set_texture("Bricks.png");
    brick16->set_texture("Bricks.png");
    brick17->set_texture("Bricks.png");
    brick18->set_texture("Bricks.png");
    brick19->set_texture("Bricks.png");
    brick20->set_texture("Bricks.png");
    brick21->set_texture("Bricks.png");
    brick22->set_texture("Bricks.png");
    brick23->set_texture("Bricks.png");
    brick24->set_texture("Bricks.png");
    brick25->set_texture("Bricks.png");
    brick26->set_texture("Bricks.png");
    brick27->set_texture("Bricks.png");
    brick28->set_texture("Bricks.png");
    brick29->set_texture("Bricks.png");
    brick30->set_texture("Bricks.png");

    movingObstacles[0]->set_texture("Bricks.png");
    movingObstacles[1]->set_texture("Bricks.png");
    movingObstacles[2]->set_texture("goomba.png");

    spike1->set_texture("Thwomp.png");
    spike2->set_texture("spike.png");
    spike3->set_texture("spike.png");
    spike4->set_texture("spike.png");
    spike5->set_texture("spike.png");
    muncher1->set_texture("muncher.png");
    muncher2->set_texture("muncher.png");
    lava1->set_texture("lava.png");
    lava2->set_texture("lava.png");
    lava3->set_texture("lava.png");
    lava4->set_texture("lava.png");
    lava5->set_texture("lava.png");
    lava6->set_texture("lava.png");
    lava7->set_texture("lava.png");
    flag->set_texture("pole.png");
    powerUpBlock->set_texture("QuestionBlock.png");

    //Testing with making top brick layer really thin
    brick1->getSprite().setScale(0.4f, 0.20f);
    brick1->getSprite().setPosition(400, 608);
    
    brick2->getSprite().setScale(0.4f, 0.01f);
    brick2->getSprite().setPosition(400, 605);

    brick3->getSprite().setScale(0.4f, 0.20f);
    brick3->getSprite().setPosition(600, 378);
    
    brick4->getSprite().setScale(0.4f, 0.01f);
    brick4->getSprite().setPosition(600, 375);

    brick5->getSprite().setScale(0.4f, 0.20f);
    brick5->getSprite().setPosition(1000, 378);

    brick6->getSprite().setScale(0.4f, 0.01f);
    brick6->getSprite().setPosition(1000, 375);

    brick7->getSprite().setScale(0.4f, 0.20f);
    brick7->getSprite().setPosition(3000, 583);

    brick8->getSprite().setScale(0.4f, 0.01f);
    brick8->getSprite().setPosition(3000, 580);

    brick9->getSprite().setScale(0.4f, 0.20f);
    brick9->getSprite().setPosition(4000, 653);

    brick10->getSprite().setScale(0.4f, 0.01f);
    brick10->getSprite().setPosition(4000, 650);

    brick11->getSprite().setScale(0.4f, 0.20f);
    brick11->getSprite().setPosition(4200, 453);

    brick12->getSprite().setScale(0.4f, 0.01f);
    brick12->getSprite().setPosition(4200, 450);

    brick13->getSprite().setScale(0.2f, 0.20f);
    brick13->getSprite().setPosition(6000, 653);

    brick14->getSprite().setScale(0.2f, 0.01f);
    brick14->getSprite().setPosition(6000, 650);

    brick15->getSprite().setScale(0.15f, 0.20f);
    brick15->getSprite().setPosition(6250, 553);

    brick16->getSprite().setScale(0.15f, 0.01f);
    brick16->getSprite().setPosition(6250, 550);

    brick17->getSprite().setScale(0.10f, 0.20f);
    brick17->getSprite().setPosition(6450, 403);

    brick18->getSprite().setScale(0.10f, 0.01f);
    brick18->getSprite().setPosition(6450, 400);

    brick19->getSprite().setScale(0.15f, 0.20f);
    brick19->getSprite().setPosition(6650, 553);

    brick20->getSprite().setScale(0.15f, 0.01f);
    brick20->getSprite().setPosition(6650, 550);

    brick21->getSprite().setScale(0.2f, 0.20f);
    brick21->getSprite().setPosition(6900, 653);

    brick22->getSprite().setScale(0.2f, 0.01f);
    brick22->getSprite().setPosition(6900, 650);

    brick23->getSprite().setScale(0.4f, 0.20f);
    brick23->getSprite().setPosition(7500, 653);

    brick24->getSprite().setScale(0.4f, 0.01f);
    brick24->getSprite().setPosition(7500, 650);

    brick25->getSprite().setScale(0.4f, 0.20f);
    brick25->getSprite().setPosition(7800, 453);

    brick26->getSprite().setScale(0.4f, 0.01f);
    brick26->getSprite().setPosition(7800, 450);

    brick27->getSprite().setScale(0.4f, 0.20f);
    brick27->getSprite().setPosition(8100, 253);

    brick28->getSprite().setScale(0.4f, 0.01f);
    brick28->getSprite().setPosition(8100, 250);

    brick29->getSprite().setScale(0.4f, 0.20f);
    brick29->getSprite().setPosition(10800, 253);

    brick30->getSprite().setScale(0.4f, 0.01f);
    brick30->getSprite().setPosition(10800, 250);

    movingObstacles[0]->getSprite().setPosition(8800, 250);
    movingObstacles[0]->getSprite().setScale(0.4f, 0.01f);
    
    movingObstacles[1]->getSprite().setScale(0.4f, 0.20f);
    movingObstacles[1]->getSprite().setPosition(8800, 253);

    movingObstacles[2]->getSprite().setScale(0.3f, 0.3f);
    movingObstacles[2]->getSprite().setPosition(5000, 730);

    spike1->getSprite().setScale(1.f, 1.f);
    spike1->getSprite().setPosition(4500, 700);

    spike2->getSprite().setScale(3.f, 3.f);
    spike2->getSprite().setPosition(450, 750);
    
    spike3->getSprite().setScale(3.f, 3.f);
    spike3->getSprite().setPosition(540, 570);
    
    spike4->getSprite().setScale(3.f, 3.f);
    spike4->getSprite().setPosition(2300, 770);

    spike5->getSprite().setScale(3.f, 3.f);
    spike5->getSprite().setPosition(3000, 770);

    muncher1->getSprite().setScale(3.5f, 3.5f);
    muncher1->getSprite().setPosition(1700, 750);

    muncher2->getSprite().setScale(4.f, 4.f);
    muncher2->getSprite().setPosition(3200, 530);

    lava1->getSprite().setScale(1.f, 1.f);
    lava1->getSprite().setPosition(700, 790);

    lava2->getSprite().setScale(0.1f, 1.f);
    lava2->getSprite().setPosition(2000, 790);

    lava3->getSprite().setScale(1.f, 1.f);
    lava3->getSprite().setPosition(6200, 790);

    lava4->getSprite().setScale(1.f, 1.f);
    lava4->getSprite().setPosition(8000, 790);

    lava5->getSprite().setScale(1.f, 1.f);
    lava5->getSprite().setPosition(8800, 790);

    lava6->getSprite().setScale(0.15f, 1.f);
    lava6->getSprite().setPosition(2000, 790);

    lava7->getSprite().setScale(0.15f, 1.f);
    lava7->getSprite().setPosition(2000, 790);

    flag->getSprite().setPosition(9900, 530);
    
    powerUpBlock->getSprite().setScale(3.0f, 3.0f);
    powerUpBlock->getSprite().setPosition(1600, 600);

    
    if (!backgroundTexture.loadFromFile("Level3BG.png")) {
        std::cout << "Background load failed for level 1" << std::endl;
    }


    backgroundSprite.setTexture(backgroundTexture);

    backgroundSprite.setPosition(-500, -200);
}



void Levels::Update(float marioX) {
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

    for (int i = 0; i < 3; i++){
        movingObstacles[i]->update(marioX);
        movingObstacleBoundingbox[i]->update(movingObstacles[i]->getSprite());
    }
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

    for (int i = 0; i < 3; i++){
        window.draw(movingObstacles[i]->getSprite());
        movingObstacleBoundingbox[i]->draw(window);
    }
}

Levels::~Levels(){
    for (auto obstacle : obstacles) {
        delete obstacle;
    }
    for (auto boundingBox : BoundingBoxes) {
        delete boundingBox;
    }

    for (int i = 0; i < 3; i++){
        delete movingObstacles[i];
        delete movingObstacleBoundingbox[i];
    }

    for (auto powerUpBlock : PowerUpBlocks) {
        delete powerUpBlock;
    }

}

void Levels::ClearLevel() {
    obstacles.clear();
    BoundingBoxes.clear();
    damagingObstacles.clear();
    BoundingBoxesDamagingObstacles.clear();
    BoundingBoxesPowerUpBlocks.clear();
    PowerUpBlocks.clear();

    for (int i = 0; i < 3; i++){
        delete movingObstacles[i];
        delete movingObstacleBoundingbox[i];
    }
}
