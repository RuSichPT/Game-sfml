#include "Figure.h"

const Vector2f offset(40, 20);

Figure::Figure(FigureColor color, Vector2f position)
{
	texture = new Texture();
	if (color == WHITE)
		texture->loadFromFile("..\\Images\\white.png");
	else
		texture->loadFromFile("..\\Images\\black.png");

	sprite = new Sprite(*texture);
	sprite->setScale(0.4, 0.4);
	sprite->setPosition(position + offset);

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
