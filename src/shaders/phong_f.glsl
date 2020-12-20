#version 330

in vec3 FragPos;
in vec3 FragNormal;

out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 ambientColor;

void main(){
     vec3 norm = normalize(FragNormal);
     vec3 lightDir = normalize(lightPos - FragPos);
     float diff = max(dot(norm, lightDir), 0.0);
     vec3 diffuse = diff * lightColor;
     vec3 result = (ambientColor + diffuse) * objectColor;
     FragColor = vec4(result, 1.0);
}