#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <utility>

#include "graph.cpp"
#include "data.cpp"

using namespace std;

int main() {
  
  Data d;
  map<string, vector<pair<string, long double>>> routes = d.buildGraph();
  
  Graph graph(routes); // Use default constructor to run test suite i.e. Graph graph;
  graph.toString();

  // UNCOMMENT TO RUN/PRINT DIJKSTRA RESULT
  /*
  pair<vector<string>, long double> res = graph.dijkstra("MDW", "WLG");
  for (auto val : res.first) {
      cout << val << ", ";
  }
  cout << "(" << res.second << ")" << "\n";
  */
  
  // UNCOMMENT TO RUN DFS ITERATOR 
  // graph.dfs("SFO", "SMF"); // TODO: need to add start and end as listed in proposal


  // UNCOMMENT TO RUN/PRINT TARJANS ALGORITHM (TODO: region specific)
  /*
  set<vector<string>> res = graph.tarjans("SFO", 5);
  for (auto vec : res) {
    cout << "[";
    for (auto val : vec) {
      cout << val << ", ";
    }
    cout << "]" << "\n";
  }
  */

  return 0;
}
