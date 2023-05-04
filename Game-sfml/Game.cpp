#include "Game.h"
#include "Figure.h"
#include <iostream>
#include "EventHandler.h"

using namespace sf;
using namespace std;

Game::Game()
{
	initGameField(NUM_FIGURES);
	printGameField();

	background = new Texture();
	background->loadFromFile("..\\Images\\board.jpg");

	spriteBackground = new Sprite(*background);
	spriteBackground->setScale(SCALE, SCALE);

	sizeField = background->getSize();
	sizeField.x = unsigned int(sizeField.x * SCALE);
	sizeField.y = unsigned int(sizeField.y * SCALE);

	window = new RenderWindow(VideoMode(sizeField.x, sizeField.y), "The Game!");
}

Game::~Game()
{
	delete spriteBackground;
	delete background;
	delete window;
}

void Game::start()
{
	Figure* figuresBlack[ NUM_FIGURES * NUM_FIGURES] = { nullptr };
	Figure* figuresWhite[NUM_FIGURES * NUM_FIGURES] = { nullptr };

	int black = 0;
	int white = 0;
	for (size_t i = 0; i < SIZE_X; i++)
	{
		for (size_t j = 0; j < SIZE_Y; j++)
		{
			if (gameField[i][j] == 1)
			{
				figuresBlack[black] = new Figure(FigureColor::BLACK, i, j);
				black++;
			}
			if (gameField[i][j] == 2)
			{
				figuresWhite[white] = new Figure(FigureColor::WHITE, i, j);
				white++;
			}
		}
	}

	int currentX = 0xFFFF;
	int currentY = 0xFFFF;
	int current = 0;
	while (window->isOpen())
	{
		//EventHandler handler;
		//handler.start(this);

		// Обрабатываем события в цикле
		Event event;
		while (window->pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window->close();

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					int numCell_x = event.mouseButton.x / SIZE_CELL;
					int numCell_y = event.mouseButton.y / SIZE_CELL;

					if (current == 1 || current == 2)
					{
						if (gameField[numCell_x][numCell_y] == 0)
						{
							gameField[currentX][currentY] = 0;
							gameField[numCell_x][numCell_y] = current;
							current = 0;
						}
					}
					else
					{
						current = gameField[numCell_x][numCell_y];
						currentX = numCell_x;
						currentY = numCell_y;
					}

					//cout << "the left button was pressed" << endl;
					//cout << "mouse x: " << event.mouseButton.x << endl;
					//cout << "mouse y: " << event.mouseButton.y << endl;
					//cout << "cell x: " << numCell_x << endl;
					//cout << "cell y: " << numCell_y << endl;
					printGameField();
				}
			}
		}

		// Установка цвета фона - белый
		window->clear(Color::White);
		// Отрисовка Бэкграунда
		window->draw(*spriteBackground);

		int black = 0;
		int white = 0;
		for (size_t i = 0; i < SIZE_X; i++)
		{
			for (size_t j = 0; j < SIZE_Y; j++)
			{
				if (gameField[i][j] == 1)
				{
					figuresBlack[black]->setPosition(i, j);
					black++;
				}
				if (gameField[i][j] == 2)
				{
					figuresWhite[white]->setPosition(i, j);
					white++;
				}
			}
		}

		for (size_t i = 0; i < NUM_FIGURES * NUM_FIGURES; i++)
		{
			window->draw(*figuresBlack[i]->getSprite());
			window->draw(*figuresWhite[i]->getSprite());
		}
		// Отрисовка окна
		window->display();
	}

	for (size_t i = 0; i < NUM_FIGURES * NUM_FIGURES; i++)
	{
		delete figuresBlack[i];
		delete figuresWhite[i];
	}
}

RenderWindow* Game::getWindow()
{
	return window;
}

void Game::setSelected(Cell cell)
{
	selectedCell = cell;
}

Cell Game::getSelectedCell()
{
	return selectedCell;
}

void Game::setGameField(int numX, int numY, int value)
{
	gameField[numX][numY] = value;
}

int Game::getGameField(int numX, int numY)
{
	return gameField[numX][numY];
}

void Game::printGameField()
{
	for (size_t j = 0; j < SIZE_Y; j++)
	{
		for (size_t i = 0; i < SIZE_X; i++)
		{
			cout << " " << gameField[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Game::initGameField(int numFigures)
{
	//for (int64_t i = 0; i < WIDTH; i++)
	//{
	//	for (int64_t j = 0; j < HIGHT; j++)
	//	{
	//		gameField[i][j].x1 = SIZE_BORDER + i * SIZE_CELL;
	//		gameField[i][j].x2 = SIZE_BORDER + (i + 1) * SIZE_CELL;
	//		gameField[i][j].y1 = SIZE_BORDER + j * SIZE_CELL;
	//		gameField[i][j].y2 = SIZE_BORDER + (j + 1) * SIZE_CELL;
	//	}
	//}

	for (size_t i = 0; i < numFigures; i++)
	{
		for (size_t j = 0; j < numFigures; j++)
		{
			gameField[i][j] = 1;
		}
	}

	for (size_t i = SIZE_X - numFigures; i < SIZE_X; i++)
	{
		for (size_t j = SIZE_Y - numFigures; j < SIZE_Y; j++)
		{
			gameField[i][j] = 2;
		}
	}
}
