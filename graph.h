// Andrew Smith
//
// Graph class implementation
//
// 121219

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

template<class v_t, class e_t>
class Graph<v_t, e_t> {
private:
  uint64_t numNodes;
  uint64_t numNeighbors;
  std::vector<uint64_t> node_ptr;
  std::vector<uint64_t> node_neighbors;


  std::vector<v_t> vertex_property;
  std::vector<e_t> edge_property;

public:
  Graph();
  ~Graph();

  // Init
  bool import();

  // Setters & Getters 
  v_t getVertexProperty(uint64_t v_id);
  void setVertexProperty(uint64_t v_id, uint64_t val);





};
