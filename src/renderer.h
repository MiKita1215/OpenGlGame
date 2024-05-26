#ifndef RENDERER_H
#define RENDERER_H

#include "map.h"
#include "player.h"
#include "gun.h"
#include "minimap.h"

class Renderer {
public:
    void init();
    void render(Map* map);
    void render(Player* player);
    void render(Gun* gun);
    void render(Minimap* minimap);
};

#endif // RENDERER_H
