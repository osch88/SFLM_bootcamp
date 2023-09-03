#pragma once

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
    virtual void Update(Entity& entity, std::shared_ptr<sf::RenderTarget> target);
    virtual bool LoadTexture(std::string filename);

private:
    sf::Texture texture_;
    sf::Sprite sprite_;
    // std::map<std::string, sf::Sprite> sprites_;

    void SetTexture();
};
