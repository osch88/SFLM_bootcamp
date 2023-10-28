#pragma once

#include "entity.hpp"
#include "physics_component.hpp"

class PlayerPhysicsComponent : public PhysicsComponent {
public:
    void Init(Entity& entity);
    virtual void Update(Entity& entity, const float& dt);

private:
    void Jump();
};
