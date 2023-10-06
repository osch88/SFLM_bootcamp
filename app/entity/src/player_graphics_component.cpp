#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <memory>

#include "animation.hpp"
#include "entity.hpp"
#include "player_graphic_component.hpp"

void PlayerGraphicsComponent::Init()
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
    sf::IntRect bounds = {0, 0, 80, 80};

    std::shared_ptr<Animation> idle =
        std::make_shared<Animation>(textureMap_["idle"], 0.08f, bounds);
    animation_map_[EntityState::IDLE] = idle;

    std::shared_ptr<Animation> run =
        std::make_shared<Animation>(textureMap_["run"], 0.08f, bounds);
    animation_map_[EntityState::RUN] = run;

    std::shared_ptr<Animation> jump =
        std::make_shared<Animation>(textureMap_["jump"], 0.08f, bounds);
    animation_map_[EntityState::JUMP] = jump;

    // Check if anything is null
    for (auto& a : animation_map_) {
        if (a.second == nullptr) {
            std::cout << "Animation is null!" << std::endl;
        }
    }
}

void PlayerGraphicsComponent::Update(Entity& entity, const float& dt,
                                     std::shared_ptr<sf::RenderTarget> target)
{
    this->SetCurrentAnimation(entity);
    // CALL ANIMATION
    current_animation_->Play(dt);
    sprite_ = current_animation_->GetSprite();
    sprite_->setScale(entity.scale_.x, entity.scale_.y);
    sprite_->setPosition(entity.position_);
    target->draw(*sprite_);
}

bool PlayerGraphicsComponent::LoadTexture(std::string filename,
                                          std::string fileID)
{
    // TODO: Evaluate if Texture should be stored in stack or heap
    // TODO: Same texture could be used in multiple objects and should
    // therefore be stored outside any GraphicComponent
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        std::cout << "Failed to load: " << filename << std::endl;
        return false;
    }
    textureMap_[fileID] = texture;
    return true;
}

void PlayerGraphicsComponent::SetCurrentAnimation(Entity& entity)
{
    switch (entity.currentState_) {
        case EntityState::IDLE:
            current_animation_ = animation_map_[EntityState::IDLE];
            break;
        case EntityState::RUN:
            current_animation_ = animation_map_[EntityState::RUN];
            break;
        case EntityState::JUMP:
            current_animation_ = animation_map_[EntityState::JUMP];
            break;
        default:
            std::cout << "Not good, no state found to set texture" << std::endl;
            break;
    }
    if (current_animation_ != nullptr) {
        sprite_ = current_animation_->GetSprite();
    } else {
        std::cout << "Error, current_animation is null" << std::endl;
    }
}
