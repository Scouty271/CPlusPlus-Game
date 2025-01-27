#pragma once
//#include "Mapgenerator.h"
//#include "TextureHolder.h"
#include "Field.h"
#include <vector>

using namespace std;
using namespace sf;

class Map : public sf::Drawable
{
public:
	Map();
	Map(Vector2i size);
	~Map();

	void setSize(Vector2i newSize);
	void setField(int x, int y, Field field);

	Vector2i getSize() { return mSize; }
	Field& getField(int x, int y);

	// Geerbt über Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	//Mapgenerator mMapgenerator;
	//TextureHolder mTextureholder;

	sf::Vector2i mSize;
	//sf::Texture texture_mGras;
	//sf::Vector2i mMap;
	
	vector<vector<Field>> mMap;
};

