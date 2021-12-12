#include "graph.h"
#include "data.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

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

Graph::Graph(map<string, vector<pair<string, long double>>> &graph, map<string, vector<string> > &f, map<string, pair<long double, long double> > loc) {
    routeGraph_ = graph;
    flights = f;
    airportLoc = loc;
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
/*
void Graph::bfs(string start, string end) {
    list<string> queue;

    bool visited[routeGraph_.size()];
    
    for(int i = 0; i < routeGraph_.size(); i++) {
        visited[i] = false;

    }
    while(!queue.empty()) {
        string s = queue.front();
        queue.pop_front();
        for(int i = 0; i < )
    }
}
*/

int Graph::minDist(int size, vector<double> dist, vector<bool> visit) {
    int min = INT_MAX, min_index;
    for(int i = 0; i < size; i++) {
        if(visit[i] == false && dist[i] <= min) {
            min = dist[i], min_index = i;
        }
    }
    return min_index;
}

long double Graph::toRadians(const long double degree) {
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

long double Graph::findDistance(pair<long double, long double> a1, pair<long double, long double> a2){
    long double lat1 = a1.first;
    long double long1 = a1.second;
    long double lat2 = a2.first;
    long double long2 = a2.second;
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
    long double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
    ans = 2 * asin(sqrt(ans));
    long double R = 6371;
    ans = ans * R;
    return ans;
}

vector<vector<double> > Graph::makeAdjMatrix() {
    vector<string> airports;
    for(auto i = routeGraph_.begin(); i != routeGraph_.end(); ++i) {
        airports.push_back(i->first);
    }
    vector<vector<double> > list;
    int row = 0;
    for(auto i = flights.begin(); i != flights.end(); ++i) {
        int counter = 0;
        list.push_back(vector<double>());
        for(auto j = flights.begin(); j != flights.end(); ++j) {
            //cout << j->first << endl;
            //cout << counter << endl;
            if(counter >= i->second.size()) {
                break;
            }
            //cout << i->second[counter] << endl;
            if(j->first == i->second[counter]) {
                //cout << "step 1";
                double dist = findDistance(airportLoc[i->first], airportLoc[i->second[counter]]);
                //cout << dist << endl;
                //cout << "step 2";
                list[row].push_back(dist);
                //cout << "step 3";
                counter++;
            }
            else {
                list[row].push_back(0);
                //cout << "oops";
            }
        }
        row++;
    }/*
    for(int i = 0; i < list.size(); i++) {
        for(int j = 0; j < list[0].size(); j++) {
            cout << list[i][j];
        }
    }
    */
   ofstream outfile;
   outfile.open("flights.txt");
     for(auto i = 0; i < list.size(); i++) {
         //cout << iter->first<<": ";
         //outfile << it->first << ": ";
         for(unsigned j = 0; j < list[0].size(); j++) {
           //cout << iter->second[j] << " ";
           outfile << list[i][j] << " ";
         }
         //cout << endl;
         outfile << endl;
     }
     outfile.close();
    
    return list;
}

void Graph::printPath(int path[], int i, vector<string> airports) {
    //int index = find(airports.begin(), airports.end(), airports[i]) - airports.begin();
    if(path[i] == -1 ) {
        //cout << "DONE";
        return;
    }
    //cout << airports[i] << endl;
    printPath(path, path[i], airports);
    cout << airports[i] << " -> ";
    cout << "DONE\n";
}

void Graph::dijkstra(vector<vector<double> > list, string source, string destination) {
    vector<double> dist;
    vector<bool> visit;
    int path[list.size()];
    for(int i = 0; i < list.size(); i++) {
        dist.push_back(INT_MAX);
        visit.push_back(false);
        path[0] = -1;
        //cout << dist[i] << endl;
    }
    vector<string> airports;
    for(auto i = flights.begin(); i != flights.end(); ++i) {
        airports.push_back(i->first);
        //cout << i->first << endl;
    }
    
    int src = find(airports.begin(), airports.end(), source) - airports.begin();
    dist[src] = 0;
    //cout << index << endl;
    for(int i = 0; i < list.size() - 1; i++) {
        int u = minDist(list.size(), dist, visit);
        //cout << u << endl;
        visit[u] = true;
        for(int j = 0; j < list.size(); j++) {
            if(!visit[j] && abs(list[u][j]) > 0.5 && dist[u] != INT_MAX && dist[u] + list[u][j] < dist[j] + 0.1) {
                path[j] = u;

                //cout << dist[u] << endl;
                dist[j] = dist[u] + list[u][j];
               // cout << dist[j] << endl;
            }
        }
    }

  //  for(int i = 1; i < list.size(); i++) {
        //cout << airports[dist[i]]
        //cout << path[i] << ", ";
  //  }

    int end = find(airports.begin(), airports.end(), destination) - airports.begin();
    ofstream outfile;
    //cout << end << endl;
    outfile.open("out.txt");
     for(auto iter = 0; iter < dist.size(); iter++) {
         //cout << iter->first<<": ";
         outfile << dist[iter] << endl;
 
     }
     outfile.close();
    if(dist[end] < 0.5) {
        cout << "No available path\n";
        return;
    }
    
    cout << "Minimum distance is: " << dist[end] << endl;
    cout << "Path: \n";
    
    cout << airports[src] << " -> ";
    printPath(path, end, airports);

    //return path;
}



/*
vector<string> Graph::dijkstra(string source, string destination) {
    //double distance = 
    //vector<int> distance;
    map<string, double> dist;
    map<string, bool> visited;

    for(auto i = routeGraph_.begin(); i != routeGraph_.end(); ++i) {
        dist[i->first] = INT_MAX;
    }
    for(auto i = routeGraph_.begin(); i != routeGraph_.end(); ++i) {
        visited[i->first] = i->second();
    }

    dist[source] = 0;
    for(auto i = routeGraph_.size(); i != routeGraph_.end(); i++) {
        string s = minDist(dist, visited);
        visited[s] = true;
        for(auto j = 0; j < routeGraph_[i->second].size(); j++) {
        //for(auto j = dist.begin(); j != dist.end(); ++j) {
            if(!visited[j->second] && dist[s] != INT_MAX && dist[s] + dist[s] - dist[j] < ) {

            }
        }
    }

    unordered_map<string, int> dist;
    vector<bool> set;
    for(int i = 0; i < routeGraph_.second.size(); i++) {
        distance.push_back(INT_MAX);
        set.push_back(false);
    }
    //dist[source] = 0;
    for(int i = 0; i < routeGraph_->second.size() - 1; i++) {
        int u = minDist(dist, set);
        set[u] = true;
        for(int j = 0; j < routeGraph_->second.size(); j++) {
            if(!set[j] && routeGraph[source][j]) {

            }
        }
    }

   
}*/


/*

st = [SFO]

SFO
SFO


*/

