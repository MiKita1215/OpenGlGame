#include "input.h"
#include <glm/gtc/matrix_transform.hpp>

void Input::processInput(GLFWwindow* window, Player* player, float deltaTime) {
    float velocity = player->getSpeed() * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        player->setPosition(player->getPosition() + player->getDirection() * velocity);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        player->setPosition(player->getPosition() - player->getDirection() * velocity);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        player->setPosition(player->getPosition() - glm::normalize(glm::cross(player->getDirection(), player->getUp())) * velocity);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        player->setPosition(player->getPosition() + glm::normalize(glm::cross(player->getDirection(), player->getUp())) * velocity);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        player->setPosition(player->getPosition() + player->getUp() * velocity);
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        player->setPosition(player->getPosition() - player->getUp() * velocity);

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    static bool firstMouse = true;
    static float lastX = 400, lastY = 300;

    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    xoffset *= player->getSensitivity();
    yoffset *= player->getSensitivity();

    glm::vec3 front;
    front.x = cos(glm::radians(player->getYaw())) * cos(glm::radians(player->getPitch()));
    front.y = sin(glm::radians(player->getPitch()));
    front.z = sin(glm::radians(player->getYaw())) * cos(glm::radians(player->getPitch()));
    player->setDirection(glm::normalize(front));
}
