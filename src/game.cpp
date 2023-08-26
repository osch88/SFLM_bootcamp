#include "game.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <memory>

#include "game_state.hpp"
#include "circle.hpp"

void Game::InitWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window_ = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(height_, width_), title_, sf::Style::Default, settings);
    window_->setFramerateLimit(kFrame_rate);
}

void Game::InitState()
{
    states_.push(static_cast<State*>(new GameState(window_)));
}

void Game::UpdateDeltaTime() { dt_ = deltaClock_.restart().asSeconds(); }
void Game::Update()
{
    this->Event();

    if (!states_.empty()) {
        states_.top()->Update(dt_);
    }
}

void Game::Event()
{
    while (window_->pollEvent(event_)) {
        if (event_.type == sf::Event::Closed) {
            window_->close();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            std::cout << "Key pressed" << std::endl;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::cout << "Mouse pressed" << std::endl;
        }
    }
}

void Game::Render()
{
    // Clear screen
    window_->clear(sf::Color::Magenta);

    if (!states_.empty()) {
        states_.top()->Render();
    }

    // Not sure but display sounds good
    window_->display();
}

void Game::Run()
{
    while (window_->isOpen()) {
        this->UpdateDeltaTime();
        this->Update();
        this->Render();
    }
}
