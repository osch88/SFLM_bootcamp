#pragma once

#include "state.hpp"
#include "circle.hpp"

class GameState : public State {
private:
    Circle circle_;
public:
    GameState(std::shared_ptr<sf::RenderWindow> window) : State(window) {}
    // virtual ~GameState();

    void EndState() override;
    void Update(const float& dt) override;
    void Render(std::shared_ptr<sf::RenderTarget> target = nullptr) override;
};
