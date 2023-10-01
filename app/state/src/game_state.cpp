#include "game_state.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

#include "state.hpp"

void GameState::EndState() {}

void GameState::Update(const float& dt) { player_->Update(dt); }

void GameState::Render(const float& dt, std::shared_ptr<sf::RenderTarget> target)
{
    (void) target;
    player_->Render(dt, window_);
}
