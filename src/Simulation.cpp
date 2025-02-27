#include "Simulation.h"


Simulation::Simulation()
	: rows(40), cols(40), windowWidth(900), windowHeight(900),
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
        window.clear(sf::Color(128, 128, 128));
        checkEvents();
        if (!mazeGenerator.isFinished())
        {
            mazeGenerator.generateStep();

        }
	        else renderer.render(mazeGenerator.getGrid(), rows, cols, cellSize);
        window.display();
    }
}