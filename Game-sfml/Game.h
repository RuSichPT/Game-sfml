#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "GameView.h"
#include "EventHandler.h"

using namespace sf;

struct Cell
{
	int x = 0xFFFFFFFF;
	int y = 0xFFFFFFFF;
	CellValue value = CellValue::EMPTY;
};

class Game
{
public:
	Game();
	~Game();

	void start();
	void moveFigure(Cell from, Cell to);
	void printGameField();
	bool isEnd();

	void setSelectedCell(Cell cell) { selectedCell = cell; }
	Cell getSelectedCell() { return selectedCell; }
	void setGameField(int numX, int numY, CellValue value) { gameField[numX][numY] = value; }
	CellValue getGameField(int numX, int numY) { return gameField[numX][numY]; }
	GameView* getGameView() { return view; }
	FigureColor getWinner() { return winner; }
private:
	GameView* view;
	EventHandler* handler;
	Cell selectedCell;
	CellValue gameField[SIZE_X][SIZE_Y] = { CellValue::EMPTY };
	FigureColor winner;

	bool canMove(Cell from, Cell to);
	void initGameField();
};

