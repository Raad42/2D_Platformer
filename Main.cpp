#include "Entity.h"
#include "Character.h"
#include "Obstacle.h"
#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "GameStats.h"
#include "Game.h"

int main() {
    Game game;
    game.run();

    Player player(0.0f, 0.0f);
    player.loadTexture("8bitMario.png");


    return 0;
}
