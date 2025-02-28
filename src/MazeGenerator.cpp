#include "MazeGenerator.h"

#include <ctime>
#include <random>
#include <iostream>
#include <vector>

using namespace std;


MazeGenerator::MazeGenerator(int rows, int cols)
	: rows(rows), cols(cols)
{
	srand(time(0));

	grid = new Cell * [rows];
	for (int row = 0; row < rows; row++)
	{
		grid[row] = new Cell[cols];
		for (int col = 0; col < cols; col++)
		{
			grid[row][col].row = row;
			grid[row][col].col = col;
		}
	}

	cellStack.push(&grid[0][0]);
	grid[0][0].isVisited = true;
	grid[0][0].isTop = true;
	visitedCells = 1;
}

MazeGenerator::~MazeGenerator()
{
	for (int row = 0; row < rows; row++)
		delete[] grid[row];
	delete[] grid;
}

bool MazeGenerator::isFinished()
{
	if (visitedCells == rows * cols)
		return true;
	return false;
}

void MazeGenerator::generateStep()
{
	/*
		start with the cell at the top of the stack
		if cell has no neighbors
			pop it from the stack
		repeat until u have a cell with a neighbor
		choose a cell next to it if it is not visited
		and repeat

	*/
	if (cellStack.empty())
	{
		cout << "Empty stack" << endl;
		return;
	}

	Cell * cell = cellStack.top();
	int row = cell->row;
	int col = cell->col;
	cell->isTop = true;
	
	///////////////////
	if (!cell->hasNeighbors)
	{
		cellStack.pop();
		cell->isTop = false;
		return;
	}
	///////////////////
	
	///////////////////
	vector<Cell *> cells;
	vector<int> walls;

	if (row > 0 && !grid[row - 1][col].isVisited)
	{
		cells.push_back(&grid[row - 1][col]);
		walls.push_back(0);
	}
	if (row <= rows - 2 && !grid[row + 1][col].isVisited)
	{
		cells.push_back(&grid[row + 1][col]);
		walls.push_back(2);
	}
	if (col > 0 && !grid[row][col - 1].isVisited)
	{
		cells.push_back(&grid[row][col - 1]);
		walls.push_back(3);
	}
	if (col <= cols - 2 && !grid[row][col + 1].isVisited)
	{
		cells.push_back(&grid[row][col + 1]);
		walls.push_back(1);
	}

	if (!cells.size())
	{
		cell->hasNeighbors = false;
		return;
	}
	///////////////////

	///////////////////
	int dir = rand() % cells.size();
	cellStack.push(cells[dir]);
	cells[dir]->isVisited = true;
	cells[dir]->isTop = true;
	cell->isTop = false;
	visitedCells++;
	///////////////////
	
	///////////////////
	cell->walls[walls[dir]] = false;///////////////

	if (walls[dir] == 0)
		cells[dir]->walls[2] = false;
	else if (walls[dir] == 1)
		cells[dir]->walls[3] = false;
	else if (walls[dir] == 2)
		cells[dir]->walls[0] = false;
	else if (walls[dir] == 3)
		cells[dir]->walls[1] = false;
	///////////////////
}



Cell ** MazeGenerator::getGrid()
{
	return grid;
}