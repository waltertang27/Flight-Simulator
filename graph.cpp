#include "graph.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <string>
#include <limits>
#include <queue>


using namespace std;

Graph::Graph() {
    vector<pair<string, long double>> SFO_connecting = {pair<string, long double>("LAX", 100), pair<string, long double>("CMI", 200), pair<string, long double>("JFK", 400)};
    vector<pair<string, long double>> LAX_connecting = {pair<string, long double>("SFO", 50), pair<string, long double>("MDW", 150)};
    vector<pair<string, long double>> CMI_connecting = {pair<string, long double>("SFO", 23), pair<string, long double>("MDW", 400), pair<string, long double>("ORD", 40000)};
    vector<pair<string, long double>> ORD_connecting = {pair<string, long double>("CMI", 600)};
    vector<pair<string, long double>> MDW_connecting = {pair<string, long double>("CMI", 30), pair<string, long double>("JFK", 100), pair<string, long double>("LAX", 669)};
    vector<pair<string, long double>> JFK_connecting = {pair<string, long double>("SFO", 100), pair<string, long double>("MDW", 200)};

    routeGraph_["SFO"] = SFO_connecting;
    routeGraph_["LAX"] = LAX_connecting;
    routeGraph_["CMI"] = CMI_connecting;
    routeGraph_["ORD"] = ORD_connecting;
    routeGraph_["MDW"] = MDW_connecting;
    routeGraph_["JFK"] = JFK_connecting;
}

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

vector<string> Graph::dfs(string start, string end) {
    stack<string> st;
    set<string> visited;
    vector<string> dfs_result;
    st.push(start);
 
    while (!st.empty())
    {
        start = st.top();
        st.pop();

        if ((visited.find(start) != visited.end())) {
            continue;
        }
 
        visited.insert(start);
        dfs_result.push_back(start);

        if (start == end) {
            return dfs_result;
        }

        for (auto neighbor : routeGraph_[start]) {
            if ((visited.find(neighbor.first) == visited.end())) {
                st.push(neighbor.first);
            }
        }
    }

    return dfs_result;
}

pair<vector<string>, long double> Graph::dijkstra(string start, string end) {
    map<string, pair<long double, string>> tracker;
    for(auto iter = routeGraph_.begin(); iter != routeGraph_.end(); ++iter)
    {
        string k =  iter->first;
        if (k == start) {
            tracker[k] = pair<long double, string>(0, "");
        } else {
            tracker[k] = pair<long double, string>(std::numeric_limits<long double>::max(), "");

        }
    }

    set<string> visited;
    queue<pair<string, long double>> q;
    q.push(pair<string, long double>(start, 0));
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        string name = p.first;
        long double dist  = p.second;

        if (name == end) {
            string curName = name;
            long double totalDist = tracker[name].first;
            vector<string> res = {name};
            while(tracker[curName].second != "") {
                auto val = tracker[curName];
                res.insert(res.begin(), val.second);
                curName = val.second;
            }
            return pair<vector<string>, long double>(res, totalDist);
        }

        visited.insert(name);
        auto neighbors = routeGraph_[name];
        for (auto neighbor : neighbors) {
            long double distance = neighbor.second;
            if ((visited.find(neighbor.first) != visited.end())) {
                continue;
            }

            long double  old_cost = tracker[neighbor.first].first;
            long double  new_cost = tracker[name].first + distance;
            if (new_cost < old_cost) {
                q.push(pair<string, long double>(neighbor.first, new_cost));
                tracker[neighbor.first] = pair<long double, string>(new_cost, name);
            }

        }

    }

    return pair<vector<string>, long double>();

}

void Graph::tarjansHelper(set<string>& visited, string start, vector<string> path, string airport,  set<vector<string>>& paths, int count, int len) {
    if (count == len - 1) {
        if (airport == start) {
            path.push_back(airport);
            paths.insert(path);
        }
        return;
    }

    if ((visited.find(airport) != visited.end())) {
        return;
    }

    visited.insert(airport);

    auto neighbors = routeGraph_[airport];
    path.push_back(airport);

    for (auto n : neighbors) {
        tarjansHelper(visited, start, path, n.first, paths, count + 1, len);
    }
    
}


set<vector<string>> Graph::tarjans(string startAirport, int len) {
    set<string> visited;
    set<vector<string>> paths;

    vector<string> curPath;
    tarjansHelper(visited,startAirport, curPath, startAirport, paths, 0, len);
    return paths;
}

