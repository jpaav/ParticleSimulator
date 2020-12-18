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
    /**
     * A pointer to the current delta time between the last frame and
     * the current frame.
     */
    double* deltaTime;
    /**
     * The current position of the camera.
     */
    glm::vec3 position;
    /**
     * The closest distance the camera will render, everything closer is
     * clipped.
     */
    float nClip;
    /**
     * The farthest distance the camera will render, everything farther is
     * clipped.
     */
    float fClip;
    /**
     * The mode the camera is in. Must be a value from CameraModes.
     */
    int mode;
    /**
     * The speed of the camera when it moves.
     */
    double speed;
    /**
     * The speed of the view rotation from the mouse.
     */
    double mouseSpeed;
    /**
     * The pitch of the camera. Used to calculate where the camera is looking in input mode.
     */
    double verticalAngle;
    /**
     * The yaw of the camera. Used to calculate where the camera is looking in input mode.
     */
    double horizontalAngle;
    /**
     * The current "up" of the camera. Used to calculate where the camera is looking in input mode.
     */
    glm::vec3 up;
    /**
     * The current "right" of the camera. Used to calculate where the camera is looking in input mode.
     */
    glm::vec3 right;
    /**
     * The current "forward" of the camera. Used to calculate where the camera is looking in input mode.
     */
    glm::vec3 forward;
    /**
     * The fov of the camera, used to calculate the view matrix.
     */
    float fov;
public:

    explicit Camera(double *dt);

    /**
     * Updates the rotation of the camera using the mouse.
     * Only relevant for INPUT_MODE.
     * @param deltaCursorPosition used to calculate how to rotate the camera.
     */
    void updateRotation(glm::dvec2 deltaCursorPosition);

    /**
     * Returns the camera's matrix for rendering objects.
     * @param dimensions the width and height of the screen
     * @return the camera matrix
     */
    glm::mat4 cameraMatrix(glm::ivec2 &dimensions);

    void setMode(CameraModes mode);

    void moveForward();

    void moveBackward();

    void moveRight();

    void moveLeft();

    void moveUp();

    void moveDown();

};


#endif //PARTICLESIMULATOR_CAMERA_H
