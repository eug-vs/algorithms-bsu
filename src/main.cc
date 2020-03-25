#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define INPUT "input.txt"
#define OUTPUT "output.txt"
#define DIVISOR 1000000007

int main() {
  ifstream fin;
  ofstream fout;

  fin.open(INPUT);
  fout.open(OUTPUT);

  long long n;
  fin >> n;

  vector<long long> results(n + 1);
  results[0] = 1;
  results[1] = 1;

  for (long long i = 2; i < results.size(); i++) {
    results[i] = (results[i - 1] + results[i - 2]) % DIVISOR;
  }
  fout << results[n];

  fin.close();
  fout.close();
  return 0;
}

