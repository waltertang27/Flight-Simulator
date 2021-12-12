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


#include "graph.h"

using namespace std;

class Data {
    public:
        Data() {}
        map<string, pair<long double, long double> > readData(std::string filename);
        map<string, vector<pair<string, long double> > > findRoutes(double distance, string source_airport, string destination_airport);
        long double toRadians(const long double degree);
        long double distance(pair<long double, long double> a1, pair<long double, long double> a2);
        bool validSource(string source, map<string, pair<long double, long double> > airportLoc);
        bool validDestination(string destination, map<string, pair<long double, long double> > airportLoc);
        map<string, vector<string> > getFlights(string filename);
    private:



};