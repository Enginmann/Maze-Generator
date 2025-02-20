#include "Simulation.h"


Simulation::Simulation()
	: rows(8), cols(8), windowWidth(800), windowHeight(800),
      renderer(&window, windowWidth, windowHeight), mazeGenerator(rows, cols)
{
    cellSize = windowWidth / cols;
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
        window.clear();
        checkEvents();
	    renderer.render(mazeGenerator.getGrid(), rows, cols, cellSize);
        mazeGenerator.generateStep();
        window.display();
    }
}