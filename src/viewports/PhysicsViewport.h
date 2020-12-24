//
// Created by Joseph Paavola on 12/20/20.
//

#ifndef PARTICLESIMULATOR_PHYSICSVIEWPORT_H
#define PARTICLESIMULATOR_PHYSICSVIEWPORT_H

#include <map>

#include "Viewport.h"
#include "../objects/FieldObject.h"

class PhysicsViewport : public Viewport {
private:
    std::map<std::string, FieldObject*> fields;
    void renderFields();
public:
    PhysicsViewport(const char *name, int width, int height);
    ~PhysicsViewport();

    void render() override;
    void addField(const std::string &name, FieldObject *field);
};


#endif //PARTICLESIMULATOR_PHYSICSVIEWPORT_H
