#pragma once

#define SIZE_X (8)
#define SIZE_Y (8)
#define SCALE (0.3)
#define SIZE_CELL (278*SCALE)
#define SIZE_BORDER (66*SCALE)
#define NUM_FIGURES (3)
#define SIZE_FINISH_WINDOW (200)

enum class CellValue
{
	EMPTY,
	BLACK,
	WHITE
};