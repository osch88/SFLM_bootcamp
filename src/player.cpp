#include "player.hpp"

#include <SFML/Graphics/Texture.hpp>
#include <iostream>

void Player::init()
{
    if (!texture_.loadFromFile("../assert/player/player.png")) {
        std::cout << "Failed to load player.png" << std::endl;
    }
    this->setTexture(&texture_);

    this->sprite_.setOrigin(28.0f, 28.0f);

    this->velocity_ = 300.0f;
    this->position_ = {100.0f, 100.0f};
}

void Player::move(const float& dt, const float x, const float y)
{
    this->position_ = {this->position_.x + x * this->velocity_ * dt,
                       this->position_.y + y * this->velocity_ * dt};
    sprite_.setPosition(this->position_);
}

void Player::update(const float& dt)
{
    float x = 0.0f;
    float y = 0.0f;

    static float face_x = 3.0f;
    static float face_y = 3.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        x = -1.0f;
        face_x = 3.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        x = 1.0f;
        face_x = -3.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        y = -1.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        y = 1.0f;
    }

    sprite_.setScale(face_x, face_y);

    this->move(dt, x, y);
    std::cout << "X: " << getPosition().x << "\tY: " << getPosition().y
              << std::endl;
}

void Player::render(std::shared_ptr<sf::RenderTarget> target)
{
    target->draw(sprite_);
}
