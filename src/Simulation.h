#pragma once

#include "Renderer.h"
#include "MazeGenerator.h"

class Simulation
{
private:
	const int rows, cols;
	const int windowWidth, windowHeight;
	float cellSize;

	sf::RenderWindow window;
	
	Renderer renderer;
	MazeGenerator mazeGenerator;

public:
	Simulation();
	
	void run();

	void checkEvents();
};