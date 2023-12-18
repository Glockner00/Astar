
// main.c
#include "astar.h"
#include <SDL2/SDL.h>

int main() {
    // Initialize SDL and create a window
    initializeSDL();

    // Create a 2D array to represent the grid
    int grid[GRID_ROWS][GRID_COLS];

    // Step 1: Initialize the grid
    initializeGrid(grid);

    // Main loop
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Step 2: Render the grid
        renderGrid(grid);
    }

    // Cleanup SDL resources
    cleanupSDL();

    return 0;
}

