#include "Player.h"
#include "Game.h"

void Player::act()
{
	Cell selectedCell = game->getSelectedCell();
	if (selectedCell.isBlack())
	{
		from = selectedCell;
		game->clearSelectedCell();
	}
	else if (from.isInit() && selectedCell.isEmpty())
	{
		to = selectedCell;
		game->clearSelectedCell();
	}

	if (game->moveFigure(from, to))
	{
		from.x = to.x;
		from.y = to.y;

		game->printGameField();
		game->setNextMove(NextMove::AI);
	}

	to.clear();
}
