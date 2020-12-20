//
// Created by Joseph Paavola on 12/14/20.
//

#include "EmptyObject.h"

EmptyObject::EmptyObject() : Object() {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(axisVertices), axisVertices, GL_STATIC_DRAW);
}

void EmptyObject::draw(Viewport *viewport) {

    Shader *shader = viewport->getShader("simple");

    // Send MVP to shader in uniform variable
    shader->setMatrix("model", getModelMatrix());
    shader->setMatrix("camera", viewport->getCameraMatrix());

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
    glDrawArrays(GL_LINES, 0, vertexCount); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
}