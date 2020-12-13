//
// Created by Joseph Paavola on 12/13/20.
//

#ifndef PARTICLESIMULATOR_VIEWPORT_H
#define PARTICLESIMULATOR_VIEWPORT_H

#include <GLFW/glfw3.h>
#include <string>


class Viewport {
private:
    GLFWwindow* window;
public:
    Viewport();
    Viewport(std::string name, int width, int height);

    bool shouldClose();
    void render();

    virtual ~Viewport();
};


#endif //PARTICLESIMULATOR_VIEWPORT_H
