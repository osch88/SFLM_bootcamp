#pragma once

#include "entity.hpp"
#include "state.hpp"
#include "player.hpp"

class GameState : public State {
private:
    Entity* player_;
public:
    GameState(std::shared_ptr<sf::RenderWindow> window) : State(window)
    {
        player_ = new Player();
    }
    // virtual ~GameState();

    void endState() override;
    void update(const float& dt) override;
    void render(std::shared_ptr<sf::RenderTarget> target = nullptr) override;
};
