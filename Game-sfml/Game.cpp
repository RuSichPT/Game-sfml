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

	Cell* p = &gameField[0][0];
	view = new GameView(&p);
}

Game::~Game()
{
	delete view;
}

void Game::start()
{
	int currentX = 0xFFFF;
	int currentY = 0xFFFF;
	Cell current = Cell::EMPTY;
	while (view->getRenderWindow()->isOpen())
	{
		//EventHandler handler;
		//handler.start(this);

		// Обрабатываем события в цикле
		Event event;
		while (view->getRenderWindow()->pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				view->getRenderWindow()->close();

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					int numCell_x = event.mouseButton.x / SIZE_CELL;
					int numCell_y = event.mouseButton.y / SIZE_CELL;

					if (current == Cell::BLACK || current == Cell::WHITE)
					{
						if (gameField[numCell_x][numCell_y] == Cell::EMPTY)
						{
							gameField[currentX][currentY] = Cell::EMPTY;
							gameField[numCell_x][numCell_y] = current;
							current = Cell::EMPTY;
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

		view->drow();
	}
}


void Game::setSelected(Cell_struct cell)
{
	selectedCell = cell;
}

Cell_struct Game::getSelectedCell()
{
	return selectedCell;
}

void Game::setGameField(int numX, int numY, Cell value)
{
	gameField[numX][numY] = value;
}

Cell Game::getGameField(int numX, int numY)
{
	return gameField[numX][numY];
}

void Game::printGameField()
{
	for (size_t j = 0; j < SIZE_Y; j++)
	{
		for (size_t i = 0; i < SIZE_X; i++)
		{
			cout << " " << (int)gameField[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Game::initGameField(int numFigures)
{
	for (size_t i = 0; i < numFigures; i++)
	{
		for (size_t j = 0; j < numFigures; j++)
		{
			gameField[i][j] = Cell::BLACK;
		}
	}

	for (size_t i = SIZE_X - numFigures; i < SIZE_X; i++)
	{
		for (size_t j = SIZE_Y - numFigures; j < SIZE_Y; j++)
		{
			gameField[i][j] = Cell::WHITE;
		}
	}
}
