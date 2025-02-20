#include "Renderer.h"


Renderer::Renderer(sf::RenderWindow * window, int windowWidth, int windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight)
{
    this->window = window;
    window->create(sf::VideoMode({ (unsigned int)windowWidth, (unsigned int)windowHeight }), "Maze Generator");
    window->setFramerateLimit(50);
}

void Renderer::render(Cell ** grid, int rows, int cols, float cellSize)
{
    //window->clear();

    renderGrid(grid, rows, cols, cellSize);

    //window->display();
}

void Renderer::renderGrid(Cell ** grid, int rows, int cols, float cellSize)
{
    float wallThickness = 7;

    sf::RectangleShape horizontalWall({cellSize, wallThickness});
    sf::RectangleShape verticalWall({wallThickness, cellSize});

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            /*sf::RectangleShape x({cellSize, cellSize});
            if (grid[row][col].isVisited)
                window->draw(x);*/

            if (grid[row][col].walls[0])
            {
                horizontalWall.setPosition({ col * cellSize, row * cellSize });
                horizontalWall.setFillColor(sf::Color::Blue);
                window->draw(horizontalWall);
            }
            if (grid[row][col].walls[2])
            {
                horizontalWall.setPosition({ col * cellSize, row * cellSize + cellSize });
                horizontalWall.setFillColor(sf::Color::Red);
                window->draw(horizontalWall);
            }
            if (grid[row][col].walls[1])
            {
                verticalWall.setPosition({ col * cellSize + cellSize, row * cellSize });
                window->draw(verticalWall);
            }
            if (grid[row][col].walls[3])
            {
                verticalWall.setPosition({ col * cellSize, row * cellSize + cellSize });
                window->draw(verticalWall);
            }
        }
    }
}