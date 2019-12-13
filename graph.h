// Andrew Smith
//
// Graph class
//
// 121219

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

template<class e_t>
class Edge {
public:
  e_t property;
  uint64_t dst;

  Edge(e_t init, uint64_t dst);
};

template<class v_t, class e_t>
class Vertex {
public:
  v_t property;
  std::list<Edge<e_t>> edges;
};

template<class v_t, class e_t>
class Graph {
public:
  std::vector<Vertex<v_t, e_t>> vertex;

  void import(std::string fname, v_t vertex_init, e_t edge_init);
  void print();
};

#include "graph.tcc"

#endif // GRAPH_H
