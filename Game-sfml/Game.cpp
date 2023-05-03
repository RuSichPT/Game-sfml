#include "Game.h"
#include "Figure.h"

using namespace sf;

Game::Game()
{
	background = new Texture();
	background->loadFromFile("..\\Images\\board.jpg");
	
	spriteBackground = new Sprite(*background);
	spriteBackground->setScale(SCALE, SCALE);

	Vector2u size = background->getSize();
	window = new RenderWindow(VideoMode(size.x * SCALE, size.y * SCALE), "The Game!");
}

Game::~Game()
{
	delete spriteBackground;
	delete background;
	delete window;
}

void Game::start()
{
	Figure figure(FigureColor::BLACK);

	while (window->isOpen())
	{
		// Обрабатываем события в цикле
		Event event;
		while (window->pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window->close();
		}

		// Установка цвета фона - белый
		window->clear(Color::White);
		// Отрисовка Бэкграунда
		window->draw(*spriteBackground);
		window->draw(*figure.getSprite());
		// Отрисовка окна
		window->display();
	}
}