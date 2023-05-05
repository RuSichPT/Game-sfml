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
