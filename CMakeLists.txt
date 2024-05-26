cmake_minimum_required(VERSION 3.10)
project(FPSGame)

set(CMAKE_CXX_STANDARD 11)

# Define sources and headers
set(SOURCES
    src/main.cpp
    src/game.cpp
    src/renderer.cpp
    src/camera.cpp
    src/input.cpp
    src/minimap.cpp
    src/player.cpp
    src/map.cpp
    src/gun.cpp
    src/utils/shader.cpp
    src/utils/texture.cpp
    src/utils/logger.cpp
)

set(HEADERS
    src/game.h
    src/renderer.h
    src/camera.h
    src/input.h
    src/minimap.h
    src/player.h
    src/map.h
    src/gun.h
    src/utils/shader.h
    src/utils/texture.h
    src/utils/logger.h
)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find GLFW
find_package(GLFW3 REQUIRED)

# Find GLM
find_package(glm REQUIRED)

# Add executable
add_executable(FPSGame ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(FPSGame ${OPENGL_LIBRARIES} glfw glm::glm)
