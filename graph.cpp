#include "graph.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

// TODO need to create a test bench that use edge weights
// Graph::Graph() {
//     vector<string> SFO_connecting = {"LAX", "CMI", "JFK"};
//     vector<string> LAX_connecting = {"SFO", "MDW"};
//     vector<string> CMI_connecting = {"SFO", "MDW", "ORD"};
//     vector<string> ORD_connecting = {"CMI"};
//     vector<string> MDW_connecting = {"CMI", "JFK", "LAX"};
//     vector<string> JFK_connecting = {"SFO", "MDW"};

//     routeGraph_["SFO"] = SFO_connecting;
//     routeGraph_["LAX"] = LAX_connecting;
//     routeGraph_["CMI"] = CMI_connecting;
//     routeGraph_["ORD"] = ORD_connecting;
//     routeGraph_["MDW"] = MDW_connecting;
//     routeGraph_["JFK"] = JFK_connecting;
// }

Graph::Graph(map<string, vector<pair<string, long double>>> &graph) {
    routeGraph_ = graph;
}

void Graph::toString() {
    for(auto it = routeGraph_.cbegin(); it != routeGraph_.cend(); ++it)
    {
        std::cout << it->first << ": ";
        for (auto s : it->second) {
            std::cout << "(" << s.first << ", " << s.second << ")" << ", ";
        }

        std::cout << "\n";
        
    }
}

// need to refactor to work with weights
void Graph::dfs(string start) {
    stack<string> st;
    set<string> visited;

    st.push(start);
 
    while (!st.empty())
    {
        start = st.top();
        st.pop();
 
        if ((visited.find(start) != visited.end())) {
            continue;
        }
 
        visited.insert(start);
        cout << start << " ";
 
        for (auto neighbor : routeGraph_[start]) {
            if ((visited.find(neighbor.first) == visited.end())) {
                st.push(neighbor.first);
            }
        }
    }
}

void Graph::dijkstra(map<string, vector<string, string> > routeGraph, string start) {

}

/*

st = [SFO]

SFO
SFO


*/

