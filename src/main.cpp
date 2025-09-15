#include "Simulation.h"


int main()
{
    /// rows, cols, fps, windowWidth, windowHeight
    Simulation simulation(20, 45, 200, 1800, 800);

    simulation.run();
}