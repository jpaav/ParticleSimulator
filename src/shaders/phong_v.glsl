#version 330
layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aNormal;

out vec3 FragPos;
out vec4 FragColor;
out vec3 FragNormal;

uniform mat4 model;
uniform mat4 camera;


void main(){
    gl_Position = model * camera * vec4(aPos, 1.0);

    FragPos = vec3(model * vec4(aPos, 1.0));
    FragNormal = aNormal;
}