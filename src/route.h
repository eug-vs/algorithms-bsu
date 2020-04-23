#include <string>

typedef std::pair<int, std::string> Bus;

typedef struct {
  int id;
  std::string driver;
  Bus bus;
} Route;

Route getRouteFromString(std::string);

