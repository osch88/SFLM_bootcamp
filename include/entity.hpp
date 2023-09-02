#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

class Entity {
protected:
    // TODO: Should texture and sprite be part of the Abstract class or the
    // Impementation class?
    sf::Vector2f position_;
    sf::Sprite sprite_;
    sf::Texture* texture_;
    float velocity_;

public:
    Entity() {}
    virtual ~Entity() = default;

    void setTexture(sf::Texture* texture)
    {
        texture_ = texture;
        sprite_.setTexture(*texture_);
    }
    // std::shared_ptr<sf::Texture> GetTexture() { return texture_; }

    void setPosition(sf::Vector2f& position) { position_ = position; }
    sf::Vector2f getPosition() { return position_; }

    virtual void move(const float& dt, const float x, const float y) {}
    virtual void update(const float& dt) = 0;
    virtual void render(std::shared_ptr<sf::RenderTarget> target = nullptr) = 0;
};
