//
// Created by Joseph Paavola on 12/23/20.
//

#include "WireObject.h"

void WireObject::draw(Viewport *viewport) {
    auto shader = viewport->getShader("simple");
    shader->use();
    shader->setMatrix("model", getModelMatrix());
    shader->setMatrix("camera", viewport->getCameraMatrix());

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0,          // Attribute 0. must match shader layout
            3,          // size
            GL_FLOAT,   // type
            GL_FALSE,   // normalized?
            0,          // stride
            (void *) 0  // array buffer offset
    );
    glDrawArrays(GL_LINE_LOOP, 0, controlPoints.size());
    glDrawArrays(GL_TRIANGLES, controlPoints.size(), 3);

    glDisableVertexAttribArray(0);
}

WireObject::WireObject() {
    vertices = std::vector<glm::vec3>();
    controlPoints.emplace_back(1.0, 0.0, 1.0);
    controlPoints.emplace_back(-1.0, 0.0, 1.0);
    controlPoints.emplace_back(-1.0, 0.0, -1.0);
    controlPoints.emplace_back(1.0, 0.0, -1.0);

    vertices = std::vector<glm::vec3>(controlPoints);
    // Draw arrow showing voltage direction
    auto arrowHeadPoint1 = controlPoints[0] * 0.5f + controlPoints[1] * 0.5f;
    auto arrowHeadPoint2 = controlPoints[0] * 0.6f + controlPoints[1] * 0.4f;
    auto arrowHeadPoint3 = controlPoints[0] * 0.6f + controlPoints[1] * 0.4f;
    arrowHeadPoint2.y += 0.1f;
    arrowHeadPoint3.y -= 0.1f;
    vertices.push_back(arrowHeadPoint1);
    vertices.push_back(arrowHeadPoint2);
    vertices.push_back(arrowHeadPoint3);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);
}
