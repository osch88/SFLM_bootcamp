#include "player_input_component.hpp"

void PlayerInputComponent::Update(const float& dt, Entity& entity)
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
    std::cout << "X: " << entity.position_.x
              << "\tY: " << entity.position_.y << std::endl;
}
