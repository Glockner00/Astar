//astar_visualization.h
#ifndef ASTAR_VISUALIZATION_H
#define ASTAR_VISUALIZATION_H

#define GRID_ROWS 40
#define GRID_COLS 40
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800
#define CELL_HEIGHT (WINDOW_HEIGHT / GRID_ROWS)
#define CELL_WIDTH (WINDOW_WIDTH / GRID_COLS)

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

#endif

