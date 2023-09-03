#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

#include "graphic_component.hpp"
#include "input_component.hpp"
#include "physics_component.hpp"

class InputComponent;
class GraphicsComponent;
class PhysicsComponent;

class Entity {
public:
    sf::Vector2f position_;
    sf::Vector2f scale_;
    float velocity_;

public:
    Entity(InputComponent* input, GraphicsComponent* graphic,
           PhysicsComponent* physics)
        : input_(input), graphic_(graphic), physics_(physics)
    {
        graphic_->LoadTexture("../assert/redHood/idle.png");
        position_ = {500.0f, 500.0f};
        velocity_ = 300.0f;
        scale_ = {3.0f, 3.0f};
    }
    ~Entity();

    void Move(const float& dt, const float x, const float y);
    void Update(const float& dt);
    void Render(std::shared_ptr<sf::RenderTarget> target);

private:
    InputComponent* input_;
    GraphicsComponent* graphic_;
    PhysicsComponent* physics_;
};
