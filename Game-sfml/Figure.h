#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

enum FigureColor
{
	BLACK,
	WHITE
};

class Figure
{
public:
	Figure(FigureColor color);
	~Figure();

	void move(int dx, int dy);
	Sprite* getSprite() { return sprite; };
private:
	Texture* texture;
	Sprite* sprite;

};

