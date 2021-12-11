#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <utility>
#include <bits/stdc++.h>

#include "graph.h"
#include "data.h"



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
  }


  double dist = d.distance(airportLoc[source_airport], airportLoc[destination_airport]);


  routes = d.findRoutes(dist, source_airport, destination_airport);


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
  Graph graph(routes);
  graph.toString();

  return 0;
}
