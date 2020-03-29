#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define INPUT "input.txt"
#define OUTPUT "output.txt"

int main() {
  ifstream fin;
  ofstream fout;

  fin.open(INPUT);
  fout.open(OUTPUT);

  int n;
  fin >> n;
  vector<int> inputs(n);
  for (int i = 0; i < n; i++) fin >> inputs[i];

  bool answer = true;
  for (int i = 2; i < n + 1; i++) {
    if (inputs[i - 1] < inputs[i / 2 - 1]) {
      answer = false;
      break;
    }
  }
  
  fout << (answer? "Yes" : "No") << endl;

  fin.close();
  fout.close();
  return 0;
}

