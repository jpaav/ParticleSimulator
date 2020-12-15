cmake_minimum_required(VERSION 3.17)
project(ParticleSimulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")

include_directories(include)
link_directories(/usr/local/lib)

add_executable(ParticleSimulator src/main.cpp src/viewports/Viewport.cpp src/viewports/Viewport.h src/callbacks.cpp src/callbacks.h src/viewports/Object.cpp src/viewports/Object.h src/viewports/Camera.cpp src/viewports/Camera.h src/viewports/EmptyObject.cpp src/viewports/EmptyObject.h src/viewports/Shader.cpp src/viewports/Shader.h)

target_link_libraries(ParticleSimulator GLEW glfw3 -m64)