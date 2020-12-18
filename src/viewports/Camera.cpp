//
// Created by Joseph Paavola on 12/13/20.
//

#include "Camera.h"

Camera::Camera() {
    position = glm::vec3(0.0f, 0.0f, 10.0f);
    // horizontal angle : toward -Z
    horizontalAngle = M_PI;
    // vertical angle : 0, look at the horizon
    verticalAngle = 0;
    //mouse speed
    mouseSpeed = 0.008f;
    //playback speed
    speed = 0.08f;
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    right = glm::vec3(1.0f, 0.0f, 0.0f);
    forward = glm::vec3(0.0f, 0.0f,-1.0f);
    fov = 60.0f;
    nClip = 0.1f;
    fClip = 100.0f;
    mode = INPUT_MODE;
}

void Camera::updateRotation(glm::dvec2 deltaCursorPosition) {
    if (mode == TURNTABLE_MODE || mode == STATIC_MODE) {
        return;
    }

    horizontalAngle += mouseSpeed * deltaCursorPosition.x;
    verticalAngle += mouseSpeed * deltaCursorPosition.y;
    if (verticalAngle > M_PI_2) {
        verticalAngle = M_PI_2;
    }
    if (verticalAngle < -M_PI_2) {
        verticalAngle = -M_PI_2;
    }
    glm::vec3 direction(
            cos(verticalAngle) * sin(horizontalAngle),
            sin(verticalAngle),
            cos(verticalAngle) * cos(horizontalAngle)
    );
    glm::vec3 newRight = glm::vec3(
            sin(horizontalAngle - M_PI_2),
            0,
            cos(horizontalAngle - M_PI_2)
    );
    glm::vec3 newUp = glm::cross(newRight, direction);

    forward = glm::normalize(direction);
    up = glm::normalize(newUp);
    right = glm::normalize(newRight);
}

glm::mat4 Camera::cameraMatrix(glm::ivec2 &dimensions) {
    if (mode == TURNTABLE_MODE) {    //Over-rides camera position and returns and turntable animation
        GLfloat radius = 4.0f;
        GLfloat camX = sin(glfwGetTime()) * radius;
        GLfloat camZ = cos(glfwGetTime()) * radius;
        return glm::lookAt(glm::vec3(camX, 1.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0)) *
               glm::perspective(glm::radians(fov), (float) dimensions.x / (float) dimensions.y, nClip, fClip);
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
    position.y += speed;
}

void Camera::moveDown() {
    position.y -= speed;
}

void Camera::moveForward() {
    position += float(speed) * forward;
}

void Camera::moveBackward() {
    position -= float(speed) * forward;
}

void Camera::moveRight() {
    position += float(speed) * right;
}

void Camera::moveLeft() {
    position -= float(speed) * right;
}

void Camera::setMode(CameraModes newMode) {
    mode = newMode;
}
