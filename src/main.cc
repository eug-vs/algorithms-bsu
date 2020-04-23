#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "route.h"
using namespace std;

#define INPUT "input.txt"

Route getRouteFromString(string s) {
  Route route;
  istringstream sin(s);
  sin >> route.id >> route.driver;
  sin >> route.bus.first >> route.bus.second;
  return route;
}

int main() {
  ifstream fin;
  fin.open(INPUT);

  vector<Route> routes;

  string line;
  while (getline(fin, line)) {
    routes.push_back(getRouteFromString(line));
  }

  for (auto r : routes) {
    cout << r.id << " " << r.driver << endl;
  }

  // TODO: sort here

  map<int, Route> routesMap;


  fin.close();
  return 0;
}

