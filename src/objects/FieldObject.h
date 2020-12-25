//
// Created by Joseph Paavola on 12/24/20.
//

#ifndef PARTICLESIMULATOR_FIELDOBJECT_H
#define PARTICLESIMULATOR_FIELDOBJECT_H


#include "Object.h"
#define SMALL_H 1e-7

class FieldObject : public Object {
public:
    FieldObject(int stepCount, float stepSize, int iterationCount);
    FieldObject(int stepCount, float stepSize, int iterationCount, bool drawArrowHeads);
    void draw(Viewport *viewport) override;
protected:
    void compute();
    int stepCount;
    float stepSize;
    int iterationCount;
    bool drawArrowHeads;

    glm::vec3 derivative(glm::vec3 x, glm::vec3 (*f)(glm::vec3), float h);
};


#endif //PARTICLESIMULATOR_FIELDOBJECT_H
