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

void Entity::Move(const float& dt, const float x, const float y)
{
    this->position_ = {this->position_.x + x * this->velocity_ * dt,
                       this->position_.y + y * this->velocity_ * dt};
}
void Entity::Update(const float& dt) { input_->Update(dt, *this); }
void Entity::Render(std::shared_ptr<sf::RenderTarget> target)
{
    graphic_->Update(*this, target);
}
