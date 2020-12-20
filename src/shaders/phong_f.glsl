#version 330

struct Light {
     vec3 position;

     vec3 ambient;
     vec3 color;

     float constant;
     float linear;
     float quadratic;
};

in vec3 FragPos;
in vec3 FragNormal;

out vec4 FragColor;

uniform vec3 objectColor;
uniform Light light;

void main(){
     vec3 norm = normalize(FragNormal);
     vec3 lightDir = normalize(light.position - FragPos);
     float diff = max(dot(norm, lightDir), 0.0);
     vec3 diffuse = diff * light.color;
     vec3 result = (light.ambient + diffuse) * objectColor;
     FragColor = vec4(result, 1.0);
}