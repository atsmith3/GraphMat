// Andrew Smith
// SSSP Baseline Application
// 121319

#ifndef SSSP_H
#define SSSP_H

#include <queue>
#include <list>
#include <iostream>

#include "graph.h"

typedef uint64_t vertex_t;
typedef uint64_t edge_t;

#define EDGE_INIT 1
#define VERTEX_INIT ~0

void initialize_sssp(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr);

void do_every_iteration_sssp(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr);

void run_sssp(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, std::queue<uint64_t>* next);

#endif // SSSP_H
