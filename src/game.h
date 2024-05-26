#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "player.h"
#include "map.h"
#include "gun.h"
#include "minimap.h"

class Game {
public:
    Game();
    void init();
    void update(float deltaTime);
    void render();
    Player* getPlayer();
private:
    Renderer* renderer;
    Player* player;
    Map* map;
    Gun* gun;
    Minimap* minimap;
};

#endif // GAME_H
