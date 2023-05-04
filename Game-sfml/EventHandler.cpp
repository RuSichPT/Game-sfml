#include "EventHandler.h"
#include "Config.h"

void EventHandler::start(Game* game)
{
	while (game->getWindow()->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			game->getWindow()->close();
		}
		else if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				int newNumCellX = event.mouseButton.x / SIZE_CELL;
				int newNumCellY = event.mouseButton.y / SIZE_CELL;
				
				Cell selectedCell = game->getSelectedCell();

				if (selectedCell.hasFigure)
				{
					game->setGameField(selectedCell.numCellX, selectedCell.numCellY, 0);
					game->setGameField(newNumCellX, newNumCellY, 1);
					selectedCell.hasFigure = 0;
				}
				else
				{
					selectedCell.hasFigure = game->getGameField(newNumCellX, newNumCellY);
					selectedCell.numCellX = newNumCellX;
					selectedCell.numCellY = newNumCellY;
				}
				game->setSelected(selectedCell);
				game->printGameField();
			}
		}
		//// Была ли нажата клавиша на клавиатуре?
		//if (event.type == Event::KeyPressed)
		//{
		//	if (event.key.code == Keyboard::Left)
		//		figure.move(-5, 0);
		//	else if (event.key.code == Keyboard::Right)
		//		figure.move(5, 0);
		//	else if (event.key.code == Keyboard::Up)
		//		figure.move(0, -5);
		//	else if (event.key.code == Keyboard::Down)
		//		figure.move(0, 5);
		//}
	}
}
