#include "Figure.h"

Figure::Figure(FigureColor color)
{
	texture = new Texture();
	if (color == WHITE)
		texture->loadFromFile("..\\Images\\white.png");
	else
		texture->loadFromFile("..\\Images\\black.png");

	sprite = new Sprite(*texture);
	sprite->setScale(0.4,0.4);
	sprite->setPosition(Vector2f(45, 20));
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
