#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "GameView.h"
#include "EventHandler.h"
#include "Ai.h"

using namespace sf;

class Game
{
public:
	Game();
	~Game();

	void start();
	bool canMove(Cell from, Cell to);
	bool moveFigure(Cell from, Cell to);
	void printGameField();
	bool isEnd();

	void setSelectedCell(Cell cell) { selectedCell = cell; }
	Cell getSelectedCell() { return selectedCell; }
	void setGameField(int numX, int numY, CellValue value) { gameField[numX][numY] = value; }
	CellValue getGameField(int numX, int numY) { return gameField[numX][numY]; }
	GameView* getGameView() { return view; }
	FigureColor getWinner() { return winner; }
	void setNextMove(NextMove nextMove) { this->nextMove = nextMove; }
	NextMove getNextMove() { return nextMove; }

private:
	GameView* view;
	EventHandler* handler;
	Ai* ai;
	Cell selectedCell;
	CellValue gameField[SIZE_X][SIZE_Y] = { CellValue::EMPTY };
	FigureColor winner;
	NextMove nextMove = NextMove::PLAYER;


	void initGameField();
};

