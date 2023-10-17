#ifndef MOVINGOBSTACLE_H
#define MOVINGOBSTACLE_H

#include "Obstacle.h"

class MovingObstacle : public Obstacle {
 private:
  float velocityX;
  float velocityY;

  float maxPosition;
  float minPosition;
  bool moveUp;

  bool enemy;
  bool isDead;

  // Add moving obstacle-specific members here.
 public:
  MovingObstacle(int x, int y, int width, int height, sf::RenderWindow& window,
                 float velocityXIn, float velocityYIn, float maxPosition,
                 float minPosition, bool enemyIn);
  void update(float marioX);

  void die();

  void set_isDead(bool isDeadIn){isDead = isDeadIn;}

  bool get_isDead(){
    return isDead; }
  // Additional attributes and methods for moving obstacles.
};

#endif