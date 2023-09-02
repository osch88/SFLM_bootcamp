#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

class Entity {
public:
    // TODO: Should texture and sprite be part of the Abstract class or the
    // Impementation class?
    sf::Vector2f position_;
    float velocity_;
    sf::Vector2f scale_;

public:
    Entity() {}
    virtual ~Entity() {}

    void SetPosition(sf::Vector2f& position) { position_ = position; }
    sf::Vector2f GetPosition() { return position_; }

    virtual void Move(const float& dt, const float x, const float y) {}
    virtual void Update(const float& dt) {}
    virtual void Render(std::shared_ptr<sf::RenderTarget> target = nullptr) {}
};
