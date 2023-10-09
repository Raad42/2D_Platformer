#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Obstacle : public Entity {
private:
    sf::RenderWindow& window;
public:
    Obstacle();
    Obstacle(int x, int y, int width, int height, sf::RenderWindow& window);
    ~Obstacle();

    virtual void update();
    bool IsColliding(Entity* other) override;
    void OnCollision(Entity* other) override;
};

#endif
