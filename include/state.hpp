#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <vector>

class State {
private:
    std::vector<sf::Texture> textures_;

public:
    State(std::shared_ptr<sf::RenderWindow> window) : window_(window) {}

    std::shared_ptr<sf::RenderWindow> window_;

    virtual void EndState() = 0;
    virtual void Update(const float& dt) = 0;
    virtual void Render(std::shared_ptr<sf::RenderTarget> target = nullptr) = 0;
};
