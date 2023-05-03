#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class EventHandler
{
public:
	EventHandler(RenderWindow* window);
	void start();
private:
	RenderWindow* window;
};

