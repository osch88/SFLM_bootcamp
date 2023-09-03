#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>
#include <string>

#include "entity.hpp"

class Entity;

class GraphicsComponent {
public:
    virtual ~GraphicsComponent() {}
    virtual void Update(Entity& entity,
                        std::shared_ptr<sf::RenderTarget> target) = 0;
    virtual bool LoadTexture(std::string filename) { return false; }
};
