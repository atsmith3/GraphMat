// Andrew Smith
// BFS Baseline Application
// 121319

#include "bfs.h"

void initialize_bfs(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr) {
  for(auto it = graph.vertex.begin(); it != graph.vertex.end(); it++) {
    it->property = false;
  }
  graph.vertex[0].property = true;
  curr->push(0);
}

void do_every_iteration_bfs(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr) {
  /* Do Nothing */
}

void run_bfs(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, std::queue<uint64_t>* next, uint64_t max_iter) {
  for(uint64_t iteration = 0; iteration < max_iter && !curr->empty(); iteration++) {
    std::cout << "Iteration: " << iteration << " Process Queue Size: " << curr->size() << " elements\n";
    while(!curr->empty()) {
      // Dequeue:
      uint64_t src = curr->front();
      curr->pop();

      // Explore neighbors:
      for(auto it = graph.vertex[src].edges.begin(); it != graph.vertex[src].edges.end(); it++) {
        if(graph.vertex[it->dst].property == false) {
          // Mark explored and add to the next queue;
          graph.vertex[it->dst].property = true;
          next->push(it->dst);
        }
      }
    }
    std::swap(curr, next);
    do_every_iteration_bfs(graph, curr);
  }
}
