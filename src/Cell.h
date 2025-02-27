#pragma once


struct Cell
{
	int row, col;
	bool isVisited;
	bool walls[4]; // up, right, down, left
	bool hasNeighbors;
	bool isTop;

	Cell(int row = -1, int col = -1)
	{
		this->row = row;
		this->col = col;

		isVisited = false;
		hasNeighbors = true;
		isTop = false;

		for (int i = 0; i < 4; i++)
			walls[i] = true;
	}
};