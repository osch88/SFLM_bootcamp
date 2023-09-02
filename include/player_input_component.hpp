#pragma once

#include <iostream>

#include "entity.hpp"
#include "input_component.hpp"

class PlayerInputComponent : public InputComponent {
public:
    virtual void Update(const float& dt, Entity& entity)
    {
        float x = 0.0f;
        float y = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            x = -1.0f;
            entity.scale_.x = -3.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            x = 1.0f;
            entity.scale_.x = 3.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            y = -1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            y = 1.0f;
        }

        entity.Move(dt, x, y);
        // std::cout << "X: " << entity.GetPosition().x
        //           << "\tY: " << entity.GetPosition().y << std::endl;
    }
};
