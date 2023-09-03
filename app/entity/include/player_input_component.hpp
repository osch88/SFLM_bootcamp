#pragma once

#include <iostream>

#include "entity.hpp"
#include "input_component.hpp"

class PlayerInputComponent : public InputComponent {
public:
    virtual void Update(const float& dt, Entity& entity);
};
