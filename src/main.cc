#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#define INPUT "input.txt"
#define OUTPUT "output.txt"


int main() {
  ifstream fin;
  ofstream fout;
  string buffer;

  fin.open(INPUT);
  fout.open(OUTPUT);

  int length;
  int queries_length;

  fin >> length;
  vector<int> array(length);
  for (int i = 0; i< length; i++) {
    fin >> array[i];
  }

  fin >> queries_length;
  vector<int> queries(queries_length);
  for (int i = 0; i< queries_length; i++) {
    fin >> queries[i];
  }

  fout.close();
  fin.close();
  return 0;
}

