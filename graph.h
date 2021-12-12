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
#include <bits/stdc++.h>

using namespace std;




class Graph {
    private:
        map<string, vector<pair<string, long double>>> routeGraph_;
        map<string, vector<string> > flights;
        map<string, pair<long double, long double> > airportLoc;

    public:
        // Initialize the matrix to zero
        Graph();

        Graph(map<string, vector<pair<string, long double>>> &graph);

        Graph(map<string, vector<pair<string, long double>>> &graph, map<string, vector<string> > &flights, map<string, pair<long double, long double> > airportLoc);

        // Print the martix
        void toString();

        void dijkstra(vector<vector<double> > list, string source, string destination);

        long double toRadians(const long double degree);

        long double findDistance(pair<long double, long double> a1, pair<long double, long double> a2);

        vector<vector<double> > makeAdjMatrix();

        // struct Vertex {
        //     Vertex(string _key, vector<string> _neighbors): key(_key)), neighbors(_neighbors) { }
        //     string key;
        //     vector<string> neighbors;
        // };
        void dfs(string start);
        vector<string> dijkstra(map<string, vector<pair<string, long double> > > routeGraph, string source, string destination);
        int minDist(int size, vector<double> dist, vector<bool> visit);
        void printPath(int path[], int i, vector<string> airports);
        // class Iterator : iterator<forward_iterator_tag, string> {
        //     private:
        //         string val;
        //         stack<string> st;
        //         set<string> visited;
        //         map<string, vector<pair<string, long double>>> graph;

        //     public:
        //         Iterator() {};
        //         Iterator(string start, map<string, vector<pair<string, long double>>> graph_)
        //         {
        //             val = start;
        //             st.push(val);
        //             graph = graph_;
        //             if (!st.empty())
        //             {
        //                 string s = st.top();
        //                 st.pop();
                      
        //                 if ((visited.find(s) == visited.end()))
        //                 {
        //                     visited.insert(s);

        //                 for (auto s : graph[val]) {
        //                     if ((visited.find(s.first) == visited.end())) {
        //                         st.push(s.first);
        //                     }
        //                 }

                        
                                
        //             }
                    
        //         }
        //         Iterator(const Iterator &that);

        //         Iterator &operator=(const Iterator &that)
        //         {
        //             val = that.val;
        //         }

        //         Iterator &operator++()
        //         {  
        //             cout << val << "\n";
        //             if (!st.empty())
        //             {
        //                 val = st.top();
        //                 st.pop();
                      
        //                 if ((visited.find(val) == visited.end()))
        //                 {
        //                     visited.insert(val);
        //                 }

        //                 for (auto s : graph[val])
        //                     if ((visited.find(s.first) == visited.end()))
        //                         st.push(s.first);
        //             }

                    
        //         }
                

        //         string operator*() { return val; };

        //         bool operator==(const Iterator &that) const { return val == that.val; }
        //         bool operator!=(const Iterator &that) const { return !st.empty() && val != that.val; }

        // };

        // Iterator begin() { 
        //     Iterator it("SFO", routeGraph_);
        //     return it; 
        // }
        // Iterator end()   { return Iterator(); }


};
