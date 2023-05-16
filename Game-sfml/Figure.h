#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include <memory>

using namespace sf;
using namespace std;

enum class FigureColor
{
	BLACK,
	WHITE
};

class Figure
{
public:
	Figure(FigureColor color, int numCellX, int numCellY);

	void setPosition(int newNumCellX, int newNumCellY);
	shared_ptr<Sprite> getSprite() { return sprite; };
	FigureColor getColor() { return color; };
private:
	unique_ptr<Texture> texture;
	shared_ptr<Sprite> sprite;
	FigureColor color;

	int numCellX;
	int numCellY;
};

