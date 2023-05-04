#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

using namespace sf;

struct Cell
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
	RenderWindow* getWindow();
	void setSelected(Cell cell);
	Cell getSelectedCell();
	void setGameField(int numX, int numY, int value);
	int getGameField(int numX, int numY);
	void printGameField();
private:
	RenderWindow* window;
	Texture* background;
	Sprite* spriteBackground;
	Vector2u sizeField;
	Cell selectedCell;	

	int gameField[SIZE_X][SIZE_Y] = {0};

	void initGameField(int numFigures);
};

