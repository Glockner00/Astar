#ifndef ASTAR_H
#define ASTAR_H

// Define the size of the grid
#define GRID_ROWS 5
#define GRID_COLS 5

// Structure to represent a node in the grid
typedef struct {
  int row;
  int col;
} GridNode;

// Function declarations

/**
 * @brief Initialize the grid with default values.
 *
 * @param grid The 2D array representing the grid.
 */
void initializeGrid(int grid[GRID_ROWS][GRID_COLS]);

/**
 * @brief Render the grid using SDL.
 *
 * @param grid The 2D array representing the grid.
 */
void renderGrid(const int grid[GRID_ROWS][GRID_COLS]);

/**
 * @brief Clean up SDL resources.
 */
void cleanupSDL();

/**
 * @brief Initialize SDL and create a window and renderer.
 */
void initializeSDL();

#endif // ASTAR_H
