#include "GameView.h"

GameView::GameView(Cell** gameField)
{
	this->gameField = gameField;
	initBackground();
	initRenderWindow();
	initFigures();
}

GameView::~GameView()
{
	for (size_t i = 0; i < NUM_FIGURES * NUM_FIGURES; i++)
	{
		delete figuresBlack[i];
		delete figuresWhite[i];
	}

	delete spriteBackground;
	delete background;
	delete window;
}

void GameView::drow()
{
	window->clear(Color::White);
	window->draw(*spriteBackground);

	int black = 0;
	int white = 0;
	for (size_t i = 0; i < SIZE_X; i++)
	{
		for (size_t j = 0; j < SIZE_Y; j++)
		{
			Cell cell = gameField[i][j];
			if (cell == Cell::BLACK)
			{
				figuresBlack[black]->setPosition(i, j);
				black++;
			}
			if (cell == Cell::WHITE)
			{
				figuresWhite[white]->setPosition(i, j);
				white++;
			}
		}
	}

	for (size_t i = 0; i < NUM_FIGURES * NUM_FIGURES; i++)
	{
		window->draw(*figuresBlack[i]->getSprite());
		window->draw(*figuresWhite[i]->getSprite());
	}
	// Отрисовка окна
	window->display();
}

void GameView::initBackground()
{
	background = new Texture();
	background->loadFromFile("..\\Images\\board.jpg");

	spriteBackground = new Sprite(*background);
	spriteBackground->setScale(SCALE, SCALE);
}

void GameView::initRenderWindow()
{
	Vector2u sizeField = background->getSize();
	sizeField.x = unsigned int(sizeField.x * SCALE);
	sizeField.y = unsigned int(sizeField.y * SCALE);
	window = new RenderWindow(VideoMode(sizeField.x, sizeField.y), "The Game!");
}

void GameView::initFigures()
{
	int black = 0;
	int white = 0;
	for (size_t i = 0; i < SIZE_X; i++)
	{
		for (size_t j = 0; j < SIZE_Y; j++)
		{
			Cell cell = gameField[i][j];
			if (cell == Cell::BLACK)
			{
				figuresBlack[black] = new Figure(FigureColor::BLACK, i, j);
				black++;
			}
			else if (cell == Cell::WHITE)
			{
				figuresWhite[white] = new Figure(FigureColor::WHITE, i, j);
				white++;
			}
		}
	}
}
