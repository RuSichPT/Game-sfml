#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

using namespace sf;

struct Cell_struct
{
	int numCellX = 0xFFFFFFFF;
	int numCellY = 0xFFFFFFFF;
	bool hasFigure = false;
};

enum class Cell
{
	EMPTY,
	BLACK,
	WHITE
};

class Game
{
public:
	Game();
	~Game();

	void start();
	RenderWindow* getWindow();
	void setSelected(Cell_struct cell);
	Cell_struct getSelectedCell();
	void setGameField(int numX, int numY, Cell value);
	Cell getGameField(int numX, int numY);
	void printGameField();
private:
	RenderWindow* window;
	Texture* background;
	Sprite* spriteBackground;
	Vector2u sizeField;
	Cell_struct selectedCell;	

	Cell gameField[SIZE_X][SIZE_Y] = {Cell::EMPTY};

	void initGameField(int numFigures);
};

