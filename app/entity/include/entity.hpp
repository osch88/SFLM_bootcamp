#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <memory>
#include <string>

#include "graphic_component.hpp"
#include "input_component.hpp"
#include "physics_component.hpp"

class InputComponent;
class GraphicsComponent;
class PhysicsComponent;

// TODO: This logic should be placed somewhere else
enum class EntityState {
    IDLE,
    RUN,
    JUMP,
};

class Entity {
public:
    sf::Vector2f position_;
    sf::Vector2f scale_;
    sf::Vector2f velocity_;
    float speed_;
    EntityState currentState_;

public:
    Entity(InputComponent* input, GraphicsComponent* graphic,
           PhysicsComponent* physics)
        : input_(input), graphic_(graphic), physics_(physics)
    {
        position_ = {500.0f, 500.0f};
        speed_ = 300.0f;
        scale_ = {3.0f, 3.0f};
        currentState_ = EntityState::IDLE;
    }
    ~Entity();

    void Move(const float& dt, const float x, const float y);
    void Update(const float& dt);
    void Render(const float& dt, std::shared_ptr<sf::RenderTarget> target);

private:
    InputComponent* input_;
    GraphicsComponent* graphic_;
    PhysicsComponent* physics_;
};
