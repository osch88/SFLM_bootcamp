#include "circle.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

void Circle::Init()
{
    shape_.setRadius(100.0f);
    shape_.setFillColor(sf::Color::Green);
    shape_.setPosition(sf::Vector2f(100, 100));
    shape_.setOutlineThickness(10);
    shape_.setOutlineColor(sf::Color::Blue);
}

void Circle::Move(const float& dt, const float x, const float y)
{
    
}
void Circle::Update(const float& dt) {}
void Circle::Render(std::shared_ptr<sf::RenderTarget> target)
{
    target->draw(this->shape_);
}
