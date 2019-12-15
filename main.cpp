// Andrew Smith
//
// Graph Application Baseline
//
// Verificaiton for G-Sims GraphMat applications
//
// 121219

#include <list>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>

#include "pr.h"
#include "graph.h"


std::queue<uint64_t>* curr;
std::queue<uint64_t>* next;
Graph<vertex_t, edge_t> graph;

int main(int argc, char** argv) {
  curr = new std::queue<uint64_t>;
  next = new std::queue<uint64_t>;

  graph.import(argv[1]);

  initialize_pr(graph, curr);

  run_pr(graph, curr, next);

  delete curr;
  delete next;

  return 0;
}
