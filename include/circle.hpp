#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "entity.hpp"

class Circle : public Entity {
private:
    sf::CircleShape shape_;
    void Init();

public:
    Circle() : Entity() { Init(); }

    void Move(const float& dt, const float x, const float y);
    void Update(const float& dt);
    void Render(std::shared_ptr<sf::RenderTarget> target = nullptr);
};
