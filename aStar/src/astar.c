#include "astar.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int start = 2;
int end = 3;

void initializeSDL() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
    // Handle error or exit the program
  }

  // Create a window and renderer
  window = SDL_CreateWindow("A-Star Visualization", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  if (window == NULL) {
    fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
    // Handle error or exit the program
  }

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
  grid[0][0] = start;
  grid[(GRID_ROWS - 1)][(GRID_COLS - 1)] = end;
}

void renderGridLines() {
  // Draw the grid lines on top of the cells.
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  for (int i = 0; i <= GRID_ROWS; ++i) {
    SDL_RenderDrawLine(renderer, 0, i * CELL_HEIGHT, WINDOW_WIDTH, i * CELL_HEIGHT);
  }
  for (int j = 0; j <= GRID_COLS; ++j) {
    SDL_RenderDrawLine(renderer, j * CELL_WIDTH, 0, j * CELL_WIDTH, WINDOW_HEIGHT);
  }
}

void renderGrid(const int grid[GRID_ROWS][GRID_COLS]) {
  // Clear the renderer
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_SetWindowSize(window, WINDOW_WIDTH, WINDOW_HEIGHT);
  SDL_RenderClear(renderer);

  // Draw the grid
  for (int i = 0; i < GRID_ROWS; ++i) {
    for (int j = 0; j < GRID_COLS; ++j) {
      // Draw a rectangle for each grid cell
      SDL_Rect rect = {j * (WINDOW_WIDTH / GRID_COLS), i * (WINDOW_HEIGHT / GRID_ROWS),
                       WINDOW_WIDTH / GRID_COLS, WINDOW_HEIGHT / GRID_ROWS};

      if (grid[i][j] == 1) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black for obstacles

      } else if (grid[i][j] == start) {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

      } else if (grid[i][j] == end) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

      } else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255,255); // white for open cells
      }

      SDL_RenderFillRect(renderer, &rect);
    }
  }
  renderGridLines();
  // Present the renderer
  SDL_RenderPresent(renderer);
}
