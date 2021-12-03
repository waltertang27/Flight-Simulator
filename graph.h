#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <iterator>
using namespace std;
#include <stack>
#include <set>



class Graph {
    private:
        unordered_map<string, vector<string>> routeGraph_;

    public:
        // Initialize the matrix to zero
        Graph();

        // Print the martix
        void toString();

        // struct Vertex {
        //     Vertex(string _key, vector<string> _neighbors): key(_key)), neighbors(_neighbors) { }
        //     string key;
        //     vector<string> neighbors;
        // };

        
        class Iterator : iterator<forward_iterator_tag, string> {
            private:
                string val;
                stack<string> st;
                set<string> visited;
                unordered_map<string, vector<string>> graph;

            public:
                Iterator();
                Iterator(string start, unordered_map<string, vector<string>> graph_)
                {
                    val = start;
                    st.push(val);
                    graph_ = graph;
                    std::cout << start << ", ";
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
                        // std::cout << key << ", ";

                        // Stack may contain same vertex twice. So
                        // we need to print the popped item only
                        // if it is not visited.
                        if ((visited.find(val) == visited.end()))
                        {
                            visited.insert(val);
                        }

                        // Get all adjacent vertices of the popped vertex s
                        // If a adjacent has not been visited, then push it
                        // to the stack.
                        for (auto s : graph[val]) {
                            std::cout << s << ", ";
                        }
                        for (auto s : graph[val])
                            if ((visited.find(s) == visited.end()))
                                st.push(s);
                    }
                }

                string operator*() { return val; };

                bool operator==(const Iterator &that) const { return val == that.val; }
                bool operator!=(const Iterator &that) const { return val != that.val || st.empty(); }

        };

        Iterator begin() { return Iterator("SFO", routeGraph_); }
        Iterator end()   { return Iterator("", routeGraph_); }

};
