#pragma once
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class Field : public Drawable
{
public:
	enum Type
	{
		Grass
	};

public:
	Field();
	Field(Type type, Vector2f position, Sprite sprite);
	~Field();

	void setType(Type type) { mType = type; }
	void setPosition(Vector2f position) { mPosition = position; }
	void setSprite(Sprite sprite) { mSprite = sprite; }

	Type getType() { return mType; }
	Vector2f getPosition() { return mPosition; }
	Sprite& getSprite() { return mSprite; }

	void update(Time dt);

	// Geerbt über Drawable
	virtual void draw(RenderTarget & target, RenderStates states) const override;

private:
	Type mType;
	Vector2f mPosition;
	Sprite mSprite;

};

