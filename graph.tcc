// Andrew Smith
//
// Graph class implementation
//
// 121219

#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/progress.hpp>
#include <cassert>
#include <stdexcept>

template<class e_t>
Edge<e_t>::Edge(e_t init, uint64_t dst) {
  this->property = init;
  this->dst = dst;
}

template<class v_t, class e_t>
void Graph<v_t, e_t>::import(std::string fname, v_t vertex_init, e_t edge_init) {
  std::fstream g;
  g.open(fname, std::ios::in);
  std::string line;
  std::vector<std::string> tokens;
  uint64_t i = 0;
  uint64_t progress = 0;
  uint64_t src, dst;
  uint64_t rows, columns, entries;
  std::string object, format, field, symmetry;

  while(!g.eof()) {
    std::getline(g, line);
    //std::cout << line << "\n";
    boost::algorithm::trim(line);
    boost::algorithm::split(tokens, line, boost::is_any_of(" "));

    if(line == "") {
      continue;
    }
    if(i == 0) {
      if(tokens[0].find("%MatrixMarket") != std::string::npos) {
        object = tokens[1];
        assert(object == "matrix");
        format = tokens[2];
        assert(format == "coordinate");
        field = tokens[3];
        symmetry = tokens[4];
        i++;
      }
      else {
        std::runtime_error("MatrixMarket file header invalid");
      }
    }
    else {
      if(tokens[0].find("%") == 0) {
        /* Do Nothing, line is a comment */
      }
      else {
        if(i == 1) {
          // Special Line: "<rows> <cols> <non-zeros>"
          rows = std::stoull(tokens[0]);
          columns = std::stoull(tokens[1]);
          entries = std::stoull(tokens[2]);
          assert(columns == rows);
          assert(entries < columns*rows);
          vertex.resize(rows);
        }
        else {
          src = std::stoull(tokens[0]) - 1;
          dst = std::stoull(tokens[1]) - 1;
          if(field == "pattern") {
            if(symmetry == "symmetric") {
              vertex[dst].property = vertex_init;
              vertex[dst].edges.push_back(Edge<e_t>(edge_init, src));
            }
            vertex[src].property = vertex_init;
            vertex[src].edges.push_back(Edge<e_t>(edge_init, dst));
            progress++;
          }
          if(field == "real") {
            
          }
          if(field == "integer") {
            
          }
        }
        i++;
      }
    }
    if((progress % 1000 == 0 || progress == entries) && entries != 0) {
      printf("\rImported: %3d%%", (int)((progress*100)/entries));
      fflush (stdout);
    }
  }

  std::cout << "\n";
  return;
}

template<class v_t, class e_t>
void Graph<v_t, e_t>::print() {
  for(auto v_it = vertex.begin(); v_it != vertex.end(); v_it++) {
    std::cout << "ID: " << v_it - vertex.begin() << " Property: " << v_it->property << " NumEdges: " << v_it->edges.size() << " \n  ";
    for(auto e_it = v_it->edges.begin(); e_it != v_it->edges.end(); e_it++) {
      std::cout << " (" << e_it->property << ", " << e_it->dst << "),";
    }
    std::cout << "\n";
  }
}
