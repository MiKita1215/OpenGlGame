#ifndef PLAYER_H
#define PLAYER_H

#include <glm/glm.hpp>

class Player {
public:
    void init();
    void update(float deltaTime);
    glm::vec3 getPosition();
    glm::vec3 getDirection();
private:
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 up;
    float speed;
    float sensitivity;
};

#endif // PLAYER_H
