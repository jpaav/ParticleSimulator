//
// Created by Joseph Paavola on 12/13/20.
//

#include "Viewport.h"
#include "Light.h"


Viewport::Viewport(const char *name, int width, int height) {
    // Create and bind window
    window = glfwCreateWindow(width, height, name, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to initialize window." << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    //Binds the Viewport to the window for use during key callbacks
    glfwSetWindowUserPointer(window, this);
    // Set callbacks
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);

    // Cursor/window dimensions
    glfwGetCursorPos(window, &cursorPosition.x, &cursorPosition.y);
    lastCursorPosition = cursorPosition;
    dimensions = glm::ivec2(width, height);

    // Initial deltaTime
    deltaTime = new double(-1.0);
    // Setup cameras
    cameras = std::vector<Camera *>();
    auto camera = new Camera(window);
    cameras.push_back(camera);
    activeCamera = camera;
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
    // Setup lighting
    ambientColor = glm::vec3(0.2f, 0.3f, 0.3f);
    light = new Light();
    this->shader = nullptr;
}

Viewport::~Viewport() {
    delete deltaTime;
    delete shader;
    for(auto &it:objects) delete it; objects.clear();
    for(auto &it:cameras) delete it; cameras.clear();
    glDeleteVertexArrays(1, &vertexArrayObject);
    glfwDestroyWindow(this->window);
}

bool Viewport::shouldClose() {
    return glfwWindowShouldClose(this->window);
}

void Viewport::render() {
    double currentTime = glfwGetTime();
    *deltaTime = currentTime - lastFrame;
    lastFrame = currentTime;
    std::cout << "FPS: " << 1 / *deltaTime << "(" << *deltaTime * 1000 << "ms)" << std::endl;
    glfwMakeContextCurrent(this->window);
    lastCursorPosition = cursorPosition;
    glfwGetCursorPos(this->window, &cursorPosition[0], &cursorPosition[1]);
    activeCamera->processInput();
    activeCamera->updateRotation(lastCursorPosition - cursorPosition);
    // Setup OpenGL flags
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearColor(ambientColor.r, ambientColor.b, ambientColor.g, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->shader->use();
    // Run camera routines
    auto cameraMatrix = this->activeCamera->cameraMatrix(dimensions);
    glBindVertexArray(vertexArrayObject);
    // Draw each object
    for (Object *const &object : this->objects) {
        object->draw(this);
    }
    glfwSwapBuffers(this->window);
}

void Viewport::addObject(Object *object) {
    this->objects.push_back(object);
}

void Viewport::setShader(Shader *shader) {
    this->shader = shader;
}

Camera *Viewport::getActiveCamera() {
    return this->activeCamera;
}

glm::mat4 Viewport::getCameraMatrix() {
    return activeCamera->cameraMatrix(dimensions);
}

Shader * Viewport::getShader() {
    return shader;
}

Light *Viewport::getLight() {
    return light;
}
