#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

class Entity {

public:
    Entity() {}
    // virtual ~Entity();

    virtual void Move(const float& dt, const float x, const float y) = 0;
    virtual void Update(const float& dt) = 0;
    virtual void Render(std::shared_ptr<sf::RenderTarget> target = nullptr) = 0;
};
