//
// Created by Joseph Paavola on 12/14/20.
//

#include "EmptyObject.h"

void EmptyObject::draw() {
    glLineWidth(5.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
//    glVertex3f(0.0f, 0.0f, 0.0f);
//    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex2f(10, 10);
    glVertex2f(20, 20);
    glEnd();
}