#pragma once

#include "SFML/Graphics.hpp"
#include "Cell.h"

class Renderer
{
private:
	const float windowWidth, windowHeight;
	sf::RenderWindow * window;

	void renderGrid(Cell ** grid, int rows, int cols, float cellSize);

public:
	Renderer(sf::RenderWindow * window, int windowWidth, int windowHeight);

	void render(Cell ** grid, int rows, int cols, float cellSize);
};