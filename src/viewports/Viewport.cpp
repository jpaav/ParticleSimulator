//
// Created by Joseph Paavola on 12/13/20.
//

#include "Viewport.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

Viewport::Viewport(const char *name, int width, int height) {
    // Create and bind window
    this->dimensions = glm::ivec2(width, height);
    this->window = glfwCreateWindow(width, height, name, nullptr, nullptr);
    if (!this->window) {
        glfwTerminate();
        std::cerr << "Failed to initialize window." << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // Initial Cursor Position
    glfwGetCursorPos(this->window, &cursorPosition[0], &cursorPosition[1]);
    // Setup cameras
    this->cameras = std::vector<Camera *>();
    auto camera = new Camera();
    this->cameras.push_back(camera);
    this->activeCamera = camera;
    // Init GLEW (should do nothing if it has already been initialized)
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    // Setup vertex buffer object
    glGenVertexArrays(1, &vertexArrayObject);
}

Viewport::~Viewport() {
    glDeleteVertexArrays(1, &vertexArrayObject);
    glfwDestroyWindow(this->window);
}

bool Viewport::shouldClose() {
    return glfwWindowShouldClose(this->window);
}

void Viewport::render() {
    glfwMakeContextCurrent(this->window);
    glfwGetCursorPos(this->window, &cursorPosition[0], &cursorPosition[1]);
    // Move forward
    if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS) {
        this->activeCamera->moveForward();
        //position += direction * dt * speed;
    }
    // Move backward
    if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS) {
        this->activeCamera->moveBackward();
        //position -= direction * dt * speed;
    }
    // Strafe right
    if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS) {
        this->activeCamera->moveRight();
        //position += newRight * dt * speed;
    }
    // Strafe left
    if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS) {
        this->activeCamera->moveLeft();
        //position -= newRight * dt * speed;
    }
    // Rotate right
    if (glfwGetKey(this->window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        this->activeCamera->rotateRight(1);
        //position += newRight * dt * speed;
    }
    // Rotate left
    if (glfwGetKey(this->window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        this->activeCamera->rotateLeft(1);
        //position -= newRight * dt * speed;
    }
    // Setup OpenGL flags
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LESS);
    // Use shader
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    this->shader->use();
    // Run camera routines
    auto cameraMatrix = this->activeCamera->cameraMatrix(dimensions);
    this->activeCamera->updatePos(cursorPosition, dimensions);
    std::cout << this->activeCamera->getPos()[0] << ", " << this->activeCamera->getPos()[1] << ", " << this->activeCamera->getPos()[2] << std::endl;
    glBindVertexArray(vertexArrayObject);
    // Draw each object
    for (Object *const &object : this->objects) {
        object->draw(cameraMatrix, this->shader);
    }
    glfwSwapBuffers(this->window);
}

void Viewport::addObject(Object *object) {
    this->objects.push_back(object);
}

void Viewport::setShader(Shader *shader) {
    this->shader = shader;
}

glm::dvec2 Viewport::getCursorPosition() {
    return this->cursorPosition;
}

Camera *Viewport::getActiveCamera() {
    return this->activeCamera;
}
