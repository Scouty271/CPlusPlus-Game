#include "Mapgenerator.h"
#include "Random.h"


Mapgenerator::Mapgenerator(TextureHolder& textures)
	: mTextures{ textures }
{
}

Map Mapgenerator::GenerateMap(sf::Vector2i size)
{
	Map map{ size };

	for (size_t zeile = 0; zeile < size.y; zeile++)
	{
		for (size_t spalte = 0; spalte < size.x; spalte++)
		{
			Sprite s{ mTextures.get(Textures::FIELD_GRASS) };
			Uint8 v = (Uint8)ae::Random::instance()->NextInt(200, 255);
			Color c{ v,v,v };
			s.setColor(c);
			Field f{ Field::Grass, Vector2f{(float)spalte, (float)zeile}, s };
			map.setField(spalte, zeile, f);
		}
	}

	return map;
}