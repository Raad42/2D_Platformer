#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
protected:
    int x_position;
    int y_position;
    int width;
    int height;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Entity(int x, int y, int width, int height);
    virtual ~Entity();

    virtual bool IsColliding(Entity* other) = 0;
    virtual void OnCollision(Entity* other) = 0;

    int get_x_position();
    int get_y_position();
    int get_width();
    int get_height();
    void set_texture(const std::string& texturePath);

    sf::Sprite& getSprite();
};

#endif
