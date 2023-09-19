#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Obstacle : public Entity {
public:
    virtual bool isColliding(const Entity& other) const override;
    virtual void onCollision(Entity& other) override;
};

#endif
