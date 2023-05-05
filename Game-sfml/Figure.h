#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

using namespace sf;

enum class FigureColor
{
	BLACK,
	WHITE
};

class Figure
{
public:
	Figure(FigureColor color, int numCellX, int numCellY);
	~Figure();

	void move(int dx, int dy);
	void setPosition(int newNumCellX, int newNumCellY);
	Sprite* getSprite() { return sprite; };
	FigureColor getColor() { return color; };
private:
	Texture* texture;
	Sprite* sprite;
	FigureColor color;

	int numCellX;
	int numCellY;
};

