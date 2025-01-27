#include "Game.h"


Game::Game(sf::Vector2i mSize, std::string mTitle)
{
	mWindow.reset(new sf::RenderWindow{ sf::VideoMode{ (unsigned)mSize.x, (unsigned)mSize.y }, mTitle });
	mTargetFPS = seconds(1.0f / 60.0f);

	mTextures.load("grass.png", Textures::FIELD_GRASS);

	Mapgenerator generator{ mTextures };
	mMap = generator.GenerateMap(Vector2i{ 200, 200 });

	mView = mWindow->getDefaultView();
}

Game::~Game()
{
}

void Game::run()
{
	Clock clock;
	Time lag;
	while (mWindow->isOpen())
	{
		lag += clock.restart();
		while (lag >= mTargetFPS)
		{
			lag -= mTargetFPS;
			handleEvent();
			update(mTargetFPS);
		}
		draw();
	}
}

void Game::update(Time dt)
{

}

void Game::draw()
{
	mWindow->clear();
	mWindow->setView(mView);
	mWindow->draw(mMap);
	mWindow->display();
}

void Game::handleEvent()
{
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			mWindow->close();
		}
		if (event.KeyPressed)
		{
			switch (event.key.code)
			{
			case Keyboard::Escape:
				mWindow->close();
				break;
			case Keyboard::Left:
				mView.move(-1.0f, 0.0f);
				break;
			case Keyboard::Right:
				mView.move(1.0f, 0.0f);
				break;
			case Keyboard::Up:
				mView.move(0.0f, -1.0f);
				break;
			case Keyboard::Down:
				mView.move(0.0f, 1.0f);
				break;
			}
		}
	}
}