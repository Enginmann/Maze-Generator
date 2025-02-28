#include "Renderer.h"


Renderer::Renderer(sf::RenderWindow * window, int windowWidth, int windowHeight, int fps)
    : windowWidth(windowWidth), windowHeight(windowHeight)
{
    this->window = window;
    window->create(sf::VideoMode({ (unsigned int)windowWidth, (unsigned int)windowHeight }), "Maze Generator");
    window->setFramerateLimit(fps);
}

void Renderer::render(Cell ** grid, int rows, int cols, float cellWidth, float cellHeight)
{
    renderGrid(grid, rows, cols, cellWidth, cellHeight);
}

void Renderer::renderGrid(Cell ** grid, int rows, int cols, float cellWidth, float cellHeight)
{
    float wallThickness = 1;

    sf::RectangleShape horizontalWall({ cellWidth, wallThickness });
    sf::RectangleShape verticalWall({ wallThickness, cellHeight });

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            sf::RectangleShape x({ cellWidth, cellHeight });
            sf::RectangleShape y({ cellWidth, cellHeight });
            x.setPosition({ col * cellWidth, row * cellHeight });
            y.setPosition({ col * cellWidth, row * cellHeight });
            x.setFillColor(sf::Color::Black);
            y.setFillColor(sf::Color::Green);

            if (grid[row][col].isVisited)
                window->draw(x);
            if (grid[row][col].isTop)
                window->draw(y);

            if (grid[row][col].walls[0])
            {
                horizontalWall.setPosition({ col * cellWidth, row * cellHeight });
                horizontalWall.setFillColor(sf::Color::White);
                window->draw(horizontalWall);
            }
            if (grid[row][col].walls[2])
            {
                horizontalWall.setPosition({ col * cellWidth, row * cellHeight + cellHeight - wallThickness });
                horizontalWall.setFillColor(sf::Color::White);
                window->draw(horizontalWall);
            }
            if (grid[row][col].walls[1])
            {
                verticalWall.setPosition({ col * cellWidth + cellWidth - wallThickness, row * cellHeight });
                verticalWall.setFillColor(sf::Color::White);
                window->draw(verticalWall);
            }
            if (grid[row][col].walls[3])
            {
                verticalWall.setPosition({ col * cellWidth, row * cellHeight });
                verticalWall.setFillColor(sf::Color::White);
                window->draw(verticalWall);
            }
        }
    }
}