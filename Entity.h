#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::Sprite sprite;

public:
    virtual void draw(sf::RenderWindow& window);
    virtual sf::Sprite getSprite() const;
    virtual bool isColliding(const Entity& other) const = 0;
    virtual void onCollision(Entity& other) = 0;
};

#endif
