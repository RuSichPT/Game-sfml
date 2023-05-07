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
	WHITE
};

enum class NextMove
{
	AI,
	PLAYER
};

struct Cell
{
	int x = 0xFFFFFFFF;
	int y = 0xFFFFFFFF;
	CellValue value = CellValue::EMPTY;
};