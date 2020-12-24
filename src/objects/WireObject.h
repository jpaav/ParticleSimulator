//
// Created by Joseph Paavola on 12/23/20.
//

#ifndef PARTICLESIMULATOR_WIREOBJECT_H
#define PARTICLESIMULATOR_WIREOBJECT_H


#include "Object.h"

class WireObject : public Object {
public:
    WireObject();
    void draw(Viewport *viewport) override;
    float current;
protected:
    std::vector<glm::vec3> controlPoints;
};


#endif //PARTICLESIMULATOR_WIREOBJECT_H
