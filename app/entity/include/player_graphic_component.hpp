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

#include "animation.hpp"
#include "entity.hpp"
#include "graphic_component.hpp"

class PlayerGraphicsComponent : public GraphicsComponent {
public:
    PlayerGraphicsComponent()
    {
        this->InitTextures();
        this->InitAnimation();
    }
    virtual void Update(Entity& entity, const float& dt,
                        std::shared_ptr<sf::RenderTarget> target);
    virtual bool LoadTexture(std::string filename, std::string fileID);

private:
    sf::Texture texture_;
    std::shared_ptr<sf::Sprite> sprite_;
    std::map<std::string, sf::Texture> textureMap_;
    std::map<EntityState, std::shared_ptr<Animation>> animation_map_;
    std::shared_ptr<Animation> current_animation_;
    EntityState previous_state_;

    void InitAnimation();
    void InitTextures();
    void SetCurrentAnimation(Entity& entity);
};
