# 🌀 Maze Generator

A real-time maze generation visualization built with C++ and SFML, implementing the iterative depth-first search (DFS) backtracking algorithm to create perfect mazes with animated step-by-step generation.

## 📸 Demo

https://github.com/user-attachments/assets/8d6d47c9-bdfe-45ed-a0ec-52d0e1e3f3b5

*Watch as the maze generates using iterative DFS backtracking*

## ✨ Features

- **🎯 Real-time Visualization**: Watch the maze generate step-by-step in real-time
- **🔄 Iterative DFS Backtracking Algorithm**: Uses stack-based depth-first search approach
- **🎨 Color-coded Generation**: 
  - **Black**: Visited cells (maze paths)
  - **Green**: Current cell being processed (top of stack)
  - **White**: Maze walls
  - **Gray**: Unvisited areas
- **⚡ High Performance**: Smooth animation at customizable frame rates
- **🎮 Interactive Controls**: Reset and regenerate mazes on command
- **📐 Configurable Grid**: Easily adjust maze dimensions

## 🛠️ Requirements

- **C++17** or later
- **CMake 3.28+** (for building)
- **Git** (for fetching dependencies)
- **Compatible Compiler**: GCC, Clang, or MSVC

> 🎉 **No manual SFML installation needed!** The project automatically downloads and builds SFML 3.0.0 using CMake's FetchContent.

## 🎯 How to Use

### 🎮 Controls

| Key | Action |
|-----|--------|
| **🔄 Space** | Reset and generate a new maze |
| **🚪 Escape** | Exit the application |

### 🎬 Running the Program

1. Launch the application
2. Watch as the maze generates automatically using iterative DFS
3. The **green cell** shows the current position in the algorithm (top of stack)
4. **Black cells** represent the maze paths that have been carved
5. **White lines** are the remaining walls
6. Press **Space** to generate a new random maze

## 🔧 Algorithm Explanation

### 🧠 Iterative Depth-First Search (DFS)

This implementation uses the **iterative DFS backtracking** algorithm:

1. **🎯 Start**: Begin at the top-left cell (0,0) and push to stack
2. **👁️ Mark**: Mark the current cell as visited
3. **🔍 Check**: Find all unvisited neighbors
4. **🎲 Choose**: Randomly select an unvisited neighbor
5. **🧱 Carve**: Remove the wall between current cell and chosen neighbor
6. **📚 Stack**: Push the neighbor onto the stack and make it current
7. **🔙 Backtrack**: If no unvisited neighbors, pop from stack
8. **🔁 Repeat**: Continue until stack is empty (all cells visited)

### 🎨 Visual Indicators

- **Green**: Current cell (top of the DFS stack)
- **Black**: Visited cells forming the maze paths
- **White**: Walls that separate cells
- **Gray**: Unvisited areas

## ⚙️ Configuration

### 📐 Customizing Maze Parameters

In `main.cpp`, you can modify the simulation parameters:

```cpp
// Simulation(rows, cols, fps, windowWidth, windowHeight)
Simulation simulation(20, 45, 200, 1800, 800);
```

- **rows**: Number of rows in the maze grid
- **cols**: Number of columns in the maze grid  
- **fps**: Frame rate (higher = faster generation)
- **windowWidth**: Window width in pixels
- **windowHeight**: Window height in pixels

### 🎯 Example Configurations

```cpp
// Small, slow maze
Simulation simulation(10, 15, 60, 900, 600);

// Large, fast maze
Simulation simulation(50, 80, 200, 2000, 1000);

// Square maze
Simulation simulation(30, 30, 150, 1200, 1200);
```

## 🏗️ Project Structure

```
Maze-Generator/
├── 📄 src/main.cpp          # Entry point
├── 🏛️ src/Simulation.h/cpp  # Main simulation controller
├── 🎨 src/Renderer.h/cpp    # SFML rendering engine
├── 🌀 src/MazeGenerator.h/cpp # Maze generation algorithm (iterative DFS)
├── 🔲 src/Cell.h            # Cell data structure
├── 📋 CMakeLists.txt        # Build configuration (auto-fetches SFML)
└── ⚙️ CMakeSettings.json    # Visual Studio CMake settings
```

### 🔍 Class Overview

- **🎯 `Simulation`**: Main application controller, handles events and coordinates components
- **🎨 `Renderer`**: Handles all SFML rendering and visualization
- **🌀 `MazeGenerator`**: Implements the iterative DFS backtracking algorithm
- **🔲 `Cell`**: Data structure representing each grid cell with walls and state

## 🔧 Technical Details

- **📊 Grid Representation**: 2D array of Cell objects
- **📚 Stack-based DFS**: Uses `std::stack` for iterative depth-first search
- **🎨 Real-time Rendering**: SFML rectangles for walls and cells
- **🎲 Random Generation**: Seeded random number generation for reproducible results
- **💾 Memory Management**: Proper dynamic allocation and cleanup

## 🚀 Performance

- **⚡ Optimized Rendering**: Efficient SFML drawing operations
- **🔄 Configurable Speed**: Adjustable FPS for different generation speeds
- **💾 Memory Efficient**: Minimal memory overhead per cell
- **📱 Scalable**: Handles various maze sizes smoothly

---

🎉 **Enjoy watching mazes come to life!** This project demonstrates the beauty of depth-first search algorithms through real-time visualization. Perfect for learning about maze generation, graph algorithms, and computer graphics programming.


