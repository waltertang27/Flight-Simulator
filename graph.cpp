#include "graph.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

Graph::Graph() {
    vector<string> SFO_connecting = {"LAX", "CMI", "JFK"};
    vector<string> LAX_connecting = {"SFO", "MDW"};
    vector<string> CMI_connecting = {"SFO", "MDW", "ORD"};
    vector<string> ORD_connecting = {"CMI"};
    vector<string> MDW_connecting = {"CMI", "JFK", "LAX"};
    vector<string> JFK_connecting = {"SFO", "MDW"};

    routeGraph_["SFO"] = SFO_connecting;
    routeGraph_["LAX"] = LAX_connecting;
    routeGraph_["CMI"] = CMI_connecting;
    routeGraph_["ORD"] = ORD_connecting;
    routeGraph_["MDW"] = MDW_connecting;
    routeGraph_["JFK"] = JFK_connecting;
}

Graph::Graph(map<string, vector<string>> &graph) {
    routeGraph_ = graph;
}

void Graph::toString() {
    for(auto it = routeGraph_.cbegin(); it != routeGraph_.cend(); ++it)
    {
        std::cout << it->first << ": ";
        for (auto s : it->second) {
            std::cout << s << ", ";
        }

        std::cout << "\n";
        
    }
}

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
 
        for (auto str : routeGraph_[start]) {
            if ((visited.find(str) == visited.end())) {
                st.push(str);
            }
        }
    }
}

/*

st = [SFO]

SFO
SFO


*/

