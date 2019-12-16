// Andrew Smith
// PR Baseline Application
// 121319

#include "pr.h"

void initialize_pr(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, double alpha, double tolerance) {
  for(uint64_t i = 0; i < graph.vertex.size(); i++) {
    graph.vertex[i].property.nodeDelta = 0.0;
    graph.vertex[i].property.nodeResidual = (1-alpha);
    graph.vertex[i].property.nodePageRank = 0.0;
    curr->push(i);
  }
}

void do_every_iteration_pr(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr) {
  /* Do Nothing */
}

void run_pr(Graph<vertex_t, edge_t>& graph, std::queue<uint64_t>* curr, std::queue<uint64_t>* next, double alpha, double tolerance, uint64_t max_iter) {
  std::list<uint64_t>* residual = new std::list<uint64_t>;

  for(int iteration = 0; !curr->empty(); iteration++) {
    std::cout << "Iteration: " << iteration << " Process Queue Size: " << curr->size() << " elements\n";
    // Update Page Rank:
    while(!curr->empty()) {
      // Dequeue:
      uint64_t src = curr->front();
      curr->pop();

      graph.vertex[src].property.nodeDelta = 0;
      if(graph.vertex[src].property.nodeResidual > tolerance) {
        double oldResidual = graph.vertex[src].property.nodeResidual;
        graph.vertex[src].property.nodePageRank += oldResidual;
        graph.vertex[src].property.nodeResidual = 0.0;
        double outDegree = (double)graph.vertex[src].edges.size();
        if(outDegree > 0) {
          graph.vertex[src].property.nodeDelta = oldResidual*alpha/outDegree;
        }
      }
      next->push(src);
    }
    // Calculate Residual
    while(!next->empty()) {
      uint64_t src = next->front();
      curr->pop();

      double sum = 0.0;
      uint64_t neighbor = 0;
      for(auto it = graph.vertex[src].in_edges.begin(); it != graph.vertex[src].in_edges.end(); it++) {
        neighbor = it->src;
        if(graph.vertex[neighbor].property.nodeDelta > 0.0 && neighbor != src) {
          sum += graph.vertex[neighbor].property.nodeDelta;
        }
      }
      if(sum > 0.0) {
        graph.vertex[neighbor].property.nodeDelta = sum;
      }
      curr->push(src);
    }
    do_every_iteration_pr(graph, curr);
  }

  delete residual;
}
