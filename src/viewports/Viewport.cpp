//
// Created by Joseph Paavola on 12/13/20.
//

#include "Viewport.h"
#include <iostream>
#include <stdlib.h>

Viewport::Viewport() {
    this->window = glfwCreateWindow(640, 480, "Viewport", NULL, NULL);
    if (!this->window)
    {
        glfwTerminate();
        std::cerr << "Failed to initialize window." << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(this->window);
}

Viewport::Viewport(std::string name, int width, int height) {
    this->window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if (!this->window)
    {
        glfwTerminate();
        std::cerr << "Failed to initialize window." << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(this->window);
}

Viewport::~Viewport() {
    glfwDestroyWindow(this->window);
}

bool Viewport::shouldClose() {
    return glfwWindowShouldClose(this->window);
}

void Viewport::render() {
    glfwMakeContextCurrent(this->window);
    // RENDER HERE
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
}