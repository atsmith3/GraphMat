// Andrew Smith
// PR Baseline Application
// 121319

#include "pr.h"

std::ostream& operator<<(std::ostream& os, const vertex_t& obj) {
  os << obj.pageRank;
  return os;
}

void initialize_pr(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, double alpha, double tolerance) {
  for(uint64_t i = 0; i < graph.vertex.size(); i++) {
    graph.vertex[i].property.delta = 0.0;
    graph.vertex[i].property.residual = (1-alpha);
    graph.vertex[i].property.pageRank = 0.0;
    curr->push(i);
  }
}

void do_every_iteration_pr(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr) {
  /* Do Nothing */
}

void run_pr(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, std::queue<uint64_t>* next, double alpha, double tolerance, uint64_t max_iter) {
  std::list<uint64_t>* residual = new std::list<uint64_t>;
  bool changed = true;

  for(uint64_t iteration = 0; iteration < max_iter && changed; iteration++) {
    std::cout << "Iteration: " << iteration << " Process Queue Size: " << curr->size() << " elements\n";
    changed = false;

    // Update Page Rank:
    while(!curr->empty()) {
      // Dequeue:
      uint64_t src = curr->front();
      curr->pop();

      graph.vertex[src].property.delta = 0;
      if(graph.vertex[src].property.residual > tolerance) {
        double oldResidual = graph.vertex[src].property.residual;
        graph.vertex[src].property.pageRank += oldResidual;
        graph.vertex[src].property.residual = 0.0;
        double outDegree = (double)graph.vertex[src].edges.size();
        if(outDegree > 0) {
          graph.vertex[src].property.delta = oldResidual*alpha/outDegree;
          changed = true;
        }
      }
      next->push(src);
    }
    // Calculate Residual
    while(!next->empty()) {
      uint64_t src = next->front();
      next->pop();

      double sum = 0.0;
      uint64_t neighbor = 0;
      for(auto it = graph.vertex[src].in_edges.begin(); it != graph.vertex[src].in_edges.end(); it++) {
        neighbor = it->src;
        if(graph.vertex[neighbor].property.delta > 0.0 && neighbor != src) {
          sum += graph.vertex[neighbor].property.delta;
        }
      }
      if(sum > 0.0) {
        graph.vertex[src].property.residual = sum;
      }
      curr->push(src);
    }
    do_every_iteration_pr(graph, curr);
  }

  delete residual;
}
