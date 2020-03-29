#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int leftmost(vector<int>& v, int target, int &firstfound) {
  int L = 0;
  int R = v.size();
  int i;
  while (L < R) {
    i = (int)((L + R) / 2);
    if (v[i] < target) {
      L = i + 1;
    } else  {
      R = i;
      if (!firstfound && v[i] == target) {
        firstfound = i;
      }
    }
  }
  return L;
}

int rightmost(vector<int>& v, int target, int start = 0) {
  int L = start;
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
  return R;
}


int main() {
  int length;
  int queries_length;

  cin >> length;
  vector<int> array(length);
  for (int i = 0; i < length; i++) {
    cin >> array[i];
  }

  cin >> queries_length;
  vector<int> queries(queries_length);
  for (int i = 0; i < queries_length; i++) {
    cin >> queries[i];
  }

  for (int query : queries){
    int firstfound = 0;
    int l = leftmost(array, query, firstfound);
    bool b = (array[l] == query);
    int r = b? rightmost(array, query, firstfound) : l;
    cout << b << " " << l << " " << r << endl;
  };

  return 0;
}

