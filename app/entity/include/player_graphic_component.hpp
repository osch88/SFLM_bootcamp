#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "entity.hpp"
#include "graphic_component.hpp"

class PlayerGraphicsComponent : public GraphicsComponent {
public:
    PlayerGraphicsComponent()
        : frameRate_(0.08),
          totalTime_(0),
          frame_(0),
          totalFrames_(0),
          frameWidth_(80)
    {
        if (!this->LoadTexture("../assert/redHood/run_high.png", "run")) {
            std::cout << "ERROR, loading img" << std::endl;
        }
        if (!this->LoadTexture("../assert/redHood/idle.png", "idle")) {
            std::cout << "ERROR, loading img" << std::endl;
        }
        if (!this->LoadTexture("../assert/redHood/jump.png", "jump")) {
            std::cout << "ERROR, loading img" << std::endl;
        }
        this->SetTexture();
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
    sf::IntRect frameRect_;
    float frameRate_;
    float totalTime_;
    int frame_;
    int totalFrames_;
    int frameWidth_;
    std::map<std::string, sf::Texture> textureMap_;

    void SetTexture();
    void SetTextureToState(Entity& entity);
};
