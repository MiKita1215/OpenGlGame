#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
    void init();
    void update(float deltaTime);
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    float yaw;
    float pitch;
    float speed;
    float sensitivity;
};

#endif // CAMERA_H
