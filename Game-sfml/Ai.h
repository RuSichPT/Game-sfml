#pragma once
#include "Config.h"
#include <vector>

class Game;

using namespace std;

struct Weight
{
	int value;
	Cell cell;
};

class Ai
{
public:
	Ai(Game* game);
	void act();
private:
	Game* game;
	vector<Weight> weights;
	vector<Weight> directionWeights;

	void selectCell(Cell* from, Cell* to);
	void calculateWeights(vector<Weight>& weights);
	void calculateDirectionWeights(vector<Weight>& directionWeights, const Cell& from);
	int calculateWeight(int x, int y);
	int minIndex(const vector<Weight>& weights);
	bool isAllMaxWeight(const vector<Weight>& weights);
	void searchFirstEmpty(Cell& from, Cell& to);
};

