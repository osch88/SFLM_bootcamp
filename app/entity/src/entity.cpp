#include "entity.hpp"

Entity::~Entity()
{
    delete input_;
    input_ = nullptr;
    delete graphic_;
    graphic_ = nullptr;
    delete physics_;
    physics_ = nullptr;
}

void Entity::Move(const float& dt, const float velocity_X, const float velocity_Y)
{
    this->position_ = {this->position_.x + velocity_X * this->speed_ * dt,
                       this->position_.y + velocity_Y * this->speed_ * dt};
}
void Entity::Update(const float& dt)
{ 
    input_->Update(dt, *this);
    physics_->Update(*this, dt);
}

void Entity::Render(const float& dt, std::shared_ptr<sf::RenderTarget> target)
{
    graphic_->Update(*this, dt, target);
}
