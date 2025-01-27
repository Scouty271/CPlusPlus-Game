#pragma once

#include "TextureIdentifiers.h"
#include <SFML\Graphics.hpp>
#include <map>
#include <string>
#include <memory>

using namespace std;
using namespace sf;

class TextureHolder
{
public:
	TextureHolder();
	~TextureHolder();

	void load(string filename, Textures::ID id);
	Texture& get(Textures::ID id);

private:
	map<Textures::ID, unique_ptr<Texture>> mTextures;
};

