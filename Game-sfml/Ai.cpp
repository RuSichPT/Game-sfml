#include "Ai.h"
#include "Game.h"
#include "Config.h"
#include <ctime>
#include <array>

constexpr int NUM_DIRECTIONS = 4;
constexpr int MAX_WEIGHT = SIZE_X * SIZE_Y * 2;

Ai::Ai(Game* game)
{
	this->game = game;
	weights.reserve(NUM_FIGURES * NUM_FIGURES);
	directionWeights.reserve(4);
}

void Ai::act()
{
	if (game->getNextMove() == NextMove::AI)
	{
		Cell from, to;
		selectCell(&from, &to);
		game->moveFigure(from, to);
		game->setNextMove(NextMove::PLAYER);
	}
}

void Ai::selectCell(Cell* from, Cell* to)
{
	calculateWeights(weights);

	while (true)
	{
		if (isAllMaxWeight(weights))
		{
			searchFirstEmpty(*from, *to);
			break;
		}

		int iMinFrom = minIndex(weights);
		*from = weights.at(iMinFrom).cell;
		int weightFrom = weights.at(iMinFrom).value;

		calculateDirectionWeights(directionWeights, *from);

		if (directionWeights.size() == 0)
		{
			weights.at(iMinFrom).value = MAX_WEIGHT;
			continue;
		}

		int iMinTo = minIndex(directionWeights);
		*to = directionWeights.at(iMinTo).cell;
		int weightTo = directionWeights.at(iMinTo).value;

		if (weightTo > weightFrom)
		{
			weights.at(iMinFrom).value = MAX_WEIGHT;
		}
		else
		{
			break;
		}
	}
}

int Ai::calculateWeight(int x, int y)
{
	return x * x + y * y;
}

void Ai::calculateWeights(vector<Weight>& weights)
{
	weights.clear();

	for (size_t i = 0; i < SIZE_X; i++)
	{
		for (size_t j = 0; j < SIZE_Y; j++)
		{
			CellValue cellValue = game->getGameField(i, j);

			if (cellValue == CellValue::WHITE)
			{
				Cell cell{ i, j, cellValue };
				Weight weight;
				weight.value = calculateWeight(0 - i, 0 - j);
				weight.cell = cell;

				weights.push_back(weight);
			}
		}
	}
}

void Ai::calculateDirectionWeights(vector<Weight>& directionWeights, const Cell& from)
{
	directionWeights.clear();
	array<Cell, NUM_DIRECTIONS> directionCells;
	array<int, NUM_DIRECTIONS> directions = { from.y + 1, from.y - 1, from.x + 1, from.x - 1 };

	for (size_t i = 0; i < NUM_DIRECTIONS / 2; i++)
	{
		int coord = directions.at(i);
		if (coord >= 0 && coord < SIZE_Y)
			directionCells.at(i) = { from.x, coord, game->getGameField(from.x, coord) };
		else
			directionCells.at(i) = { from.x, coord, CellValue::BLACK };
	}

	for (size_t i = NUM_DIRECTIONS / 2; i < NUM_DIRECTIONS; i++)
	{
		int coord = directions.at(i);
		if (coord >= 0 && coord < SIZE_X)
			directionCells.at(i) = { coord, from.y, game->getGameField(coord, from.y) };
		else
			directionCells.at(i) = { coord, from.y, CellValue::BLACK };
	}

	for (size_t i = 0; i < NUM_DIRECTIONS; i++)
	{
		Weight weight;
		if (directionCells[i].isEmpty())
		{
			weight.value = calculateWeight(directionCells[i].x, directionCells[i].y);
			weight.cell = directionCells[i];
			directionWeights.push_back(weight);
		}
	}
}

int Ai::minIndex(const vector<Weight>& weights)
{
	auto minIter = min_element(weights.begin(), weights.end(), [](Weight first, Weight second)
	{
		return first.value < second.value;
	});

	return std::distance(std::begin(weights), minIter);
}

bool Ai::isAllMaxWeight(const vector<Weight>& weights)
{
	for (auto& el : weights)
	{
		if (el.value != MAX_WEIGHT)
		{
			return false;
		}
	}
	return true;
}

void Ai::searchFirstEmpty(Cell& from, Cell& to)
{
	for (size_t i = 0; i < weights.size(); i++)
	{
		from = weights.at(i).cell;
		calculateDirectionWeights(directionWeights, from);
		for (size_t j = 0; j < directionWeights.size(); j++)
		{
			if (directionWeights.at(j).cell.isEmpty())
			{
				to = directionWeights.at(j).cell;
				return;
			}
		}
	}
}
