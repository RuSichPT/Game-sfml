#include "EventHandler.h"
#include "Config.h"
#include "Game.h"

void EventHandler::handle()
{
	auto window = game->getGameView()->getRenderWindow();

	Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window->close();
		}
		else if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				Cell cell;
				cell.x = event.mouseButton.x / (int)SIZE_CELL;
				cell.y = event.mouseButton.y / (int)SIZE_CELL;
				cell.value = game->getGameField(cell.x, cell.y);
				game->setSelectedCell(cell);
			}
		}
	}
}

EventHandler::EventHandler(Game* game)
{
	this->game = game;
}

