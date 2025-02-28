#pragma once

#include "Cell.h"
#include <stack>

using namespace std;


class MazeGenerator
{
private:
	const int rows, cols;
	Cell ** grid;
	stack<Cell *> cellStack;
	int visitedCells;

public:

	MazeGenerator(int rows, int cols);
	~MazeGenerator();

	void generateStep();

	Cell ** getGrid();

	bool isFinished();

	void reset();
};