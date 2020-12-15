//
// Created by Joseph Paavola on 12/13/20.
//

#ifndef PARTICLESIMULATOR_VIEWPORT_H
#define PARTICLESIMULATOR_VIEWPORT_H

#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "Camera.h"
#include "Object.h"
#include "Shader.h"


class Viewport {
private:
    GLFWwindow* window;
    std::vector<Camera*> cameras;
    Camera* activeCamera;
    std::vector<Object*> objects;
    glm::dvec2 cursorPosition;
    // TODO: allow multiple shaders
    Shader* shader;
public:
    Viewport(std::string name, int width, int height);

    glm::dvec2 getCursorPosition();

    void addObject(Object* object);
    void setShader(Shader* shader);
    bool shouldClose();
    void render();

    virtual ~Viewport();
};


#endif //PARTICLESIMULATOR_VIEWPORT_H
