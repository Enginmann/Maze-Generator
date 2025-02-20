#pragma once

#include "Cell.h"
#include <vector>

using namespace std;


class MazeGenerator
{
private:
	const int rows, cols;
	Cell ** grid;
	int visitedCellCount;
	int cellCount;
	vector<Cell> cellStack;

	bool chooseRandomDir(Cell & cell);
	void getNeighbors(Cell & cell, vector<Cell> & cells, vector<int> & walls);

public:

	MazeGenerator(int rows, int cols);
	~MazeGenerator();

	void generateStep();
	Cell ** getGrid();

	bool isFinished();
};