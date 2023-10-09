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
#include "GameStats.h"
#include "BoundingBox.h"

class Levels {
private:
    sf::RenderWindow& window;

    std::vector<Obstacle*> obstacles;
    std::vector<BoundingBox*> BoundingBoxes;

    // game world size (levels might have different sizes)
    float gameWorldWidth;

public:
    Levels(sf::RenderWindow& window);
    ~Levels();
    
    void LoadLevel1();
    void LoadLevel2();
    void LoadLevel3();
    void LoadLevel4();
    void LoadLevel5();

    void ClearLevel();

    std::vector<std::function<void()>> levelLoadFunctions;
    
    void Update();
    void Render(sf::RenderWindow& window);

    std::vector<Obstacle*>& getObstacles() { return obstacles; }
    std::vector<BoundingBox*>& getBoundingBoxes() { return BoundingBoxes; }

    float getGameWorldWidth();
    void setGameWorldWidth(float Width);
    
};


#endif
