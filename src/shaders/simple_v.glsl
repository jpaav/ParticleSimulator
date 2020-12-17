#version 330 core
layout(location=0) in vec3 vertexPosition_modelspace;

out vec4 vertexColor;

uniform mat4 MVP;

//uniform vec4 color;

void main(){
    gl_Position = MVP * vec4(vertexPosition_modelspace,1.0);
    vertexColor = vec4(1.0, 1.0, 1.0, 1.0);
}