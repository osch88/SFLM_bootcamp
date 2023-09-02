#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include <memory>
#include <string>

#include "entity.hpp"

class GraphicsComponent {
public:
    void Update(Entity& entity, std::shared_ptr<sf::RenderTarget> target)
    {
        sprite_.setScale(entity.scale_.x, entity.scale_.y);
        sprite_.setPosition(entity.GetPosition());
        target->draw(sprite_);
    }

    void SetTexture()
    {
        sprite_.setTexture(texture_);
    }

    bool LoadTexture(std::string filename)
    {
        if (!texture_.loadFromFile(filename)) {
            std::cout << "Failed to load player.png" << std::endl;
            return false;
        }
        this->SetTexture();
        sf::Vector2u textureSize = texture_.getSize();

        this->sprite_.setOrigin(40.0f, 40.0f);
        this->sprite_.setTextureRect(sf::IntRect(0, 0, 80, 80));
        return true;
    }

private:
    sf::Texture texture_;
    sf::Sprite sprite_;
};
