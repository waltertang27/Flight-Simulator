#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <utility>
#include <math.h>
#include "../catch/catch.hpp"

#include "../graph.cpp"
#include "../data.cpp"

Data smallData("tests/data/airports_small.txt", "tests/data/routes_small.txt");
Data largeData("tests/data/airports.txt", "tests/data/routes.txt");

map<string, vector<pair<string, long double>>> smallGraph = smallData.buildGraph();
map<string, vector<pair<string, long double>>> largeGraph = largeData.buildGraph();

TEST_CASE("Test Map Generation - Small Dataset") {
  REQUIRE(smallGraph["GKA"][0].first == "MAG");
  REQUIRE(floor(smallGraph["GKA"][0].second) == floor(106.714));
  REQUIRE(smallGraph["LAX"][0].first == "SYD");
  REQUIRE(floor(smallGraph["LAX"][0].second) == floor(12061.1));
  REQUIRE(smallGraph["UAK"][0].first == "SFJ");
  REQUIRE(floor(smallGraph["UAK"][0].second) == floor(698.952));
}

TEST_CASE("Test Map Generation - Large Dataset") {
  REQUIRE(largeGraph["ZSA"][0].first == "PLS");
  REQUIRE(floor(largeGraph["ZSA"][0].second) == floor(343.942));
  REQUIRE(largeGraph["ZSA"][1].first == "FLL");
  REQUIRE(floor(largeGraph["ZSA"][1].second) == floor(609.282));

  REQUIRE(largeGraph["ZPB"][0].first == "MSA");
  REQUIRE(floor(largeGraph["ZPB"][0].second) == floor(57.5889));

  REQUIRE(largeGraph["ZAM"][0].first == "MNL");
  REQUIRE(floor(largeGraph["ZAM"][0].second) == floor(851.151));

  REQUIRE(largeGraph["ZAM"][1].first == "CEB");
  REQUIRE(floor(largeGraph["ZAM"][1].second) == floor(431.482));
}

TEST_CASE("Test DFS 1 - Small Dataset") {
  Graph graph(smallGraph);
  vector<string> res = graph.dfs("LAX", "SYD");

  REQUIRE(res[0] == "LAX");
  REQUIRE(res[1] == "SYD");
}

TEST_CASE("Test DFS 2 - Small Dataset") {
  Graph graph(smallGraph);
  vector<string> res = graph.dfs("GKA", "MAG");

  REQUIRE(res[0] == "GKA");
  REQUIRE(res[1] == "MAG");
}

TEST_CASE("Test DFS 1 - Large Dataset") {
  Graph graph(largeGraph);
  vector<string> res = graph.dfs("GKA", "LAX");

  REQUIRE(res[0] == "GKA");
  REQUIRE(res[1] == "POM");
  REQUIRE(res[2] == "LNV");
  REQUIRE(res[8] == "WWK");
  REQUIRE(res[res.size() - 2] == "MNL");
  REQUIRE(res[res.size() - 1] == "LAX");
}

TEST_CASE("Test Dijkstras 1 - Large Dataset") {
  Graph graph(largeGraph);
  pair<vector<string>, long double> res = graph.dijkstra("LAX", "SYD");
  vector<string> path = res.first;
  long double dist = res.second;

  REQUIRE(path[0] == "LAX");
  REQUIRE(path[1] == "SYD");

  REQUIRE(floor(dist) == floor(12061.1));
}

TEST_CASE("Test Dijkstras 2 - Large Dataset") {
  Graph graph(largeGraph);
  pair<vector<string>, long double> res = graph.dijkstra("MDW", "HNL");
  vector<string> path = res.first;
  long double dist = res.second;

  REQUIRE(path[0] == "MDW");
  REQUIRE(path[1] == "SMF");
  REQUIRE(path[2] == "HNL");
  REQUIRE(floor(dist) == floor(6833));
}


TEST_CASE("Test Tarjans 1 - Large Dataset") {
  Graph graph(largeGraph);
  set<vector<string>> res = graph.tarjans("LAX", 3);
  vector<string> sol1 = {"LAX", "YUM", "LAX"};
  vector<string> sol2 = {"LAX", "YVR", "LAX"};
 
  REQUIRE(res.find(sol1) != res.end());
  REQUIRE(res.find(sol2) != res.end());
}

TEST_CASE("Test Tarjans 2 - Large Dataset") {
  Graph graph(largeGraph);
  set<vector<string>> res = graph.tarjans("SFO", 5);
  vector<string> sol1 = {"SFO", "JFK", "YVR", "PSP", "SFO"};
  vector<string> sol2 = {"SFO", "JFK", "YVR", "PVG", "SFO"};
  
  REQUIRE(res.find(sol1) != res.end());
  REQUIRE(res.find(sol2) != res.end());
}





