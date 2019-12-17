// Andrew Smith
// SSSP Baseline Application
// 121319

#include "sssp.h"

void initialize_sssp(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr) {
  for(auto it = graph.vertex.begin(); it != graph.vertex.end(); it++) {
    it->property = ~0x0;
  }
  graph.vertex[0].property = 0;
  curr->push(0);
}

void do_every_iteration_sssp(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr) {
  /* Do Nothing */
}

void run_sssp(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, std::queue<uint64_t>* next, uint64_t max_iter) {
  for(uint64_t iteration = 0; iteration < max_iter && !curr->empty(); iteration++) {
    std::cout << "Iteration: " << iteration << " Process Queue Size: " << curr->size() << " elements\n";
    while(!curr->empty()) {
      // Dequeue:
      uint64_t src = curr->front();
      curr->pop();

      // Explore neighbors:
      for(auto it = graph.vertex[src].edges.begin(); it != graph.vertex[src].edges.end(); it++) {
        uint64_t dist = graph.vertex[src].property + it->property;
        if(dist < graph.vertex[it->dst].property) {
          // Mark explored and add to the next queue;
          graph.vertex[it->dst].property = dist;
          next->push(it->dst);
        }
      }
    }
    std::swap(curr, next);
    do_every_iteration_sssp(graph, curr);
  }
}

