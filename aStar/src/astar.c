#include "astar.h"
#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void initializeSDL() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        // Handle error or exit the program
    }

    // Create a window and renderer
    window = SDL_CreateWindow("A-Star Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (window == NULL) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        // Handle error or exit the program
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        // Handle error or exit the program
    }
}

void cleanupSDL() {
    // Cleanup SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void initializeGrid(int grid[GRID_ROWS][GRID_COLS]) {
    // Initialize the grid with default values 
    for (int i = 0; i < GRID_ROWS; ++i) {
        for (int j = 0; j < GRID_COLS; ++j) {
            grid[i][j] = 0;
        }
    } 
}

void renderGrid(const int grid[GRID_ROWS][GRID_COLS]) {
    // Clear the renderer
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Draw the grid
    for (int i = 0; i < GRID_ROWS; ++i) {
        for (int j = 0; j < GRID_COLS; ++j) {
            // Draw a rectangle for each grid cell
            SDL_Rect rect = { j * 40, i * 40, 40, 40 };

            if (grid[i][j] == 1) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black for obstacles
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Green for open cells
            }

            SDL_RenderFillRect(renderer, &rect);
        }
    }
    // Present the renderer
    SDL_RenderPresent(renderer);
}
