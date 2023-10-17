#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "BoundingBox.h"

class Entity {
protected:
    // attributes that all entitys in game need
    int x_position;
    int y_position;
    int width;
    int height;
    sf::Texture texture;
    sf::Sprite sprite;
    BoundingBox boundingBox;
public:
    Entity(int x, int y, int width, int height);
    virtual ~Entity();
    
    // getters and setters
    int get_x_position();
    void set_x_position(int x_position);
    int get_y_position();
    void set_y_position(int y_position);
    int get_width();
    int get_height();

    // to give sprites a texture
    void set_texture(const std::string& texturePath);
    
    sf::Sprite& getSprite();

    // all entitys in game need a bounding box for collision
    virtual BoundingBox& getBoundingox() { return boundingBox; }
    void updateBoundingBox();
    
    virtual sf::FloatRect getBoundingbox() const;

};

#endif
