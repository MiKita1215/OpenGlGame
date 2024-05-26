#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include "player.h"

class Input {
public:
    static void processInput(GLFWwindow* window, Player* player, float deltaTime);
};

#endif // INPUT_H
