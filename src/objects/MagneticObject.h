//
// Created by Joseph Paavola on 12/20/20.
//

#ifndef PARTICLESIMULATOR_MAGNETICOBJECT_H
#define PARTICLESIMULATOR_MAGNETICOBJECT_H


#include "MeshObject.h"

class MagneticObject : public MeshObject {
private:
    glm::vec3 pole;
    float magneticMoment;
    glm::vec3 getMagnetization();
    float permeability;
};


#endif //PARTICLESIMULATOR_MAGNETICOBJECT_H
