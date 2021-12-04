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
        map<string, vector<string>> routeGraph_;

    public:
        // Initialize the matrix to zero
        Graph();

        Graph(map<string, vector<string>> &graph);

        // Print the martix
        void toString();

        // struct Vertex {
        //     Vertex(string _key, vector<string> _neighbors): key(_key)), neighbors(_neighbors) { }
        //     string key;
        //     vector<string> neighbors;
        // };
        void dfs(string start);

        
        class Iterator : iterator<forward_iterator_tag, string> {
            private:
                string val;
                stack<string> st;
                set<string> visited;
                map<string, vector<string>> graph;

            public:
                Iterator() {};
                Iterator(string start, map<string, vector<string>> graph_)
                {
                    val = start;
                    st.push(val);
                    graph = graph_;
                    if (!st.empty())
                    {
                        string s = st.top();
                        st.pop();
                      
                        if ((visited.find(s) == visited.end()))
                        {
                            visited.insert(s);

                            for (auto str : graph[s]) {
                                if ((visited.find(str) == visited.end())) {
                                    st.push(str);
                                }
                            }
                        }

                        
                                
                    }
                    
                }
                Iterator(const Iterator &that);

                Iterator &operator=(const Iterator &that)
                {
                    val = that.val;
                }

                Iterator &operator++()
                {  
                    
                    if (!st.empty())
                    {
                        val = st.top();
                        st.pop();
                      
                        if ((visited.find(val) == visited.end()))
                        {
                            visited.insert(val);
                        }

                        for (auto s : graph[val])
                            if ((visited.find(s) == visited.end()))
                                st.push(s);
                    }

                    
                }
                

                string operator*() { return val; };

                bool operator==(const Iterator &that) const { return val == that.val; }
                bool operator!=(const Iterator &that) const { return !st.empty() && val != that.val; }

        };

        Iterator begin() { 
            Iterator it("SFO", routeGraph_);
            return it; 
        }
        Iterator end()   { return Iterator(); }

};
