#include "Simulation.h"


Simulation::Simulation(int rows, int cols, int fps, int windowWidth, int windowHeight)
	: rows(rows), cols(cols), windowWidth(windowWidth), windowHeight(windowHeight),
      renderer(&window, windowWidth, windowHeight, fps), mazeGenerator(rows, cols)
{
    cellWidth = windowWidth / cols;
    cellHeight = windowHeight / rows;
}

void Simulation::checkEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto * keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                window.close();
        }
    }
}

void Simulation::run()
{
    while (window.isOpen())
    {
        window.clear(sf::Color(128, 128, 128));
        checkEvents();
        if (!mazeGenerator.isFinished())
            mazeGenerator.generateStep();
	    renderer.render(mazeGenerator.getGrid(), rows, cols, cellWidth, cellHeight);
        window.display();
    }
}