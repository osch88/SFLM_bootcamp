#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include "entity.hpp"
#include "graphic_component.hpp"
#include "input_component.hpp"

class Player : public Entity {
public:
    Player(InputComponent* input) : Entity(), input_(input) { init(); }
    virtual ~Player();

    void init();
    virtual void Move(const float& dt, const float x, const float y);
    virtual void Update(const float& dt);
    virtual void Render(std::shared_ptr<sf::RenderTarget> target = nullptr);

private:
    InputComponent* input_;
    GraphicsComponent graphic_;
};
