#include "EventHandler.h"
#include "Config.h"
#include "Game.h"

void EventHandler::handle()
{
	RenderWindow* window = game->getGameView()->getRenderWindow();

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
				if (game->getNextMove() == NextMove::PLAYER)
				{
					Cell to;
					to.x = event.mouseButton.x / (int)SIZE_CELL;
					to.y = event.mouseButton.y / (int)SIZE_CELL;
					to.value = game->getGameField(to.x, to.y);

					Cell from = game->getSelectedCell();
					if (from.value != CellValue::EMPTY)
					{
						if (game->moveFigure(from, to)) {
							game->setNextMove(NextMove::AI);
						}
						from.value = CellValue::EMPTY;
					}
					else
					{
						memcpy(&from, &to, sizeof(Cell));
					}
					game->setSelectedCell(from);
					game->printGameField();
				}
			}
		}
	}
}

EventHandler::EventHandler(Game* game)
{
	this->game = game;
}

