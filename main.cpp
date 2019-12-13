// Andrew Smith
//
// Graph Application Baseline
//
// Verificaiton for G-Sims GraphMat applications
//
// 121219

#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>

void import(std::string graph) {
  std::fstream g;
  g.open(graph, std::ios::in);
  std::string line;
  std::vector<std::string> tokens;
  uint64_t i = 0;
  //uint64_t num_edges, num_vertices;

  try {
    while(!g.eof()) {
      std::getline(g, line);
      std::cout << line << "\n";
      boost::algorithm::trim(line);
      boost::algorithm::split(tokens, line, boost::is_any_of(" "));

      if(i == 0) {
        if(line.find("%MatrixMarket") != std::string::npos) {
        }
        else {
          throw std::string("MatrixMarket file header invalid");
        }
      }
      i++;
    }
  }
  catch (std::string err) {
    std::cerr << "Error: " + err + "\n";
  }
}

int main(int argc, char** argv) {
  import(argv[1]);
  return 0;
}
