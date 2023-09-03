#pragma once

#include "entity.hpp"
#include "player_graphic_component.hpp"
#include "player_input_component.hpp"
#include "player_physics_components.hpp"
#include "state.hpp"

class GameState : public State {
private:
    Entity* player_;

public:
    GameState(std::shared_ptr<sf::RenderWindow> window) : State(window)
    {
        player_ = new Entity(new PlayerInputComponent(),
                             new PlayerGraphicsComponent(),
                             new PlayerPhysicsComponent());
    }
    // virtual ~GameState();

    void EndState() override;
    void Update(const float& dt) override;
    void Render(std::shared_ptr<sf::RenderTarget> target = nullptr) override;
};
