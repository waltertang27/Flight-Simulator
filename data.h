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
#include <string>


#include "graph.h"

using namespace std;

class Data {
    public:
        Data() {}
        Data(string airportLoc, string routesLoc) {
            airportDataLoc = airportLoc;
            routesDataLoc = routesLoc;
        }
        map<string, pair<long double, long double>> getAirportLocations();
        map<string, vector<pair<string, long double>>> buildGraph();
        long double toRadians(const long double degree);
        long double distance(pair<long double, long double> a1, pair<long double, long double> a2);
        bool validSource(string source, map<string, pair<long double, long double> > airportLoc);
        bool validDestination(string destination, map<string, pair<long double, long double> > airportLoc);
    private:
        string airportDataLoc = "airports.txt";
        string routesDataLoc = "routes.txt";


};