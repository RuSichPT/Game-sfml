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
				int newNumCellX = event.mouseButton.x / SIZE_CELL;
				int newNumCellY = event.mouseButton.y / SIZE_CELL;

				SelectedCell selectedCell = game->getSelectedCell();

				if (selectedCell.cell != Cell::EMPTY)
				{
					if (game->getGameField(newNumCellX, newNumCellY) == Cell::EMPTY)
					{
						game->setGameField(selectedCell.numCellX, selectedCell.numCellY, Cell::EMPTY);
						game->setGameField(newNumCellX, newNumCellY, selectedCell.cell);
						selectedCell.cell = Cell::EMPTY;
					}
				}
				else
				{
					selectedCell.cell = game->getGameField(newNumCellX, newNumCellY);
					selectedCell.numCellX = newNumCellX;
					selectedCell.numCellY = newNumCellY;
				}

				game->setSelected(selectedCell);
				game->printGameField();
			}
		}
	}
}

EventHandler::EventHandler(Game* game)
{
	this->game = game;
}

