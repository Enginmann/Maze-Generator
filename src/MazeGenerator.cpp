#include "MazeGenerator.h"

#include <ctime>
#include <random>
#include <iostream>


using namespace std;

MazeGenerator::MazeGenerator(int rows, int cols)
	: rows(rows), cols(cols)
{
	cellCount = rows * cols;
	visitedCellCount = 1;

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

	cellStack.push_back(grid[0][0]);
	grid[0][0].isVisited = true;
}

MazeGenerator::~MazeGenerator()
{
	for (int row = 0; row < rows; row++)
		delete[] grid[row];
	delete[] grid;
}

bool MazeGenerator::isFinished()
{
	if (visitedCellCount == cellCount)
		return true;
	return false;
}

void MazeGenerator::generateStep()
{
	if (isFinished() || !cellStack.size())
		return;

	chooseRandomDir(cellStack.back());
}

bool MazeGenerator::chooseRandomDir(Cell & cell)
{
	srand(time(0));

	vector<Cell> cells;
	vector<int> walls;

	getNeighbors(cell, cells, walls);

	cout << cellStack.size() << endl;

	if (!grid[cell.row][cell.col].hasNeighbors)
	{
		cell.hasNeighbors = false;
		cellStack.pop_back();
		return false;
	}

	int dir = rand() % cells.size();

	cellStack.push_back(grid[cells[dir].row][cells[dir].col]);
	grid[cell.row][cell.col].walls[walls[dir]] = false;///////////////
	grid[cells[dir].row][cells[dir].col].isVisited = true;
	visitedCellCount++;
	
	if (walls[dir] == 0)
		grid[cells[dir].row][cells[dir].col].walls[2] = false;
	else if (walls[dir] == 1)
		grid[cells[dir].row][cells[dir].col].walls[3] = false;
	else if (walls[dir] == 2)
		grid[cells[dir].row][cells[dir].col].walls[0] = false;
	else if (walls[dir] == 3)
		grid[cells[dir].row][cells[dir].col].walls[1] = false;

	return true;
}

void MazeGenerator::getNeighbors(Cell & cell, vector<Cell> & cells, vector<int> & walls)
{
	if (cell.row > 0 && !grid[cell.row - 1][cell.col].isVisited)
	{
		cells.push_back(grid[cell.row - 1][cell.col]);
		walls.push_back(0);
	}
	if (cell.row < rows - 2 && !grid[cell.row + 1][cell.col].isVisited)
	{
		cells.push_back(grid[cell.row + 1][cell.col]);
		walls.push_back(2);
	}
	if (cell.col > 0 && !grid[cell.row][cell.col - 1].isVisited)
	{
		cells.push_back(grid[cell.row][cell.col - 1]);
		walls.push_back(3);
	}
	if (cell.row < cols - 2 && !grid[cell.row][cell.col + 1].isVisited)
	{
		cells.push_back(grid[cell.row][cell.col + 1]);
		walls.push_back(1);
	}

	if (!cells.size())
		grid[cell.row][cell.col].hasNeighbors = false;
}

Cell ** MazeGenerator::getGrid()
{
	return grid;
}