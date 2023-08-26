#include "circle.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

void Circle::Init()
{
    velocity_ = 100.0f;
    position_ = {100.0f, 100.0f};

    shape_.setRadius(100.0f);
    shape_.setFillColor(sf::Color::Green);
    shape_.setPosition(position_);
    shape_.setOutlineThickness(10);
    shape_.setOutlineColor(sf::Color::Blue);
}

void Circle::Move(const float& dt, const float x, const float y)
{
    position_ = {position_.x + x * velocity_ * dt,
                 position_.y + y * velocity_ * dt};
    shape_.setPosition(position_);
}

void Circle::Update(const float& dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->Move(dt, -1.0f, 0.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->Move(dt, 1.0f, 0.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->Move(dt, 0.0f, -1.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->Move(dt, 0.0f, 1.0f);
    }
}

void Circle::Render(std::shared_ptr<sf::RenderTarget> target)
{
    target->draw(this->shape_);
}
