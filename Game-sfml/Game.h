#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "GameView.h"

using namespace sf;

struct Cell_struct
{
	int numCellX = 0xFFFFFFFF;
	int numCellY = 0xFFFFFFFF;
	bool hasFigure = false;
};

class Game
{
public:
	Game();
	~Game();

	void start();
	void setSelected(Cell_struct cell);
	Cell_struct getSelectedCell();
	void setGameField(int numX, int numY, Cell value);
	Cell getGameField(int numX, int numY);
	GameView* getGameView() { return view; }
	void printGameField();
private:
	GameView* view;
	Cell_struct selectedCell;
	Cell gameField[SIZE_X][SIZE_Y] = { Cell::EMPTY };

	void initGameField(int numFigures);
};

