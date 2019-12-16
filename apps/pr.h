// Andrew Smith
// PR Baseline Application
// 121319

#ifndef PR_H
#define PR_H

#include <queue>
#include <list>
#include <iostream>

#include "graph.h"

typedef double edge_t;

typedef struct {
  double nodeDelta;
  double nodeResidual;
  double nodePageRank;
} vertex_t;

void initialize_pr(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, double alpha, double tolerance);

void do_every_iteration_pr(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr);

void run_pr(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, std::queue<uint64_t>* next, double alpha, double tolerance, uint64_t max_iter);

#endif // PR_H
