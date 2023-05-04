#include "Figure.h"

const Vector2f offset(40, 20);

Figure::Figure(FigureColor color, int numCellX, int numCellY)
{
	texture = new Texture();
	if (color == WHITE)
		texture->loadFromFile("..\\Images\\white.png");
	else
		texture->loadFromFile("..\\Images\\black.png");

	sprite = new Sprite(*texture);
	sprite->setScale(0.4, 0.4);
	sprite->setPosition(Vector2f(numCellX * SIZE_CELL, numCellY * SIZE_CELL) + offset);

	this->numCellX = numCellX;
	this->numCellY = numCellY;
}

Figure::~Figure()
{
	delete texture;
	delete sprite;
}

void Figure::move(int dx, int dy)
{
	sprite->move(dx, dy);
}

void Figure::setPosition(int numCellX, int numCellY)
{
	sprite->setPosition(Vector2f(numCellX * SIZE_CELL, numCellY * SIZE_CELL) + offset);
}
