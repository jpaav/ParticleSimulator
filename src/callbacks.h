//
// Created by Joseph Paavola on 12/13/20.
//

#ifndef PARTICLESIMULATOR_CALLBACKS_H
#define PARTICLESIMULATOR_CALLBACKS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "viewports/Viewport.h"

#include <iostream>

void error_callback(int code, const char* description);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif //PARTICLESIMULATOR_CALLBACKS_H
