//
// Created by Joseph Paavola on 12/19/20.
//

#include "MeshObject.h"

void MeshObject::draw(Viewport *viewport) {
    Shader *shader = viewport->getShader();
    // Send MVP to shader in uniform variable
    shader->setMatrix("model", getModelMatrix());
    shader->setMatrix("camera", viewport->getCameraMatrix());
    // TODO: make a material class that handles this stuff
    shader->setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
    shader->setVec3("light.color",  viewport->getLight()->color);
    shader->setVec3("light.position", viewport->getLight()->position);
    shader->setVec3("light.ambient", viewport->ambientColor);

    // Add Vertex Position Attribute
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
            0,          // Attribute 0. must match shader layout
            3,          // size
            GL_FLOAT,   // type
            GL_FALSE,   // normalized?
            0,          // stride
            (void *) 0  // array buffer offset
    );
    // Add Normals Attribute
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glVertexAttribPointer(
            1,          // Attribute 1. must match shader layout
            3,          // size
            GL_FLOAT,   // type
            GL_FALSE,   // normalized?
            0,          // stride
            (void *) 0  // array buffer offset
    );

    glDrawArrays(GL_TRIANGLES, 0, vertices.size() * 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

MeshObject::MeshObject(const char *objPath) : Object() {
    glGenBuffers(1, &uvBuffer);
    glGenBuffers(1, &normalBuffer);

    loadObj(objPath);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec3), uvs.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), normals.data(), GL_STATIC_DRAW);
}

MeshObject::~MeshObject() {
    glDeleteBuffers(1, &uvBuffer);
    glDeleteBuffers(1, &normalBuffer);
}

void MeshObject::loadObj(const char *path) {
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;

    FILE *file = fopen(path, "r");
    if (file == nullptr) {
        std::cerr << "MeshObject::loadObj => Impossible to open file!" << std::endl;
        return;
    }
    while (true) {
        char lineHeader[1024];
        //read first word
        int res = fscanf(file, "%s", lineHeader);    //fnscanf?
        //Stops at end of file
        if (res == EOF) {
            break;
        }
        //Parse vertices
        if (strcmp(lineHeader, "v") == 0) {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            temp_vertices.push_back(vertex);
        }//Parse UVs
        else if (strcmp(lineHeader, "vt") == 0) {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            temp_uvs.push_back(uv);
        }//Parse normals
        else if (strcmp(lineHeader, "vn") == 0) {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            temp_normals.push_back(normal);
        }//Parse faces
        else if (strcmp(lineHeader, "f") == 0) {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                                 &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                 &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
            if (matches != 9) {
                printf("Try other options, this parser is too basic for that kind of file!\n");
                return;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices.push_back(uvIndex[0]);
            uvIndices.push_back(uvIndex[1]);
            uvIndices.push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
        //Process the object data
        for (unsigned int vertexIndex : vertexIndices) {
            glm::vec3 vertex = temp_vertices[vertexIndex - 1];    //OBJ indexing starts at 1
            vertices.push_back(vertex);
        }
        for (unsigned int uvIndex : uvIndices) {
            glm::vec2 uv = temp_uvs[uvIndex - 1];    //OBJ indexing starts at 1
            uvs.push_back(uv);
        }
        for (unsigned int normalIndex : normalIndices) {
            glm::vec3 normal = temp_normals[normalIndex - 1];    //OBJ indexing starts at 1
            normals.push_back(normal);
        }
    }
}