// astar.h
#ifndef ASTAR_H
#define ASTAR_H
#include "astar_visualization.h"

// Node structer.
typedef struct {
  int row;
  int col;
  int g_score; // The cost from the start node to the current node.
  int f_score; // The sum of g_score and the heuristic estimate to the goal.
  struct PriorityQueueNode* parent; // pointer to the parent node.
} PriorityQueueNode;

// PriorityQueue structure
typedef struct {
  int maxSize;
  int size;
  PriorityQueueNode *nodes;

} PriorityQueue;

// Function declations

#endif
