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

#include "graph.h"

typedef bool vertex_t;
typedef bool edge_t;

std::queue<uint64_t>* process;
std::queue<uint64_t>* apply;
Graph<vertex_t, edge_t> graph;

void run_bfs() {
  for(int iteration = 0; iteration < 1000 && !process->empty(); iteration++) {
    std::cout << "Iteration: " << iteration << " Process Queue Size: " << process->size() << " elements\n";
    while(!process->empty()) {
      // Dequeue:
      uint64_t src = process->front();
      process->pop();

      // Explore neighbors:
      for(auto it = graph.vertex[src].edges.begin(); it != graph.vertex[src].edges.end(); it++) {
        if(graph.vertex[it->dst].property == false) {
          // Mark explored and add to the apply queue;
          graph.vertex[it->dst].property = true;
          apply->push(it->dst);
        }
      }
    }
    std::swap(process, apply);
  }
}

int main(int argc, char** argv) {
  process = new std::queue<uint64_t>;
  apply = new std::queue<uint64_t>;

  graph.import(argv[1], false, true);
  //graph.print();

  // Initialize the problem
  graph.vertex[0].property = true;
  process->push(0);

  run_bfs();
  //graph.print();

  return 0;
}
