#include "Figure.h"

const Vector2f offset(40, 20);

Figure::Figure(FigureColor color, int numCellX, int numCellY)
{
	texture = new Texture(); 
	if (color == FigureColor::WHITE)
		texture->loadFromFile("..\\Images\\white.png");
	else
		texture->loadFromFile("..\\Images\\black.png");

	sprite = new Sprite(*texture);
	sprite->setScale(0.4f, 0.4f);
	sprite->setPosition(Vector2f(numCellX * SIZE_CELL, numCellY * SIZE_CELL) + offset);

	this->numCellX = numCellX;
	this->numCellY = numCellY;
	this->color = color;
}

Figure::~Figure()
{
	delete texture;
	delete sprite;
}

void Figure::setPosition(int newNumCellX, int newNumCellY)
{
	sprite->setPosition(Vector2f(newNumCellX * SIZE_CELL, newNumCellY * SIZE_CELL) + offset);
}
