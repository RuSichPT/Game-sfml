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
	int i = 7;
	int j = 7;
	Figure figure(FigureColor::BLACK, Vector2f(i * SIZE_CELL * SCALE, j * SIZE_CELL * SCALE));

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

			// ���� �� ������ ������� �� ����������?
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Left)
					figure.move(-5, 0);
				else if (event.key.code == Keyboard::Right)
					figure.move(5, 0);
				else if (event.key.code == Keyboard::Up)
					figure.move(0, -5);
				else if (event.key.code == Keyboard::Down)
					figure.move(0, 5);
			}
		}

		// ��������� ����� ���� - �����
		window->clear(Color::White);
		// ��������� ����������
		window->draw(*spriteBackground);
		window->draw(*figure.getSprite());
		// ��������� ����
		window->display();
	}
}