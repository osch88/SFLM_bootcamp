#pragma once


#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "entity.hpp"

class Circle : public Entity {
private:
    sf::CircleShape shape_;
    sf::Vector2f position_;
    float velocity_;

    void Init();

public:
    Circle() : Entity() { Init(); }

    void Move(const float& dt, const float x, const float y);
    void Update(const float& dt);
    void Render(std::shared_ptr<sf::RenderTarget> target = nullptr);
};