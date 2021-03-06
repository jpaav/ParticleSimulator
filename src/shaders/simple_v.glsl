#version 330 core
layout(location=0) in vec3 aPos;

out vec4 vertexColor;

uniform mat4 model;
uniform mat4 camera;

//uniform vec4 color;

void main(){
    gl_Position = model * camera * vec4(aPos,1.0);
    vertexColor = vec4(1.0, 1.0, 1.0, 1.0);
}