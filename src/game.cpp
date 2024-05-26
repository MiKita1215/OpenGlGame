#include "game.h"

Game::Game() {
    renderer = new Renderer();
    player = new Player();
    map = new Map();
    gun = new Gun();
    minimap = new Minimap();
}

void Game::init() {
    renderer->init();
    player->init();
    map->load("assets/levels/basiclevel.png");
    gun->init();
    minimap->init();
}

void Game::update(float deltaTime) {
    player->update(deltaTime);
    gun->update(player->getPosition(), player->getDirection());
}

void Game::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderer->render(map);
    renderer->render(player);
    renderer->render(gun);
    renderer->render(minimap);
}

Player* Game::getPlayer() {
    return player;
}
