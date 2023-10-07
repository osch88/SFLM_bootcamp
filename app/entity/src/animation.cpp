#include "animation.hpp"

#include <iostream>
#include <memory>

void Animation::Init()
{
    totalFrames_ = texture_.getSize().x / frameRect_.width;
    sprite_ = std::make_shared<sf::Sprite>();
    sprite_->setTexture(texture_);
    if (sprite_ == nullptr) {
        std::cout << "Init: sprite_ == nullptr" << std::endl;
    }
}

bool Animation::Play(const float& dt)
{
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

    // std::cout << "frameRect_.left: " << frameRect_.left
    //           << ", frameRect_.top: " << frameRect_.top
    //           << ", frameRect_.width: " << frameRect_.width
    //           << ", frameRect_.height: " << frameRect_.height
    //           << " frame_: " << frame_ << " frameRate_: " << frameRate_
    //           << " dt: " << dt << " totalTime_ " << totalTime_ << std::endl;

    return false;
}
