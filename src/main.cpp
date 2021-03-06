#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <map>
#include "viewports/Viewport.h"
#include "callbacks.h"
#include "objects/EmptyObject.h"
#include "materials/PhongMaterial.h"
#include "viewports/PhysicsViewport.h"
#include "objects/WireObject.h"

// TODO: support this author: https://www.paypal.com/paypalme/learnopengl/

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
    viewports["main"] = new PhysicsViewport("Particle Simulator", 1440, 900);

    // Setup shaders
    auto simpleShader = new Shader("/Users/josephpaavola/CLionProjects/ParticleSimulator/src/shaders/simple_v.glsl",
                                   "/Users/josephpaavola/CLionProjects/ParticleSimulator/src/shaders/simple_f.glsl");
    viewports["main"]->addShader("simple", simpleShader);
    auto phongShader = new Shader("/Users/josephpaavola/CLionProjects/ParticleSimulator/src/shaders/phong_v.glsl",
                                  "/Users/josephpaavola/CLionProjects/ParticleSimulator/src/shaders/phong_f.glsl");
    viewports["main"]->addShader("phong", phongShader);
    auto vertexShader = new Shader("/Users/josephpaavola/CLionProjects/ParticleSimulator/src/shaders/vertex_v.glsl",
                                  "/Users/josephpaavola/CLionProjects/ParticleSimulator/src/shaders/vertex_f.glsl");
    viewports["main"]->addShader("vertex", vertexShader);

    // Setup materials
    viewports["main"]->addMaterial(
            "phong",
            new PhongMaterial(
                    glm::vec3(0.2, 0.05, 0.7),
                    glm::vec3(0.2, 0.05, 0.7),
                    glm::vec3(0.0, 0.0, 0.0),
                    0.0,
                    phongShader
            )
    );

    // Setup objects
//    viewports["main"]->addObject(
//            new MeshObject("/Users/josephpaavola/CLionProjects/ParticleSimulator/src/objects/meshes/icosphere.obj",
//                           viewports["main"]->getMaterial("phong")));

//    viewports["main"]->addObject(new WireObject());
    dynamic_cast<PhysicsViewport*>(viewports["main"])->addField("magnetic", new FieldObject(10, 1.0, 10, false, false));


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
