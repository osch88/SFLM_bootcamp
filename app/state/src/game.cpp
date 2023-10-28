#include "game.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <memory>

#include "game_state.hpp"

void Game::InitWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window_ = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(width_, height_), title_, sf::Style::Default, settings);
    window_->setFramerateLimit(kFrame_rate);
}

void Game::InitState()
{
    states_.push(static_cast<State*>(new GameState(window_)));
}

void Game::updateDeltaTime() { dt_ = deltaClock_.restart().asSeconds(); }
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
        if (event_.type == sf::Event::Closed ||
            event_.key.code == sf::Keyboard::Escape) {
            window_->close();
        }
    }
}

void Game::Render()
{
    // Clear screen
    window_->clear(sf::Color::Black);

    if (!states_.empty()) {
        states_.top()->Render(dt_);
    }

    // Not sure but display sounds good
    window_->display();
}

void Game::Run()
{
    while (window_->isOpen()) {
        this->updateDeltaTime();
        this->Update();
        this->Render();
    }
}
