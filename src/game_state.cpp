#include "game_state.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

#include "state.hpp"

void GameState::endState() {}

void GameState::update(const float& dt) { player_->update(dt); }

void GameState::render(std::shared_ptr<sf::RenderTarget> target)
{
    if (!target) {
        player_->render(this->window_);
        // Go on
    }
}
