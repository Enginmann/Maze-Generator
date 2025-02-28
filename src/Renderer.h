#pragma once

#include "SFML/Graphics.hpp"
#include "Cell.h"

class Renderer
{
private:
	const float windowWidth, windowHeight;
	sf::RenderWindow * window;

	void renderGrid(Cell ** grid, int rows, int cols, float cellWidth, float cellHeight);

public:
	Renderer(sf::RenderWindow * window, int windowWidth, int windowHeight, int fps);

	void render(Cell ** grid, int rows, int cols, float cellWidth, float cellHeight);
};