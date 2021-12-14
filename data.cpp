#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <utility>
#include <math.h>
// #include <bits/stdc++.h>

#include "graph.h"
#include "data.h"

using namespace std;

/**
 * @brief retrivies all the airports and their lat/long coordinates
 * 
 *  @return a map that contains the name of the airport and its coordinates
 */
map<string, pair<long double, long double> > Data::getAirportLocations() {
    string s;
    map<string, pair<long double, long double> > airportLoc;
    
    ifstream infile(airportDataLoc);
    if(!infile) {
        cout << "Airport data file can not be opened" << endl;
        return airportLoc;
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
        int length = iata.length();
        iata = iata.substr(1, 3);
        airportLoc[iata] = p;
        }
    }
    infile.close();
    return airportLoc;
}
/**
 * @brief checks if the input source is a valid airport source found in data
 * 
 * @param source user entered airport name
 * @return true if valid source airport name
 * @return false if not valid source airport name
 */
bool Data::validSource(string source, map<string, pair<long double, long double> > airportLoc) {
    auto it = airportLoc.find(source);
    if(it != airportLoc.end()) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief checks if the input destination is a valid airport destination found in data
 * 
 * @param destination user entered airport name
 * @return true if valid destination airport name
 * @return false if not valid destination airport name
 */
bool Data::validDestination(string destination, map<string, pair<long double, long double> > airportLoc) {
    auto it = airportLoc.find(destination);
    if(it != airportLoc.end()) {
        return true;
    }
    else {
        return false;
    }
}
/**
 * @brief creates a map of airports and the distances between them
 * 
 * @return map of aiports and all the other airports that they are connected to.
 */
map<string, vector<pair<string, long double> > > Data::buildGraph() {
    map<string, vector<pair<string, long double>>> routes;
    map<string, pair<long double, long double>> airportLoc =  getAirportLocations(); 
    string s2;
    ifstream infile2(routesDataLoc);
    if(!infile2) {
        cout << "Data file can not be opened" << endl;
        return routes;
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

        double dist = distance(airportLoc[source_airport], airportLoc[destination_airport]);

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
    }

    infile2.close();
    return routes;
}
/**
 * @brief Converts the specified degree into radians
 * 
 * @param degree the degree to convert into radians
 * @return radians value
 */
long double Data::toRadians(const long double degree) {
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
/**
 * @brief Calculates the shortest distance between two airports based on coordinate values
 * 
 * @param a1 coordinate value of first airport
 * @param a2 coordinate value of second airport
 * @return the shortest distance between the two airports
 */
long double Data::distance(pair<long double, long double> a1, pair<long double, long double> a2){
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


