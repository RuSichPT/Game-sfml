#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

using namespace sf;

enum FigureColor
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
	void setPosition(int numCellX, int numCellY);
	Sprite* getSprite() { return sprite; };
private:
	Texture* texture;
	Sprite* sprite;

	int numCellX;
	int numCellY;
};

