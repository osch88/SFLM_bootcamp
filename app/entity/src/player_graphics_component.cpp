#include "player_graphic_component.hpp"

void PlayerGraphicsComponent::Update(Entity& entity,
                                     std::shared_ptr<sf::RenderTarget> target)
{
    sprite_.setScale(entity.scale_.x, entity.scale_.y);
    sprite_.setPosition(entity.position_);
    target->draw(sprite_);
}

bool PlayerGraphicsComponent::LoadTexture(std::string filename)
{
    if (!texture_.loadFromFile(filename)) {
        std::cout << "Failed to load player.png" << std::endl;
        return false;
    }
    this->SetTexture();
    sf::Vector2u textureSize = texture_.getSize();

    this->sprite_.setOrigin(40.0f, 40.0f);
    this->sprite_.setTextureRect(sf::IntRect(0, 0, 80, 80));
    return true;
}

void PlayerGraphicsComponent::SetTexture() { sprite_.setTexture(texture_); }
