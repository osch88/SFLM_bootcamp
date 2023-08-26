#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Network.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <stack>
#include <string>
#include <vector>

#include "circle.hpp"
#include "game_state.hpp"
#include "entity.hpp"


constexpr int kFrame_rate = 60;

class Game {
private:
    // Variables for Window
    int const height_;
    int const width_;
    std::string title_;
    sf::Event event_;
    std::shared_ptr<sf::RenderWindow> window_;
    void InitWindow();

    // Deltatime
    sf::Clock deltaClock_;
    float dt_;
    void UpdateDeltaTime();

    // State
    void InitState();
    std::stack<State*> states_;

public:
    // Constructor
    Game(int height, int width, std::string title)
        : height_(height), width_(width), title_(title)
    {
        InitWindow();
        InitState();
    }

    // Public Methods
    void Update();
    void Event();
    void Render();
    void Run();
};
