#ifndef GUN_H
#define GUN_H

#include <glm/glm.hpp>

class Gun {
public:
    void init();
    void update(glm::vec3 playerPosition, glm::vec3 playerDirection);
    void render();
private:
    glm::vec3 position;
    glm::vec3 direction;
};

#endif // GUN_H
