//
// Created by Joseph Paavola on 12/13/20.
//

#include "Camera.h"

Camera::Camera(double *dt) {
    deltaTime = dt;
    position = glm::vec3(1.0f, 1.0f, 1.0f);
    focusPoint = glm::vec3(0.0f, 0.0f, 0.0f);
    // horizontal angle : toward -Z
    horizontalAngle = 0.0;
    // vertical angle : 0, look at the horizon
    verticalAngle = 0.0;
    //mouse speed
    mouseSpeed = 0.5f;
    //playback speed
    speed = 3.0f;
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    right = glm::vec3(1.0f, 0.0f, 0.0f);
    forward = glm::vec3(0.0f, 0.0f, 1.0f);
    fov = 60.0f;
    nClip = 0.1f;
    fClip = 100.0f;
    mode = INPUT_MODE;
}

void Camera::update(glm::dvec2 deltaCursorPosition) {
    if (mode == TURNTABLE_MODE || mode == STATIC_MODE) {
        return;
    }

    horizontalAngle += mouseSpeed * *deltaTime * (deltaCursorPosition.x);
    verticalAngle += mouseSpeed * *deltaTime * (deltaCursorPosition.y);
    glm::vec3 direction(
            cos(verticalAngle) * sin(horizontalAngle),
            sin(verticalAngle),
            cos(verticalAngle) * cos(horizontalAngle)
    );
    glm::vec3 newRight = glm::vec3(
            sin(horizontalAngle - 3.14f / 2.0f),
            0,
            cos(horizontalAngle - 3.14f / 2.0f)
    );
    glm::vec3 newUp = glm::cross(newRight, direction);

    forward = direction;
    up = newUp;
    right = newRight;
}

glm::mat4 Camera::cameraMatrix(glm::ivec2 &dimensions) {
    if (mode == TURNTABLE_MODE) {    //Over-rides camera position and returns and turntable animation
        GLfloat radius = 4.0f;
        GLfloat camX = sin(glfwGetTime()) * radius;
        GLfloat camZ = cos(glfwGetTime()) * radius;
        glm::mat4 view, projection;
        view = glm::lookAt(glm::vec3(camX, 1.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
        projection = glm::perspective(glm::radians(fov), (float) dimensions.x / (float) dimensions.y, nClip, fClip);
        return projection * view;
    } else if (mode == STATIC_MODE) {
        return glm::perspective(glm::radians(fov), (float) dimensions.x / (float) dimensions.y, nClip, fClip) *
               glm::lookAt(position, glm::vec3(0.0f, 0.0f, 0.0f), up);
    } else if (mode == INPUT_MODE) {
        return glm::perspective(glm::radians(fov), (float) dimensions.x / (float) dimensions.y, nClip, fClip) *
               glm::lookAt(position, position + forward, up);
    }
    std::cerr << "Camera has a mode value of " << mode << " which is not a valid option" << std::endl;
    return glm::mat4();
}

void Camera::moveUp() {
    position.y += *deltaTime * speed;
}

void Camera::moveDown() {
    position.y -= *deltaTime * speed;
}

void Camera::moveForward() {
    position += float(*deltaTime * speed) * forward;
}

void Camera::moveBackward() {
    position -= float(*deltaTime * speed) * forward;
}

void Camera::moveRight() {
    position += float(*deltaTime * speed) * right;
}

void Camera::moveLeft() {
    position -= float(*deltaTime * speed) * right;
}

void Camera::setMode(CameraModes newMode) {
    mode = newMode;
}
