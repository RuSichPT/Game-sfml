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
	Figure(FigureColor color, Vector2f position);
	~Figure();

	void move(int dx, int dy);
	Sprite* getSprite() { return sprite; };
private:
	Texture* texture;
	Sprite* sprite;

};

