#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "GameView.h"
#include "EventHandler.h"

using namespace sf;

struct SelectedCell
{
	int numCellX = 0xFFFFFFFF;
	int numCellY = 0xFFFFFFFF;
	Cell cell = Cell::EMPTY;
};

class Game
{
public:
	Game();
	~Game();

	void start();
	void printGameField();

	void setSelected(SelectedCell cell) { selectedCell = cell; }
	SelectedCell getSelectedCell() { return selectedCell; }
	void setGameField(int numX, int numY, Cell value) { gameField[numX][numY] = value; }
	Cell getGameField(int numX, int numY) { return gameField[numX][numY]; }
	GameView* getGameView() { return view; }
private:
	GameView* view;
	EventHandler* handler;
	SelectedCell selectedCell;
	Cell gameField[SIZE_X][SIZE_Y] = { Cell::EMPTY };

	void initGameField(int numFigures);
};

