#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.h"
#include "input.h"
#include "player.h"

// Callback function to adjust viewport size when the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Set OpenGL version to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "FPS Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, 800, 600);

    // Set the callback function for window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize the game
    Game game;
    game.init();

    // Capture the mouse cursor
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Main game loop
    while (!glfwWindowShouldClose(window)) {
        // Calculate delta time
        static double lastTime = glfwGetTime();
        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);
        lastTime = currentTime;

        // Process input
        Input::processInput(window, game.getPlayer(), deltaTime);

        // Update game state
        game.update(deltaTime);

        // Render game
        game.render();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and exit
    glfwTerminate();
    return 0;
}
