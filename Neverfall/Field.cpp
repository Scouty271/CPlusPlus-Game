#include "Field.h"



Field::Field()
{
}

Field::Field(Type type, Vector2f position, Sprite sprite)
	: mType{ type }
	, mPosition{ position }
	, mSprite{ sprite }
{
	mSprite.setPosition(mPosition * 32.0f);
}


Field::~Field()
{
}

void Field::update(Time dt)
{
}

void Field::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(mSprite, states);
}
