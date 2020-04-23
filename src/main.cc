#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "route.h"
using namespace std;

#define INPUT "input.txt"

Route getRouteFromString(string s) {
  Route route; istringstream sin(s);
  sin >> route.id >> route.driver;
  sin >> route.bus.first >> route.bus.second;
  return route;
}

int main() {
  ifstream fin;
  fin.open(INPUT);

  vector<Route> routes;
  map<int, Route> routesMap;

  string line;
  while (getline(fin, line)) {
    routes.push_back(getRouteFromString(line));
  }

  sort(routes.begin(), routes.end(), [](Route a, Route b) {
    if (a.bus.first == b.bus.first) {
      return a.id < b.id;
    } else return a.bus.first < b.bus.first;
  });

  for (auto route : routes) {
    cout << route.id << " " << route.driver << endl;
    routesMap.insert(pair<int, Route>(route.bus.first, route));
  }


  int id;
  cout << "Enter id: ";
  cin >> id;

  for_each(routes.begin(), routes.end(), [id](Route route) {
    if (route.id == id) {
      cout << route.bus.second << " #" << route.bus.first << endl;
    };
  });


  string bus;
  cout << "Enter bus: ";
  cin >> bus;

  for_each(routes.begin(), routes.end(), [bus](Route route) {
    if (route.bus.second == bus) {
      cout << route.driver << endl;
    };
  });

  fin.close();
  return 0;
}

