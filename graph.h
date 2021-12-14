#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <stack>
#include <set>

using namespace std;

class Graph {
    private:
        map<string, vector<pair<string, long double>>> routeGraph_;

    public:
        Graph();
        Graph(map<string, vector<pair<string, long double>>> &graph);
        void toString();
        
        void tarjansHelper(set<string>& visited, string start, vector<string> path, string airport,  set<vector<string>>& paths, int count, int len);
        set<vector<string>> tarjans(string startAirport, int len);
        vector<string> dfs(string start, string end);
        pair<vector<string>, long double> dijkstra(string start, string end);
        
};
