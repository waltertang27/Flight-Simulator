#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <string>
#include "graph.h"
#include <map>
#include <sstream>
//Add any includes here

int main() {

  map<string, string> airport_names;

  map<string, int> airport_id;

  map<string, vector<string> > routes;

  //vector<string> airlines;

  graph routes();
  

  ifstream infile("data.txt");
  if(!infile) {
    cout << "data file can not be opened" << endl;
    return 0;
  }


  

  //stringstream ss(str);
  string s;
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

    getline(stream, airline_id, 's');

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
  
  return 0;
}
