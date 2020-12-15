//
// Created by Joseph Paavola on 12/14/20.
//

#ifndef PARTICLESIMULATOR_SHADER_H
#define PARTICLESIMULATOR_SHADER_H


#ifndef SHADER_H
#define SHADER_H

#include "GLFW/glfw3.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader {
private:
    // the program ID
    unsigned int ID;
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};

#endif


#endif //PARTICLESIMULATOR_SHADER_H

