#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "GameView.h"
#include "EventHandler.h"
#include "Ai.h"
#include "Player.h"
#include <memory>

using namespace sf;
using namespace std;

class Game
{
public:
	Game();

	void run();
	bool moveFigure(const Cell& from, const Cell& to);
	void printGameField();
	bool isEnd();

	void setSelectedCell(const Cell& cell) { selectedCell = cell; }
	Cell getSelectedCell() { return selectedCell; }
	void clearSelectedCell();

	void setGameField(int numX, int numY, CellValue value) { gameField[numX][numY] = value; }
	CellValue getGameField(int numX, int numY) { return gameField[numX][numY]; }

	shared_ptr<GameView> getGameView() { return view; }
	shared_ptr<Ai> getAi() { return ai; }

	FigureColor getWinner() { return winner; }

	void setNextMove(NextMove nextMove) { this->nextMove = nextMove; }
	NextMove getNextMove() { return nextMove; }

private:
	shared_ptr<GameView> view;
	shared_ptr<EventHandler> handler;
	shared_ptr<Ai> ai;
	shared_ptr<Player> player;

	Cell selectedCell;
	CellValue gameField[SIZE_X][SIZE_Y] = { CellValue::EMPTY };
	FigureColor winner;
	NextMove nextMove = NextMove::PLAYER;

	bool canMove(Cell from, Cell to);
	void initGameField();
};

