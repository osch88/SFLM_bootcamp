#include "game.hpp"

constexpr int HEIGHT = 1080;
constexpr int WIDTH = 1920;

int main(/* int argc, char *argv[] */)
{
    Game game(HEIGHT, WIDTH, "Hello World!");
    game.run();
    return 0;
}
