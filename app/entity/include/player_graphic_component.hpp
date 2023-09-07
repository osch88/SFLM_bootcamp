#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "entity.hpp"
#include "graphic_component.hpp"

class PlayerGraphicsComponent : public GraphicsComponent {
public:
    PlayerGraphicsComponent() : frameRate_(0.08), totalTime_(0), frame_(0)
    {
        if (!this->LoadTexture("../assert/redHood/idle.png", "idle")) {
            std::cout << "ERROR, loading img" << std::endl;
        }
        frameRect_.top = 0;
        frameRect_.left = 0;
        frameRect_.width = 80;
        frameRect_.height = 80;
    }
    virtual void Update(Entity& entity, const float& dt,
                        std::shared_ptr<sf::RenderTarget> target);
    virtual bool LoadTexture(std::string filename, std::string fileID);

private:
    sf::Texture texture_;
    sf::Sprite sprite_;
    float frameRate_;
    float totalTime_;
    sf::IntRect frameRect_;
    int frame_;
    // std::map<std::string, sf::Sprite> sprites_;

    void SetTexture();
};
