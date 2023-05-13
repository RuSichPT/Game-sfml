#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "GameView.h"
#include "EventHandler.h"
#include "Ai.h"
#include "Player.h"

using namespace sf;

class Game
{
public:
	Game();
	Game(const Game &game);
	~Game();

	void start();
	bool moveFigure(Cell from, Cell to);
	void printGameField();
	bool isEnd();

	void setSelectedCell(Cell& cell) { selectedCell = cell; }
	Cell getSelectedCell() { return selectedCell; }
	void clearSelectedCell();

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
	Player* player;

	Cell selectedCell;
	CellValue gameField[SIZE_X][SIZE_Y] = { CellValue::EMPTY };
	FigureColor winner;
	NextMove nextMove = NextMove::PLAYER;


	bool canMove(Cell from, Cell to);
	void initGameField();
	void initDynamicMemory();
};

