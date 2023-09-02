#include "player.hpp"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

void Player::init()
{
    graphic_.LoadTexture("../assert/redHood/idle.png");

    this->velocity_ = 300.0f;
    this->position_ = {100.0f, 100.0f};

    this->scale_.x = 3.0f;
    this->scale_.y = 3.0f;
}

void Player::Move(const float& dt, const float x, const float y)
{
    this->position_ = {this->position_.x + x * this->velocity_ * dt,
                       this->position_.y + y * this->velocity_ * dt};
}

void Player::Update(const float& dt) { input_->Update(dt, *this); }

void Player::Render(std::shared_ptr<sf::RenderTarget> target)
{
    graphic_.Update(*this, target);
}

Player::~Player()
{
    delete input_;
    input_ = nullptr;
}
