//
// Created by Joseph Paavola on 12/13/20.
//

#include "Viewport.h"
#include <iostream>
#include <stdlib.h>

Viewport::Viewport(std::string name, int width, int height) {
    this->window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    if (!this->window)
    {
        glfwTerminate();
        std::cerr << "Failed to initialize window." << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(this->window);
    glfwGetCursorPos(this->window, &cursorPosition[0], &cursorPosition[1]);
    this->cameras = std::vector<Camera*>();
    auto camera = new Camera();
    this->cameras.push_back(camera);
    this->activeCamera = camera;
}

Viewport::~Viewport() {
    glfwDestroyWindow(this->window);
}

bool Viewport::shouldClose() {
    return glfwWindowShouldClose(this->window);
}

void Viewport::render() {
    glfwGetCursorPos(this->window, &cursorPosition[0], &cursorPosition[1]);
    glfwMakeContextCurrent(this->window);
    // Move forward
    if (glfwGetKey( this->window, GLFW_KEY_W ) == GLFW_PRESS){
        this->activeCamera->moveForward();
        //position += direction * dt * speed;
    }
    // Move backward
    if (glfwGetKey( this->window, GLFW_KEY_S ) == GLFW_PRESS){
        this->activeCamera->moveBackward();
        //position -= direction * dt * speed;
    }
    // Strafe right
    if (glfwGetKey( this->window, GLFW_KEY_D ) == GLFW_PRESS){
        this->activeCamera->moveRight();
        //position += newRight * dt * speed;
    }
    // Strafe left
    if (glfwGetKey( this->window, GLFW_KEY_A ) == GLFW_PRESS){
        this->activeCamera->moveLeft();
        //position -= newRight * dt * speed;
    }
    std::cout << this->activeCamera->getPos()[0] << ", " << this->activeCamera->getPos()[1] << ", " << this->activeCamera->getPos()[2] << std::endl;
    for (Object* const& object : this->objects) {
        object->draw();
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
}

void Viewport::addObject(Object* object) {
    this->objects.push_back(object);
}

void Viewport::setShader(Shader* shader) {
    this->shader = shader;
}

glm::dvec2 Viewport::getCursorPosition() {
    return this->cursorPosition;
}