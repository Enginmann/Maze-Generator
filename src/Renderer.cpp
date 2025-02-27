#include "Renderer.h"


Renderer::Renderer(sf::RenderWindow * window, int windowWidth, int windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight)
{
    this->window = window;
    window->create(sf::VideoMode({ (unsigned int)windowWidth, (unsigned int)windowHeight }), "Maze Generator");
    window->setFramerateLimit(200);
}

void Renderer::render(Cell ** grid, int rows, int cols, float cellSize)
{
    renderGrid(grid, rows, cols, cellSize);
}

void Renderer::renderGrid(Cell ** grid, int rows, int cols, float cellSize)
{
    float wallThickness = 2;

    sf::RectangleShape horizontalWall({ cellSize, wallThickness });
    sf::RectangleShape verticalWall({ wallThickness, cellSize });

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            sf::RectangleShape x({ cellSize, cellSize });
            sf::RectangleShape y({ cellSize, cellSize });
            x.setPosition({ col * cellSize, row * cellSize });
            y.setPosition({ col * cellSize, row * cellSize });
            x.setFillColor(sf::Color::Black);
            y.setFillColor(sf::Color::Green);

            if (grid[row][col].isVisited)
                window->draw(x);
            if (grid[row][col].isTop)
                window->draw(y);

            if (grid[row][col].walls[0])
            {
                horizontalWall.setPosition({ col * cellSize, row * cellSize });
                horizontalWall.setFillColor(sf::Color::White);
                window->draw(horizontalWall);
            }
            if (grid[row][col].walls[2])
            {
                horizontalWall.setPosition({ col * cellSize, row * cellSize + cellSize - wallThickness });
                horizontalWall.setFillColor(sf::Color::White);
                window->draw(horizontalWall);
            }
            if (grid[row][col].walls[1])
            {
                verticalWall.setPosition({ col * cellSize + cellSize - wallThickness, row * cellSize });
                verticalWall.setFillColor(sf::Color::White);
                window->draw(verticalWall);
            }
            if (grid[row][col].walls[3])
            {
                verticalWall.setPosition({ col * cellSize, row * cellSize });
                verticalWall.setFillColor(sf::Color::White);
                window->draw(verticalWall);
            }
        }
    }
}