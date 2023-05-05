#include "Game.h"
#include "Figure.h"
#include <iostream>
#include "EventHandler.h"

using namespace sf;
using namespace std;

Game::Game()
{
	initGameField();
	printGameField();

	view = new GameView(this);
	handler = new EventHandler(this);
}

Game::~Game()
{
	delete view;
	delete handler;
}

void Game::start()
{
	while (view->getRenderWindow()->isOpen())
	{
		handler->handle();
		view->drow();
	}
}

void Game::moveFigure(Cell from, Cell to)
{
	if (canMove(from, to))
	{
		gameField[from.x][from.y] = CellValue::EMPTY;
		gameField[to.x][to.y] = from.value;
	}
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

bool Game::isEnd()
{
	int numPointsWhite = 0;
	for (size_t i = 0; i < NUM_FIGURES; i++)
	{
		for (size_t j = 0; j < NUM_FIGURES; j++)
		{
			if (gameField[i][j] == CellValue::WHITE)
			{
				numPointsWhite++;
			}
		}
	}

	int numPointsBlack = 0;
	for (size_t i = SIZE_X - NUM_FIGURES; i < SIZE_X; i++)
	{
		for (size_t j = SIZE_Y - NUM_FIGURES; j < SIZE_Y; j++)
		{
			if (gameField[i][j] == CellValue::BLACK)
			{
				numPointsBlack++;
			}
		}
	}
	if (numPointsWhite == NUM_FIGURES * NUM_FIGURES)
	{
		winner = FigureColor::WHITE;
		return true;
	}
	else if (numPointsBlack == NUM_FIGURES * NUM_FIGURES)
	{
		winner = FigureColor::BLACK;
		return true;
	}

	return false;
}

bool Game::canMove(Cell from, Cell to)
{
	bool cond1 = to.value == CellValue::EMPTY;
	bool cond2 = from.value != CellValue::EMPTY;

	int deltaX = abs(from.x - to.x);
	int deltaY = abs(from.y - to.y);
	bool cond3 = (deltaX == 1 && deltaY == 0) || (deltaX == 0 && deltaY == 1);

	return cond1 && cond2 && cond3;
}

void Game::initGameField()
{
	for (size_t i = 0; i < NUM_FIGURES; i++)
	{
		for (size_t j = 0; j < NUM_FIGURES; j++)
		{
			gameField[i][j] = CellValue::BLACK;
		}
	}

	for (size_t i = SIZE_X - NUM_FIGURES; i < SIZE_X; i++)
	{
		for (size_t j = SIZE_Y - NUM_FIGURES; j < SIZE_Y; j++)
		{
			gameField[i][j] = CellValue::WHITE;
		}
	}
}
