#include <SFML/Graphics/Rect.hpp>
#include <iostream>

#include "player_graphic_component.hpp"

void PlayerGraphicsComponent::Update(Entity& entity, const float& dt,
                                     std::shared_ptr<sf::RenderTarget> target)
{
    // 18 frames for idle sprite
    totalTime_ += dt;
    if (totalTime_ >= frameRate_) {
        frameRect_.left = frame_ * 80;
        frame_++;
        totalTime_ = 0;
    }

    if (frame_ > 16) {
        frame_ = 0;
    }
    sprite_.setTextureRect(frameRect_);
    sprite_.setScale(entity.scale_.x, entity.scale_.y);
    sprite_.setPosition(entity.position_);
    target->draw(sprite_);
}

bool PlayerGraphicsComponent::LoadTexture(std::string filename,
                                          std::string fileID)
{
    if (!texture_.loadFromFile(filename)) {
        std::cout << "Failed to load player.png" << std::endl;
        return false;
    }
    this->SetTexture();
    sf::Vector2u textureSize = texture_.getSize();

    this->sprite_.setOrigin(30.0f, 0.0f);
    this->sprite_.setTextureRect(sf::IntRect(0, 0, 80, 80));
    return true;
}

void PlayerGraphicsComponent::SetTexture() { sprite_.setTexture(texture_); }
