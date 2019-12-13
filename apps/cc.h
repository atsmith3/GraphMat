// Andrew Smith
// CC Baseline Application
// 121319

#ifndef CC_H
#define CC_H

#include <queue>
#include <list>
#include <iostream>

#include "graph.h"

typedef uint64_t vertex_t;
typedef uint64_t edge_t;

#define EDGE_INIT 1
#define VERTEX_INIT ~0

void initialize_cc(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr);

void do_every_iteration_cc(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr);

void run_cc(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, std::queue<uint64_t>* next);

#endif // CC_H
