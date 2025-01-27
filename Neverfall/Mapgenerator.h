#pragma once

#include "TextureHolder.h"
#include "Map.h"
#include <SFML\Graphics.hpp>

class Mapgenerator
{
public:
	Mapgenerator(TextureHolder& textures);
	// MapGenerator erstellt Maps.
	// Maps haben eine bestimmte Größe.
	// Maps bestehen aus vielen Feldern.
	// Ein Feld kann von einem bestimmten Typ sein.
	// Ein Feld hat eine bestimmte Position auf der Map.

	Map GenerateMap(sf::Vector2i size);

private:
	TextureHolder& mTextures;
};

