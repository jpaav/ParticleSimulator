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

#define PERSP_TYPE 1
#define ORTHO_TYPE 2

class Camera {
private:
    glm::vec3 position;
    glm::vec3 focusPoint;
    float nClip;
    float fClip;
    int width;
    int height;
    float *deltaTime;
    float verticalAngle;
    float horizontalAngle;
    float speed;
    float mouseSpeed;
public:
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 forward;
    int mode;
    int type;
    float fov;

    Camera();

    void updatePos(glm::dvec2 &cursorPosition, glm::ivec2 &dimensions);

    glm::mat4 cameraMatrix(glm::ivec2 &dimensions);

    void setDeltaTimePtr(float *dt) { deltaTime = dt; }

    void setMode(CameraModes mode);

    glm::vec3 getPos() { return position; }

    void moveForward();

    void moveBackward();

    void moveRight();

    void moveLeft();

    void moveWest(float);

    void moveEast(float);

    void moveNorth(float);

    void moveSouth(float);

    void moveUp(float);

    void moveDown(float);

    void rotateLeft(float);

    void rotateRight(float);

};


#endif //PARTICLESIMULATOR_CAMERA_H
