#include <iostream>

#include "entity.hpp"
#include "player_physics_components.hpp"

void PlayerPhysicsComponent::Init(Entity& entity)
{
    entity.speed_ = 300.0f;
    entity.position_ = {100.0f, 100.0f};

    entity.scale_.x = 3.0f;
    entity.scale_.y = 3.0f;
}

void PlayerPhysicsComponent::Update(Entity& entity, const float& dt)
{
    if (entity.current_state_ == EntityState::JUMP &&
        entity.previous_state_ != EntityState::JUMP) {
        entity.velocity_.y = 750.0f;
        std::cout << "New velocity" << std::endl;
    }

    entity.velocity_.y -= 20 * 9.82f * dt;
    if (entity.position_.y > 1000) {
        entity.velocity_.y = 0;
        // std::cout << "This happened" << std::endl;
    }

    std::cout << "velocity_.y: " << entity.velocity_.y << "\tposition_.y: "
              << entity.position_.y << std::endl;

    entity.position_.x += entity.velocity_.x * entity.speed_ * dt;
    entity.position_.y -= entity.velocity_.y * entity.speed_ * .01 * dt;
}
