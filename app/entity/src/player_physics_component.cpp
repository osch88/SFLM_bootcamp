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
    entity.position_ = {
        entity.position_.x + entity.velocity_.x * entity.speed_ * dt,
        entity.position_.y + entity.velocity_.y * entity.speed_ * dt};
}
