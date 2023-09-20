#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity {
private:
    int x_position;
    int y_position;
    int width;
    int height;
public:
    Entity(int x, int y, int width, int height);
    virtual ~Entity();

    virtual bool IsColliding(Entity* other) = 0;
    virtual void OnCollision(Entity* other) = 0;

    virtual int get_x_position();
    virtual int get_y_position();
    virtual int get_width();
    virtual int get_height();
};


#endif
