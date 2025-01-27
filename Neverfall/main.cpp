#include <SFML\Graphics.hpp>
#include "Game.h"

int main()
{
	Game game{ sf::Vector2i{800,600}, "Neverfall" };
	game.run();
}