#include "Game.h"

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
	while (window->isOpen())
	{
		// ������������ ������� � �����
		Event event;
		while (window->pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window->close();
		}

		// ��������� ����� ���� - �����
		window->clear(Color::White);
		// ��������� ����������
		window->draw(*spriteBackground);
		// ��������� ����
		window->display();
	}
}