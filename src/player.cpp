#include "player.h"
#include <GLFW/glfw3.h>

void Player::init() {
    position = glm::vec3(0.0f, 1.0f, 0.0f);
    direction = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    speed = 5.0f;
    sensitivity = 0.1f;
}

void Player::update(float deltaTime) {
    // Implement movement, collision, and shooting logic here
}

glm::vec3 Player::getPosition() {
    return position;
}

glm::vec3 Player::getDirection() {
    return direction;
}
