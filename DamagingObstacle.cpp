#include "DamagingObstacle.h"

DamagingObstacle::DamagingObstacle(int x, int y, int width, int height, int damage)
    : Obstacle(x, y, width, height), damage(damage) {
    // Initialize damaging obstacle-specific members here.
}
