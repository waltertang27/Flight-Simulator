#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <string>
#include "graph.cpp"
//Add any includes here

int main() {

  // vector<string> countries;
  // vector<vector<int> > debt;


  // ifstream infile("data.txt");
  // if(!infile) {
  //   cout << "data file can not be opened" << endl;
  //   return 0;
  // }


  // string s = "";
  // int temp = 0;
  // while(getline(infile, s)) {
  //     cout << s << endl;
  //     while(infile >> temp) {
  //       cout << temp << endl;
  //     }
  // }
  // infile.close();

  Graph graph;
  graph.toString();

  cout << "The vector elements are : ";
  cout << "\n";
    for (Graph::Iterator it = graph.begin(); it != graph.end(); ++it)
        cout << *it << ", ";
    cout << "\n";
  return 0;
}
