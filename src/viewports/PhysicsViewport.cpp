//
// Created by Joseph Paavola on 12/20/20.
//

#include "PhysicsViewport.h"

void PhysicsViewport::render() {
    renderSetup();
    renderFields();
    renderObjects();
    renderTeardown();
}

PhysicsViewport::PhysicsViewport(const char *name, int width, int height) : Viewport(name, width, height) {
    fields = std::map<std::string, FieldObject*>();
}

void PhysicsViewport::renderFields() {
    // Draw each field
    for (auto &fieldEntry : fields) {
        fieldEntry.second->draw(this);
    }
}

void PhysicsViewport::addField(const std::string &name, FieldObject *field) {
    fields[name] = field;
}

PhysicsViewport::~PhysicsViewport() {
    for (auto &it:fields) delete it.second;
    fields.clear();
}
