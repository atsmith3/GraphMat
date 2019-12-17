// Andrew Smith
// BFS Baseline Application
// 121319

#ifndef BFS_H
#define BFS_H

#include <queue>
#include <list>
#include <iostream>

#include "graph.h"

typedef bool vertex_t;
typedef bool edge_t;

#define EDGE_INIT true
#define VERTEX_INIT false

void initialize_bfs(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr);

void do_every_iteration_bfs(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr);

void run_bfs(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, std::queue<uint64_t>* next, uint64_t max_iter);

#endif // BFS_H
