#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

#include "entity.hpp"
#include "player_graphic_component.hpp"

void PlayerGraphicsComponent::Update(Entity& entity, const float& dt,
                                     std::shared_ptr<sf::RenderTarget> target)
{
    this->GetState(entity);
    this->SetTexture();
    totalFrames_ = texture_.getSize().x / frameWidth_;
    // 18 frames for idle sprite
    totalTime_ += dt;
    if (totalTime_ >= frameRate_) {
        frameRect_.left = frame_ * frameWidth_;
        frame_++;
        totalTime_ = 0;
    }

    if (frame_ >= totalFrames_) {
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
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        std::cout << "Failed to load: " << filename << std::endl;
        return false;
    }
    textureMap_[fileID] = texture;
    return true;
}

void PlayerGraphicsComponent::GetState(Entity& entity)
{
    switch (entity.currentState_)
    {
    case EntityState::IDLE:
        texture_ = textureMap_["idle"];
        break;
    case EntityState::RUN:
        texture_ = textureMap_["run"];
        break;
    case EntityState::JUMP:
        texture_ = textureMap_["jump"];
        break;
    default:
        std::cout << "Not good, no state found to set texture" << std::endl;
        break;
    }
}

void PlayerGraphicsComponent::SetTexture()
{
    sprite_.setTexture(texture_);
    sf::Vector2u textureSize = texture_.getSize();
    this->sprite_.setOrigin(30.0f, 0.0f);
    this->sprite_.setTextureRect(sf::IntRect(0, 0, frameWidth_, frameWidth_));
}