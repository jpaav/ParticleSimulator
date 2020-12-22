//
// Created by Joseph Paavola on 12/20/20.
//

#ifndef PARTICLESIMULATOR_PHYSICSVIEWPORT_H
#define PARTICLESIMULATOR_PHYSICSVIEWPORT_H


#include "Viewport.h"

class PhysicsViewport : public Viewport {

    void render() override;

    void drawVectorField(int resolution, float stepSize, glm::vec3 (*vectorField)(float, float, float));

public:
    PhysicsViewport(const char *name, int width, int height);
};


#endif //PARTICLESIMULATOR_PHYSICSVIEWPORT_H
