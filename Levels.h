#ifndef LEVELS_H
#define LEVELS_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Character.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include "MovingObstacle.h"
#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "PowerUpBlock.h"
#include "GameStats.h"
#include "BoundingBox.h"

class Levels {
private:
    sf::RenderWindow& window;
    
    // vectors to store various entities
    std::vector<Obstacle*> obstacles;
    std::vector<BoundingBox*> BoundingBoxes;

    std::vector<DamagingObstacle*> damagingObstacles;
    std::vector<BoundingBox*> BoundingBoxesDamagingObstacles;

    std::vector<PowerUpBlock*> PowerUpBlocks;
    std::vector<BoundingBox*> BoundingBoxesPowerUpBlocks;

    // pointers instead of vector for movingObstacles
    MovingObstacle** movingObstacles;
    BoundingBox**  movingObstacleBoundingbox;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    Levels(sf::RenderWindow& window);
    ~Levels();
    
    // load level
    void LoadLevel1();
    void LoadLevel2();

    // similar to destructor to clear level
    void ClearLevel();

    // vector to store functions (store level functions)
    std::vector<std::function<void()>> levelLoadFunctions;
    
    void Update();
    void Render(sf::RenderWindow& window);

    // get the objects stored in the vectors
    std::vector<Obstacle*>& getObstacles() { return obstacles; }
    std::vector<BoundingBox*>& getBoundingBoxes() { return BoundingBoxes; }

    std::vector<DamagingObstacle*>& getDamagingObstacles() { return damagingObstacles; }
    std::vector<BoundingBox*>& getBoundingBoxesDamagingObstacles() { return BoundingBoxesDamagingObstacles; }

    std::vector<PowerUpBlock*>& getPowerUpBlocks() { return PowerUpBlocks; }
    std::vector<BoundingBox*>& getBoundingBoxesPowerUpBlocks() { return BoundingBoxesPowerUpBlocks; }

    MovingObstacle** getmovingObstacles() { return movingObstacles; }
        
};


#endif