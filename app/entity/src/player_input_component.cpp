#include "player_input_component.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "entity.hpp"

void PlayerInputComponent::Update(const float& dt, Entity& entity)
{
    (void) dt;
    entity.velocity_ = {0.0f, 0.0f};
    switch (entity.currentState_) {
        case EntityState::IDLE:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                entity.currentState_ = EntityState::RUN;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                entity.currentState_ = EntityState::RUN;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                entity.currentState_ = EntityState::JUMP;
            }
            break;

        case EntityState::RUN:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                entity.velocity_.x = -1.0f;
                entity.scale_.x = -3.0f;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                entity.velocity_.x = 1.0f;
                entity.scale_.x = 3.0f;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                entity.currentState_ = EntityState::JUMP;
            }
            else {
                entity.currentState_ = EntityState::IDLE;
            }
            break;

        case EntityState::JUMP:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                entity.currentState_ = EntityState::IDLE;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                entity.velocity_.x = -1.0f;
                entity.scale_.x = -3.0f;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                entity.velocity_.x = 1.0f;
                entity.scale_.x = 3.0f;
            }
            break;
        default:
            std::cout << "NO STATE" << std::endl;
    }
}
