#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#define INPUT "input.txt"
#define OUTPUT "output.txt"


int leftmost(vector<int> v, int target) {
  int L = 0;
  int R = v.size();
  int i;
  while (L < R) {
    i = (int)((L+R)/2);
    if (v[i] < target) {
      L = i + 1;
    } else {
      R = i;
    }
  }
  return L;
}

int rightmost(vector<int> v, int target) {
  int L = 0;
  int R = v.size();
  int i;
  while (L < R) {
    i = (int)((L+R)/2);
    if (v[i] > target) {
      R = i;
    } else {
      L = i + 1;
    }
  }
  return R - 1;
}


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

  for (int query : queries){
    int l = leftmost(array, query);
    int r = rightmost(array, query) + 1;
    bool b = (array[l] == query);
    cout << b << " " << l << " " << r << endl;
  };

  fout.close();
  fin.close();
  return 0;
}

