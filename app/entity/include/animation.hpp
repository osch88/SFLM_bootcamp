#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class Animation {
public:
    Animation(sf::Texture& textureSheet, float speed, sf::Vector2u bounds,
              sf::IntRect startRect, sf::IntRect endRect)
        : textureSheet_(textureSheet),
          speed_(speed),
          bounds_(bounds),
          startRect_(startRect),
          endRect_(endRect)
    {
    }

    sf::Texture& textureSheet_;
    float speed_;
    sf::Vector2u bounds_;
    sf::IntRect startRect_, endRect_;

    void Update();
    void Pause();
    void Reset();
};
