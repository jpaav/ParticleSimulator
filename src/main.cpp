#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <map>
#include "viewports/Viewport.h"
#include "viewports/Camera.h"
#include "callbacks.h"
#include "viewports/EmptyObject.h"



int main() {
    // Init GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwSetErrorCallback(error_callback);

    std::map<std::string, Viewport *> viewports = std::map<std::string, Viewport *>();
    viewports["main"] = new Viewport("Particle Simulator", 1440, 900);

    viewports["main"]->addObject(new EmptyObject());

    auto shader = new Shader("/Users/josephpaavola/CLionProjects/ParticleSimulator/src/shaders/simple_v.glsl",
                             "/Users/josephpaavola/CLionProjects/ParticleSimulator/src/shaders/simple_f.glsl");
    viewports["main"]->setShader(shader);


    bool shouldClose = false;
    do {
        for (auto const&[name, viewport] : viewports) {
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
