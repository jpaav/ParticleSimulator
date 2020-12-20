//
// Created by Joseph Paavola on 12/20/20.
//

#include "Light.h"

Light::Light() {
    position = glm::vec3(1.0, 1.0, 1.0);
    color = glm::vec3(1.0, 1.0, 1.0);
    intensity = 10.0f;
}
