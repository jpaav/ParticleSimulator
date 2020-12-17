//
// Created by Joseph Paavola on 12/14/20.
//

#include "EmptyObject.h"

EmptyObject::EmptyObject() : Object() {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(axisVertices), axisVertices, GL_STATIC_DRAW);
}

void EmptyObject::draw(glm::mat4 &cameraMatrix, Shader *shader) {

    // Send MVP to shader in uniform variable
     shader->setMatrix("MVP", getMVPMatrix(cameraMatrix));

//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Add Vertex Position Attribute
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
            0,          // Attribute 0. must match shader layout
            3,          // size
            GL_FLOAT,   // type
            GL_FALSE,   // normalized?
            0,          // stride
            (void *) 0  // array buffer offset
    );
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
}