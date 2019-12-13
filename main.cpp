// Andrew Smith
//
// Graph Application Baseline
//
// Verificaiton for G-Sims GraphMat applications
//
// 121219

#include <list>
#include <vector>
#include <iostream>
#include <fstream>

#include "graph.h"

int main(int argc, char** argv) {
  Graph<uint64_t, uint64_t> graph;
  graph.import(argv[1], ~0x0, 1);
  return 0;
}
