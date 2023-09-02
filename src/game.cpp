#include "game.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <memory>

#include "game_state.hpp"
#include "circle.hpp"

void Game::initWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window_ = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(width_, height_), title_, sf::Style::Default, settings);
    window_->setFramerateLimit(kFrame_rate);
}

void Game::initState()
{
    states_.push(static_cast<State*>(new GameState(window_)));
}

void Game::updateDeltaTime() { dt_ = deltaClock_.restart().asSeconds(); }
void Game::update()
{
    this->event();

    if (!states_.empty()) {
        states_.top()->update(dt_);
    }
}

void Game::event()
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

void Game::render()
{
    // Clear screen
    window_->clear(sf::Color::Black);

    if (!states_.empty()) {
        states_.top()->render();
    }

    // Not sure but display sounds good
    window_->display();
}

void Game::run()
{
    while (window_->isOpen()) {
        this->updateDeltaTime();
        this->update();
        this->render();
    }
}
