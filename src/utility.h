//
// Created by Joseph Paavola on 12/24/20.
//

#ifndef PARTICLESIMULATOR_UTILITY_H
#define PARTICLESIMULATOR_UTILITY_H

// TODO: use function templates

glm::vec3 interpolate(glm::vec3 first, glm::vec3 second, float ratio) {
    return first * ratio + second * (1.0f - ratio);
}

#endif //PARTICLESIMULATOR_UTILITY_H
