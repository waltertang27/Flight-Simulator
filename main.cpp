#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "graph.cpp"
#include <map>
#include <sstream>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

//Add any includes here

long double toRadians(const long double degree)
{
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
 
long double distance(pair<long double, long double> a1, pair<long double, long double> a2)
{
    
    long double lat1 = a1.first;
    long double long1 = a1.second;
    long double lat2 = a2.first;
    long double long2 = a2.second;
    // cout << lat1 << " "  << long1 << "\n";
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);

    // cout << lat1 << " "  << long1 << "\n";

    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    long double R = 6371;
    
    ans = ans * R;
 
    return ans;
}

int main() {

  map<string, string> airport_names;

  map<string, int> airport_id;

  map<string, vector<pair<string, long double>>> routes;
  map<string, pair<long double, long double> > airportLoc;

  string s;
  ifstream infile("airports.txt");
  if(!infile) {
    cout << "airport data file can not be opened" << endl;
    return 0;
  }

  while(getline(infile, s)) {
    string airport_id;;
    string name;
    string city;
    string country;
    string iata;
    string icao;
    string latitude;
    string longitude;
    string altitude;
    string timezone;
    string dst;
    string tz_database_time;
    string zone;
    string type;
    string source;

    istringstream stream(s);
    getline(stream, airport_id, ',');

    getline(stream, name, ',');

    getline(stream, city, ',');

    getline(stream, country, ',');

    getline(stream, iata, ',');

    getline(stream, icao, ',');

    getline(stream, latitude, ',');

    long double lati = 0.0;
    long double longi = 0.0;
    try {
      lati = stold(latitude);
    } catch(const std::exception&) {
      getline(stream, latitude, ',');
    }
      
    


    getline(stream, longitude, ',');

    getline(stream, altitude, ',');

    getline(stream, timezone, '\n');
    getline(stream, dst, '\n');
    getline(stream, tz_database_time, '\n');
    getline(stream, zone, '\n');
    getline(stream, type, '\n');
    getline(stream, source, '\n');
    pair<long double, long double> p(stold(latitude), stold(longitude));

    
    if (iata.compare("\\N") != 0) {
      airportLoc[iata] = p;
      // cout << iata << p.first << " "  << p.second << "\n";
    }
    
  }

  infile.close();

  // for(auto it = airportLoc.cbegin(); it != airportLoc.cend(); ++it)
  //   {
  //       std::cout << it->first << ": ";
  //       std::cout << "(" << it->second.first << ", " << it->second.second << ")" << ", ";

  //       std::cout << "\n";
        
  //   }

  cout << airportLoc["ZTR"].first << airportLoc["ZTR"].second << "\n";
  
  string s2;
  ifstream infile2("data.txt");
  if(!infile2) {
    cout << "data file can not be opened" << endl;
    return 0;
  }


  while(getline(infile2, s2)) {
    string airline;;
    string airline_id;
    string source_airport;
    string source_airport_id;
    string destination_airport;
    string destination_airport_id;
    string codeshare;
    string stops;
    string equipment;

    istringstream stream(s2);
    getline(stream, airline, ',');

    getline(stream, airline_id, ',');

    getline(stream, source_airport, ',');

    getline(stream, source_airport_id, ',');

    getline(stream, destination_airport, ',');

    getline(stream, destination_airport_id, ',');

    getline(stream, codeshare, ',');

    getline(stream, stops, ',');

    getline(stream, equipment, '\n');

    // std::cout << airportLoc[source_airport].first << ", " << airportLoc[destination_airport].first << "\n";
    double dist = distance(airportLoc[source_airport], airportLoc[destination_airport]);
    // std::cout << routes[source_airport].size() << "\n";
    // vector<pair<string, double>> &neighbors = routes[source_airport];
    // for (auto s : routes[source_airport]) {
    //  std::cout << "(" << s.first << ", " << s.second << ")" << ", ";
    // }

    if (routes[source_airport].size() == 0) {
      routes[source_airport].push_back(pair<string, long double>(destination_airport, dist));
    } else {
      auto size = routes[source_airport].size();
      for(size_t i = 0; i < size; i++) {
        if (i < routes[source_airport].size() - 1) {
          if (dist >= routes[source_airport][i].second && dist < routes[source_airport][i + 1].second) {
              routes[source_airport].insert(routes[source_airport].begin() + i, pair<string, long double>(destination_airport, dist));
              break;
          }
        } else {
            routes[source_airport].push_back(pair<string, long double>(destination_airport, dist));
          
        }
      }
    }
    

    // routes[source_airport] = neighbors;

  }



  
  infile2.close();

  // //testing

  // ofstream outfile;
  // outfile.open("test.txt");
  //   for(auto iter = routes.begin(); iter != routes.end(); ++iter) {
  //       cout << iter->first<<": ";
  //       outfile << iter->first << ": ";
  //       for(unsigned j = 0; j < iter->second.size(); j++) {
  //         cout << iter->second[j] << " ";
  //         outfile << iter->second[j] << " ";
  //       }
  //       cout << endl;
  //       outfile << endl;
  //   }
  //   outfile.close();
    
  // Graph graph(routes);
  //   graph.toString();

  // cout << "The vector elements are : ";
  // cout << "\n";
  // for (Graph::Iterator it = graph.begin(); it != graph.end(); ++it)
  //   cout << *it << ", ";
  // cout << "\n";
  
  return 0;
}
