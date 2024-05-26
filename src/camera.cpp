#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>

void Camera::init() {
    position = glm::vec3(0.0f, 0.0f, 3.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    yaw = -90.0f;
    pitch = 0.0f;
    speed = 2.5f;
    sensitivity = 0.1f;
}

void Camera::update(float deltaTime) {
    // Implement camera movement logic here
}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::getProjectionMatrix() {
    return glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}
