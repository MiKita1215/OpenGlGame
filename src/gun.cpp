#include "gun.h"

void Gun::init() {
    // Initialize gun resources here
}

void Gun::update(glm::vec3 playerPosition, glm::vec3 playerDirection) {
    // Update gun position and direction based on player
    position = playerPosition;
    direction = playerDirection;
}

void Gun::render() {
    // Render the gun here
}
