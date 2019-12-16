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
  uint64_t src;

  Edge(e_t init, uint64_t src, uint64_t dst);
};

template<class v_t, class e_t>
class Vertex {
public:
  v_t property;
  std::vector<Edge<e_t>> edges;
  std::vector<Edge<e_t>> in_edges;
};

template<class v_t, class e_t>
class Graph {
public:
  std::string graph_name;
  std::vector<Vertex<v_t, e_t>> vertex;

  void import(std::string fname);
  void serialize();
  void deserialize();
  void print();
};

#include "graph.tcc"

#endif // GRAPH_H
