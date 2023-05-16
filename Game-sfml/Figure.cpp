#include "Figure.h"

const Vector2f offset(40, 20);

Figure::Figure(FigureColor color, int numCellX, int numCellY)
	:color{ color }, numCellX{ numCellX }, numCellY{ numCellY }
{
	texture = make_unique<Texture>();
	if (color == FigureColor::WHITE)
		texture->loadFromFile("..\\Images\\white.png");
	else
		texture->loadFromFile("..\\Images\\black.png");

	sprite = make_shared<Sprite>(*texture);
	sprite->setScale(0.4f, 0.4f);
	sprite->setPosition(Vector2f(numCellX* SIZE_CELL, numCellY* SIZE_CELL) + offset);
}

void Figure::setPosition(int newNumCellX, int newNumCellY)
{
	sprite->setPosition(Vector2f(newNumCellX * SIZE_CELL, newNumCellY * SIZE_CELL) + offset);
}
