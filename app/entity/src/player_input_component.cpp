#include "player_input_component.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "entity.hpp"

void PlayerInputComponent::Update(const float& dt, Entity& entity)
{
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                entity.velocity_.x = 1.0f;
                entity.scale_.x = 3.0f;
            }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            //     entity.velocity_.y = -1.0f;
            // }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            //     entity.velocity_.y = 1.0f;
            // }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                entity.currentState_ = EntityState::JUMP;
            }
            break;

        case EntityState::JUMP:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                entity.velocity_.x = -1.0f;
                entity.scale_.x = -3.0f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                entity.velocity_.x = 1.0f;
                entity.scale_.x = 3.0f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                entity.currentState_ = EntityState::IDLE;
            }
            break;
        default:
            std::cout << "NO STATE" << std::endl;
    }
}
