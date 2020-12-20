#version 330

struct Light {
     vec3 position;

     vec3 ambient;
     vec3 color;

     float constant;
     float linear;
     float quadratic;
};

struct Material {
     vec3 ambient;
     vec3 diffuse;
     vec3 specular;
     float shininess;
};

in vec3 FragPos;
in vec3 FragNormal;

out vec4 FragColor;

uniform Material material;
uniform Light light;
uniform vec3 viewPos;

void main(){
     // ambient
     vec3 ambient = light.ambient * material.ambient;

     // diffuse
     vec3 norm = normalize(FragNormal);
     vec3 lightDir = normalize(light.position - FragPos);
     float diff = max(dot(norm, lightDir), 0.0);
     vec3 diffuse = diff * material.diffuse;

     // specular
     vec3 viewDir = normalize(viewPos - FragPos);
     vec3 reflectDir = reflect(-lightDir, norm);
     float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
     vec3 specular = spec * material.specular;

     vec3 result = ambient + diffuse + specular;
     FragColor = vec4(result, 1.0);
}