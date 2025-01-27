#pragma once

#include "TextureHolder.h"
#include "Mapgenerator.h"
#include <SFML\Graphics.hpp>
#include <memory>
#include "Map.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game(sf::Vector2i mSize, std::string title);
	~Game();

	void run();

private:
	void handleEvent();
	void update(Time dt);
	void draw();

private:
	Map mMap;
	Time mTargetFPS;
	std::unique_ptr<sf::RenderWindow>mWindow;
	TextureHolder mTextures;

	View mView;
};

