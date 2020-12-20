cmake_minimum_required(VERSION 3.17)
project(ParticleSimulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")

include_directories(include)
link_directories(/usr/local/lib)

add_executable(ParticleSimulator src/main.cpp src/viewports/Viewport.cpp src/viewports/Viewport.h src/callbacks.cpp src/callbacks.h src/objects/Object.cpp src/objects/Object.h src/cameras/Camera.cpp src/cameras/Camera.h src/objects/EmptyObject.cpp src/objects/EmptyObject.h src/materials/Shader.cpp src/materials/Shader.h src/objects/MeshObject.cpp src/objects/MeshObject.h src/lights/Light.cpp src/lights/Light.h src/viewports/Viewport.fwd.h src/objects/Object.fwd.h src/materials/Material.cpp src/materials/Material.h src/materials/PhongMaterial.cpp src/materials/PhongMaterial.h)

target_link_libraries(ParticleSimulator GLEW glfw3 -m64)