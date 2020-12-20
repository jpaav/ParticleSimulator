//
// Created by Joseph Paavola on 12/13/20.
//

#ifndef PARTICLESIMULATOR_VIEWPORT_H
#define PARTICLESIMULATOR_VIEWPORT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "../objects/Object.fwd.h"
#include "../objects/Object.h"
#include "Shader.h"
#include "../callbacks.h"
#include "Light.h"

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
    // TODO: allow multiple lights
    Light* light;

    glm::dvec2 lastCursorPosition;
    glm::dvec2 cursorPosition;
    glm::ivec2 dimensions;
    // TODO: allow multiple shaders
    Shader* shader;
    double* deltaTime;
    double lastFrame;
public:
    glm::vec3 ambientColor;

    Viewport(const char* name, int width, int height);
    virtual ~Viewport();

    void addObject(Object* object);
    void setShader(Shader* shader);
    Camera* getActiveCamera();
    bool shouldClose();
    void render();

    glm::mat4 getCameraMatrix();

    Shader * getShader();

    Light *getLight();
};


#endif //PARTICLESIMULATOR_VIEWPORT_H
