#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "graph.cpp"
#include <map>
#include <sstream>

using namespace std;

//Add any includes here

int main() {

  map<string, string> airport_names;

  map<string, int> airport_id;

  map<string, vector<string> > routes;

	
  string s;
  ifstream infile("data.txt");
  if(!infile) {
    cout << "data file can not be opened" << endl;
    return 0;
  }


  while(getline(infile, s)) {
    string airline;;
    string airline_id;
    string source_airport;
    string source_airport_id;
    string destination_airport;
    string destination_airport_id;
    string codeshare;
    string stops;
    string equipment;

    istringstream stream(s);
    getline(stream, airline, ',');

    getline(stream, airline_id, ',');

    getline(stream, source_airport, ',');

    getline(stream, source_airport_id, ',');

    getline(stream, destination_airport, ',');

    getline(stream, destination_airport_id, ',');

    getline(stream, codeshare, ',');

    getline(stream, stops, ',');

    getline(stream, equipment, '\n');

    routes[source_airport].push_back(destination_airport);

  }



  
  infile.close();

  // //testing
/*
   ofstream outfile;
   outfile.open("test.txt");
     for(auto iter = routes.begin(); iter != routes.end(); ++iter) {
         cout << iter->first<<": ";
         outfile << iter->first << ": ";
         for(unsigned j = 0; j < iter->second.size(); j++) {
           cout << iter->second[j] << " ";
           outfile << iter->second[j] << " ";
         }
         cout << endl;
         outfile << endl;
     }
     outfile.close();
*/
    map<string, vector<string> > test;

    vector<string> SFO_connecting = {"LAX", "CMI", "JFK"};
    vector<string> LAX_connecting = {"SFO", "MDW"};
    vector<string> CMI_connecting = {"SFO", "MDW", "ORD"};
    vector<string> ORD_connecting = {"CMI"};
    vector<string> MDW_connecting = {"CMI", "JFK", "LAX"};

    test["SFO"] = SFO_connecting;
    test["LAX"] = LAX_connecting;
    test["CMI"] = CMI_connecting;
    test["ORD"] = ORD_connecting;
    test["MDW"] = MDW_connecting;
    
    /*
  Graph graph(test);
    // graph.toString();

  cout << "The vector elements are : \n";
  cout << " \n";
*/
  /*
  for (Graph::Iterator it = graph.begin(); it != graph.end(); ++it)
    cout << *it << ", ";
  cout << "\n";
  */
  Graph graph(routes);
  // graph.toString();
  graph.dfs("SFO");

  // cout << "The vector elements are : ";
  // cout << "\n";
  // for (Graph::Iterator it = graph.begin(); it != graph.end(); ++it)
  //   cout << *it << ", ";
  // cout << "\n";
  

  return 0;
}
