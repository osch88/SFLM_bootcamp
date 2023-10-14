#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <memory>

#include "animation.hpp"
#include "entity.hpp"
#include "player_graphic_component.hpp"

void PlayerGraphicsComponent::InitTextures()
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
}

void PlayerGraphicsComponent::InitAnimation()
{
    sf::IntRect bounds = {0, 0, 80, 80};

    std::shared_ptr<Animation> idle =
        std::make_shared<Animation>(textureMap_["idle"], 0.07f, bounds);
    animation_map_[EntityState::IDLE] = idle;

    std::shared_ptr<Animation> run =
        std::make_shared<Animation>(textureMap_["run"], 0.04f, bounds);
    animation_map_[EntityState::RUN] = run;

    std::shared_ptr<Animation> jump =
        std::make_shared<Animation>(textureMap_["jump"], 0.04f, bounds);
    animation_map_[EntityState::JUMP] = jump;
}

void PlayerGraphicsComponent::Update(Entity& entity, const float& dt,
                                     std::shared_ptr<sf::RenderTarget> target)
{
    SetCurrentAnimation(entity);
    current_animation_->Play(dt, entity.scale_, entity.position_);
    target->draw(*(current_animation_->GetSprite()));
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
    bool reset = false;

    if (entity.currentState_ != previous_state_) {
        reset = true;
    }

    switch (entity.currentState_) {
        case EntityState::IDLE:
            current_animation_ = animation_map_[EntityState::IDLE];
            previous_state_ = EntityState::IDLE;
            break;
        case EntityState::RUN:
            current_animation_ = animation_map_[EntityState::RUN];
            previous_state_ = EntityState::RUN;
            break;
        case EntityState::JUMP:
            current_animation_ = animation_map_[EntityState::JUMP];
            previous_state_ = EntityState::JUMP;
            break;
        default:
            std::cout << "Not good, no state found to set texture" << std::endl;
            break;
    }

    if (reset) {
        current_animation_->Reset();
    }
}
