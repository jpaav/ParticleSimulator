//
// Created by Joseph Paavola on 12/24/20.
//

#ifndef PARTICLESIMULATOR_FIELDOBJECT_H
#define PARTICLESIMULATOR_FIELDOBJECT_H


#include "Object.h"

class FieldObject : public Object {
public:
    FieldObject(int stepCount, float stepSize, int iterationCount);
    void draw(Viewport *viewport) override;
protected:
    void compute();
    int stepCount;
    float stepSize;
    int iterationCount;
};


#endif //PARTICLESIMULATOR_FIELDOBJECT_H
