#include "entity.hpp"
#include "player_physics_components.hpp"

void PlayerPhysicsComponent::Init(Entity& entity)
{
    entity.velocity_ = 300.0f;
    entity.position_ = {100.0f, 100.0f};

    entity.scale_.x = 3.0f;
    entity.scale_.y = 3.0f;
}

void PlayerPhysicsComponent::Update(Entity& entity, const float& dt,
                                    const float x, const float y)
{
    entity.position_ = {entity.position_.x + x * entity.velocity_ * dt,
                        entity.position_.y + y * entity.velocity_ * dt};
}
