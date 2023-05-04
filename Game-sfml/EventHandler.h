#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

class EventHandler
{
public:
	void start(Game* game);
private:
	Event event;
};

