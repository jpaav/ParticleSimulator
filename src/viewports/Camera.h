//
// Created by Joseph Paavola on 12/13/20.
//

#ifndef PARTICLESIMULATOR_CAMERA_H
#define PARTICLESIMULATOR_CAMERA_H


//OpenGL libraries
#include "GLFW/glfw3.h"
//GLM libraries
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define TURNTABLE_MODE 1
#define INPUT_MODE 2
#define STATIC_MODE 3
#define PERSP_TYPE 1
#define ORTHO_TYPE 2

class Camera {
private:
    glm::vec3 position{};
    glm::vec3 focusPoint{};
    float nClip;
    float fClip;
    int width{};
    int height{};
    float *deltaTime;
    float verticalAngle;
    float horizontalAngle;
    float speed;
    float mouseSpeed;
    double xpos{}, ypos{};
public:
    glm::vec3 up{};
    glm::vec3 right{};
    glm::vec3 forward{};
    int mode;
    int type;
    float fov;

    Camera();

    void updatePos();

    glm::mat4 cameraMatrix();

    glm::mat4 dynamicCameraMatrix();
    //glm::mat4 tableTurn();

    void setPos(glm::vec3 p) { position = p; }

    glm::vec3 getPos() { return position; }

    void setDeltaTimePtr(float *dt) { deltaTime = dt; }

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
