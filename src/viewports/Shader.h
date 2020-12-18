//
// Created by Joseph Paavola on 12/14/20.
//

#ifndef PARTICLESIMULATOR_SHADER_H
#define PARTICLESIMULATOR_SHADER_H


#ifndef SHADER_H
#define SHADER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader {
private:
    /**
     * The OpenGL shader id.
     */
    unsigned int id;
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
    void use() const;
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setMatrix(const std::string &name, glm::mat4) const;
};

#endif


#endif //PARTICLESIMULATOR_SHADER_H

