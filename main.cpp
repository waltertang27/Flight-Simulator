#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <utility>
#include <bits/stdc++.h>

#include "graph.cpp"
#include "data.cpp"



using namespace std;

//Add any includes here

 

int main() {

  map<string, string> airport_names;

  map<string, int> airport_id;

  map<string, vector<pair<string, long double> > > routes;

  map<string, pair<long double, long double> > airportLoc;

  Data d;

  airportLoc = d.readData("airports.txt");
  
  string s2;
  
  string source_airport, destination_airport;

  //prompts user to enter source airport
  cout << "Enter your source airport: \n";
  cin >> source_airport;
  int counter = 0;
  srand(time(NULL));
  //checks if user entered airport source is valid
  while(!d.validSource(source_airport, airportLoc)) {
    cout << "Source airport not found \n";
    cout << "Enter another: \n";
    counter++;
    //if too many failed attempts, recommend a random airport source
    if(counter > 2) {
      auto it = airportLoc.begin();
      int random = rand() % airportLoc.size();
      advance(it, random);
      cout << "Recommended random airport source: " << it->first << endl;
    }
    cin >> source_airport;
  }
  counter = 0;
  //prompts user to enter destination airport
  cout << "Enter your destination airport: \n";
  cin >> destination_airport;
  //checks if user entered airport destination is valid
  while(!d.validDestination(destination_airport, airportLoc)) {
    cout << "Destination airport not found \n";
    cout << "Enter another: \n";
    counter++;
    //if too many failed attempts, recommend a random airport destination
    if(counter > 2) {
      auto it = airportLoc.begin();
      int random = rand() % airportLoc.size();
      advance(it, random);
      cout << "Recommended random airport destination: " << it->first << endl;
    }
    cin >> destination_airport;
  }


  double dist = d.distance(airportLoc[source_airport], airportLoc[destination_airport]);


  routes = d.findRoutes(dist, source_airport, destination_airport);
/*
for(auto i = airportLoc.begin(); i != airportLoc.end(); ++i) {
    cout << i->first << ", ";
    
      cout << i->second.first << ", ";
      cout << i->second.second << endl;
    
  }
  */

  map<string, vector<string> > flights = d.getFlights("data.txt");
  /*
  for(auto i = routes.begin(); i != routes.end(); ++i) {
    cout << i->first << ", ";
    for(int j = 0; j < i->second.size(); j++) {
      cout << i->second[j].first << ", ";
      cout << i->second[j].second << endl;
    }
  }
  */


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

 
  Graph graph(routes, flights, airportLoc);
  graph.toString();
  vector<vector<double> > matrix = graph.makeAdjMatrix();
  graph.dijkstra(matrix, source_airport, destination_airport);

  return 0;
}
