#pragma once

#include "entity.hpp"

class InputComponent {
public:
    virtual ~InputComponent() {}
    virtual void Update(const float& dt, Entity& entity) = 0;
};
