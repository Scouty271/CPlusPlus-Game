#include "TextureHolder.h"



TextureHolder::TextureHolder()
{
}


TextureHolder::~TextureHolder()
{
}

void TextureHolder::load(string filename, Textures::ID id)
{
	Texture* t = new Texture();
	if (t->loadFromFile(filename))
	{
		mTextures[id].reset(t);
	}
}

Texture & TextureHolder::get(Textures::ID id)
{
	return *mTextures[id].get();
}

//sf::Texture TextureHolder::getTexture(std::string mTexturePath, sf::Texture texture)
//{
//	texture.loadFromFile(mTexturePath);
//	return texture;
//}
//
//sf::Texture TextureHolder::setTexture()
//{
//	return sf::Texture();
//}
