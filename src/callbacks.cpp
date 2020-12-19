//
// Created by Joseph Paavola on 12/13/20.
//

#include "callbacks.h"

void error_callback(int code, const char* description)
{
    std::cerr << "ERROR (" << code << "): " << description << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto v = static_cast<Viewport*>(glfwGetWindowUserPointer(window));

    // Escape
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    // Change input mode
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) {
        v->getActiveCamera()->cycleMode();
    }
}
