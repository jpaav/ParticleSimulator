//
// Created by Joseph Paavola on 12/24/20.
//

#ifndef PARTICLESIMULATOR_FIELDOBJECT_H
#define PARTICLESIMULATOR_FIELDOBJECT_H


#include "Object.h"
#define SMALL_H 1e-5

class FieldObject : public Object {
public:
    FieldObject(int stepCount, double stepSize, int iterationCount);
    FieldObject(int stepCount, double stepSize, int iterationCount, bool drawArrowHeads, bool drawColored);
    void draw(Viewport *viewport) override;
protected:
    void compute();
    void drawColored(Viewport *viewport);
    void drawMonochrome(Viewport *viewport);
    int stepCount;
    double stepSize;
    int iterationCount;
    bool shouldDrawArrows;
    bool shouldDrawColored;

    glm::dvec3 derivative(glm::dvec3 x, glm::dvec3 (*f)(glm::dvec3), double h);
};


#endif //PARTICLESIMULATOR_FIELDOBJECT_H
