//
// Created by Joseph Paavola on 12/13/20.
//

#ifndef PARTICLESIMULATOR_CAMERA_H
#define PARTICLESIMULATOR_CAMERA_H


#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>


enum CameraModes {
    TURNTABLE_MODE,
    INPUT_MODE,
    STATIC_MODE
};

class Camera {
private:
    double* deltaTime;
    glm::vec3 position;
    glm::vec3 focusPoint;
    float nClip;
    float fClip;
    int width;
    int height;
    double verticalAngle;
    double horizontalAngle;
    double speed;
    double mouseSpeed;
public:
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 forward;
    int mode;
    float fov;

    Camera(double *dt);

    void update(glm::dvec2 deltaCursorPosition);

    glm::mat4 cameraMatrix(glm::ivec2 &dimensions);

    void setMode(CameraModes mode);

    glm::vec3 getPos() { return position; }

    void moveForward();

    void moveBackward();

    void moveRight();

    void moveLeft();

    void moveUp();

    void moveDown();

};


#endif //PARTICLESIMULATOR_CAMERA_H
