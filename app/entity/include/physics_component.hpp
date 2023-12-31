#pragma once

#include "entity.hpp"

class Entity;

class PhysicsComponent {
public:
    virtual ~PhysicsComponent() {}
    virtual void Update(Entity& entity, const float& dt) = 0;
};
