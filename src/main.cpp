#include <iostream>
#include <map>
#include "viewports/Viewport.h"
#include "callbacks.h"

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    glfwSetErrorCallback(error_callback);

    std::map<std::string, Viewport*> viewports = std::map<std::string, Viewport*>();
    viewports["main"] = new Viewport("Particle Simulator", 1440, 900);

    bool shouldClose = false;
    do {
        for(auto const& [name, viewport] : viewports) {
            if (viewport->shouldClose()) {
                shouldClose = true;
            }
            viewport->render();
        }
        glfwPollEvents();
    } while (!shouldClose);

    glfwTerminate();
    return 0;
}
