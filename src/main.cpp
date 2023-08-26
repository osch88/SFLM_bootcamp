#include "game.hpp"

constexpr int HEIGHT = 800;
constexpr int WIDTH = 600;

int main(/* int argc, char *argv[] */)
{
    Game game(HEIGHT, WIDTH, "Hello World!");
    game.Run();
    return 0;
}
