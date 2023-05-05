#include "GameView.h"
#include "Game.h" 

GameView::GameView(Game* game)
{
	this->game = game;

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

	if (!game->isEnd())
	{
		window->draw(*spriteBackground);

		int black = 0;
		int white = 0;
		for (size_t i = 0; i < SIZE_X; i++)
		{
			for (size_t j = 0; j < SIZE_Y; j++)
			{
				CellValue cell = game->getGameField(i, j);
				if (cell == CellValue::BLACK)
				{
					figuresBlack[black]->setPosition(i, j);
					black++;
				}
				if (cell == CellValue::WHITE)
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
	}
	else
	{
		window->setSize(Vector2u(SIZE_FINISH_WINDOW, SIZE_FINISH_WINDOW));

		Font font;
		if (font.loadFromFile("..\\Fonts\\Times_New_Roman.ttf"))
		{
			String strWinner;
			if (game->getWinner() == FigureColor::WHITE)
				strWinner = "White is the winner";
			else
				strWinner = "Black is the winner";

			Text text(strWinner,font);
			text.setPosition(90, 200);
			text.setCharacterSize(70);
			text.setFillColor(sf::Color::Black);
			window->draw(text);
		}
		else
		{
			throw "Don't load font";
		}
	}

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
			CellValue cell = game->getGameField(i, j);
			if (cell == CellValue::BLACK)
			{
				figuresBlack[black] = new Figure(FigureColor::BLACK, i, j);
				black++;
			}
			else if (cell == CellValue::WHITE)
			{
				figuresWhite[white] = new Figure(FigureColor::WHITE, i, j);
				white++;
			}
		}
	}
}
