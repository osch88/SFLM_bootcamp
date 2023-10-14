#include "animation.hpp"

#include <iostream>
#include <memory>

void Animation::Init()
{
    totalFrames_ = texture_.getSize().x / frameRect_.width;
    sprite_ = std::make_shared<sf::Sprite>();
    sprite_->setTexture(texture_);
    sprite_->setTextureRect(frameRect_);
    // HACK: Hack, needs to be improved
    sprite_->setOrigin(40.0f, 40.0f);
}

bool Animation::Play(const float& dt, const sf::Vector2f& scale, const sf::Vector2f& position)
{
    sprite_->setScale(scale);
    sprite_->setPosition(position);
    totalTime_ += dt;
    if (totalTime_ >= frameRate_) {
        frameRect_.left = frame_ * frameRect_.width;
        frame_++;
        totalTime_ = 0;
        if (frame_ >= totalFrames_) {
            frame_ = 0;
        }
        sprite_->setTextureRect(frameRect_);
        return true;
    }
    return false;
}

void Animation::Reset() { frame_ = 0; }
