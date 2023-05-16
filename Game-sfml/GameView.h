#pragma once

#include <SFML/Graphics.hpp>
#include "Figure.h"
#include "Config.h"
#include <vector>
#include <memory>
#include <array>

class Game;

using namespace sf;
using namespace std;

class GameView
{
public:
	GameView(Game* game);
	void drow();

	shared_ptr<RenderWindow> getRenderWindow() { return window; }
private:
	Game* game;
	shared_ptr<RenderWindow> window;
	unique_ptr<Texture> background;
	unique_ptr<Sprite> spriteBackground;

	array<unique_ptr<Figure>, NUM_FIGURES* NUM_FIGURES> figuresBlack;
	array<unique_ptr<Figure>, NUM_FIGURES* NUM_FIGURES> figuresWhite;

	void initBackground();
	void initRenderWindow();
	void initFigures();
	void drowFigures();
	void drowFinishWindow();
};

