//
// Created by Joseph Paavola on 12/13/20.
//

#ifndef PARTICLESIMULATOR_VIEWPORT_H
#define PARTICLESIMULATOR_VIEWPORT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "Object.h"
#include "Shader.h"

#include <string>
#include <vector>
#include <iostream>

class Viewport {
private:
    GLFWwindow* window;
    GLuint vertexArrayObject;
    std::vector<Camera*> cameras;
    Camera* activeCamera;
    std::vector<Object*> objects;
    glm::dvec2 lastCursorPosition;
    glm::dvec2 cursorPosition;
    glm::ivec2 dimensions;
    // TODO: allow multiple shaders
    Shader* shader;
    double* deltaTime;
    double lastFrame;

    void processInput();
public:
    Viewport(const char* name, int width, int height);
    virtual ~Viewport();

    void addObject(Object* object);
    void setShader(Shader* shader);
    Camera* getActiveCamera();
    bool shouldClose();
    void render();
};


#endif //PARTICLESIMULATOR_VIEWPORT_H
