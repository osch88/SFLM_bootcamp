#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <memory>
#include "entity.hpp"

class Animation {
public:
    Animation(sf::Texture& texture, float frameRate, sf::IntRect frameRect)
        : texture_(texture),
          frameRate_(frameRate),
          frameRect_(frameRect),
          frame_(0),
          totalTime_(0.0f)
    {
        this->Init();
    }
    std::shared_ptr<sf::Sprite> GetSprite()
    {
        if (sprite_ == nullptr) {
            std::cout << "sprite_ is null" << std::endl;
        }
        return sprite_;
    }
    bool Play(const float& dt, const sf::Vector2f& scale, const sf::Vector2f& position);
    void Update();
    void Pause();
    void Reset();

private:
    sf::Texture texture_;
    float frameRate_;
    sf::IntRect frameRect_;
    int totalFrames_;
    int frame_;
    float totalTime_;
    std::shared_ptr<sf::Sprite> sprite_;

private:
    void Init();
};
