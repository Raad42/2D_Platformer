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

    std::vector<Obstacle*> obstacles;
    std::vector<BoundingBox*> BoundingBoxes;
    
    MovingObstacle** movingObstacles;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    Levels(sf::RenderWindow& window);
    ~Levels();

    void LoadLevel1();
    void LoadLevel2();
    void ClearLevel(); // Cleans up resources and preps for a new level.

    // Function pointers for level loading.
    std::vector<std::function<void()>> levelLoadFunctions; 

    void Update(); 
    void Render(sf::RenderWindow& window);

    // Accessor for obstacles
    std::vector<Obstacle*>& getObstacles() { return obstacles; } 
    MovingObstacle** getmovingObstacles() { return movingObstacles; }        
};

#endif
