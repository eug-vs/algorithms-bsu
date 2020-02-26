#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int leftmost(vector<int> v, int target) {
  int L = 0;
  int R = v.size();
  int i;
  while (L < R) {
    i = (int)((L + R) / 2);
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
    i = (int)((L + R) / 2);
    if (v[i] > target) {
      R = i;
    } else {
      L = i + 1;
    }
  }
  return R - 1;
}


int main() {
  int length;
  int queries_length;

  cin >> length;
  vector<int> array(length);
  for (int i = 0; i< length; i++) {
    cin >> array[i];
  }

  cin >> queries_length;
  vector<int> queries(queries_length);
  for (int i = 0; i< queries_length; i++) {
    cin >> queries[i];
  }

  for (int query : queries){
    int l = leftmost(array, query);
    int r = rightmost(array, query) + 1;
    bool b = (array[l] == query);
    cout << b << " " << l << " " << r << endl;
  };

  return 0;
}

