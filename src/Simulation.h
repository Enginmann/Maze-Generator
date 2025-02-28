#pragma once

#include "Renderer.h"
#include "MazeGenerator.h"

class Simulation
{
private:
	const int rows, cols;
	const int windowWidth, windowHeight;
	float cellWidth, cellHeight;

	sf::RenderWindow window;
	
	Renderer renderer;
	MazeGenerator mazeGenerator;

public:
	Simulation(int rows, int cols, int fps, int windowWidth, int windowHeight);
	
	void run();

	void checkEvents();

	void reset();
};