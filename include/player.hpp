#pragma once

#include <SFML/Graphics/Texture.hpp>

#include "entity.hpp"

class Player : public Entity {
public:
    Player() : Entity() { init(); }
    // virtual ~Player();

    void init();
    virtual void move(const float& dt, const float x, const float y);
    virtual void update(const float& dt);
    virtual void render(std::shared_ptr<sf::RenderTarget> target = nullptr);

private:
    sf::Texture texture_;
};
