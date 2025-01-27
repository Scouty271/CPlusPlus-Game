#include "Map.h"

Map::Map()
{	
	//mMapgenerator.GenerateMap(mSize, mTextureholder.getTexture("grass.png", texture_mGras));
}

Map::Map(Vector2i size)
{
	// Äußerer Vector stellt die Zeilen dar
	// Innerer Vector stellt die Felder dar.
	setSize(size);
}

Map::~Map()
{
}

void Map::setSize(Vector2i newSize)
{
	mSize = newSize;
	mMap.resize(newSize.y);
	for (size_t i = 0; i < mMap.size(); i++)
	{
		mMap[i].resize(newSize.x);
	}
}

void Map::setField(int x, int y, Field field)
{
	if (x < 0 || x >= mSize.x || y < 0 || y >= mSize.y)
		return;
	mMap[y][x] = field;
}

Field & Map::getField(int x, int y)
{
	return mMap[y][x];
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (size_t zeile = 0; zeile < mMap.size(); zeile++)
	{
		for (size_t spalte = 0; spalte < mMap[zeile].size(); spalte++)
		{
			target.draw(mMap[zeile][spalte], states);
		}
	}
}
