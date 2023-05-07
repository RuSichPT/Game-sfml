#pragma once

constexpr int SIZE_X = (8);
constexpr int SIZE_Y = (8);
constexpr float SCALE = (0.3f);
constexpr float SIZE_CELL(278 * SCALE);
constexpr float SIZE_BORDER(66 * SCALE);
constexpr int NUM_FIGURES = (3);
constexpr int SIZE_FINISH_WINDOW = (200);

enum class CellValue
{
	EMPTY,
	BLACK,
	WHITE,
	NONE
};

enum class NextMove
{
	AI,
	PLAYER
};

struct Cell
{
	int x = -1;
	int y = -1;
	CellValue value = CellValue::NONE;

	void clear()
	{
		this->x = -1;
		this->y = -1;
		this->value = CellValue::NONE;
	};

	bool isInit()
	{
		return value != CellValue::NONE;
	}
	
	bool isEmpty()
	{
		return value != CellValue::EMPTY;
	}

	bool isBlack()
	{
		return value != CellValue::BLACK;
	}

	bool isWhite()
	{
		return value != CellValue::WHITE;
	}
};