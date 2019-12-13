// Andrew Smith
// CC Baseline Application
// 121319

#include "cc.h"

uint64_t components = 0;

void initialize_cc(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr) {
  graph.vertex[0].property = components;
  curr->push(0);
}

void do_every_iteration_cc(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr) {
  if(curr->empty()) {
    components++;
    for(uint64_t i = 0; i < graph.vertex.size(); i++) {
      if(components < graph.vertex[i].property) {
        graph.vertex[i].property = components;
        curr->push(i);
        return;
      } 
    }
    std::cout << "Found " << components << " connected components\n";
  }
}

void run_cc(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, std::queue<uint64_t>* next) {
  for(int iteration = 0; !curr->empty(); iteration++) {
    std::cout << "Iteration: " << iteration << " Process Queue Size: " << curr->size() << " elements\n";
    while(!curr->empty()) {
      // Dequeue:
      uint64_t src = curr->front();
      curr->pop();

      // Explore neighbors:
      for(auto it = graph.vertex[src].edges.begin(); it != graph.vertex[src].edges.end(); it++) {
        uint64_t dist = graph.vertex[src].property;
        if(dist < graph.vertex[it->dst].property) {
          // Mark explored and add to the next queue;
          graph.vertex[it->dst].property = dist;
          next->push(it->dst);
        }
      }
    }
    std::swap(curr, next);
    do_every_iteration_cc(graph, curr);
  }
}

