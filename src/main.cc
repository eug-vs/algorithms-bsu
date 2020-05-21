#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define INPUT "in.txt"
#define OUTPUT "out.txt"

struct Node {
  long long value = 0;
  vector<int> childrenIds;
  int bestChildId = 0;
};

long long proceed(int id, vector<Node>& nodes) {
  // cout << "Proceed id=" << id + 1 << endl;
  Node* node = &nodes[id];
  long long sum = -1;
  for (int childId : node->childrenIds) {
    long long childSum = proceed(childId, nodes);
    if (sum < 0 || childSum < sum) {
      // cout << "Better childSum=" << childSum << " for id=" << id + 1 << " bestLeafId=" << childId + 1 << endl;
      sum = childSum;
      node->bestChildId = childId;
    }
  }
  return sum > 0 ? (node->value + sum) : node->value;
}

int main() {
  ifstream fin;
  ofstream fout;

  fin.open(INPUT);
  fout.open(OUTPUT);

  int n;
  fin >> n;

  vector<Node> nodes(n);

  for (int i = 0; i < n; i++) {
    int id, childrenCount;
    fin >> id >> childrenCount;
    id--;
    for (int j = 0; j < childrenCount; j++) {
      int childId, value;
      fin >> childId >> value;
      childId--;

      nodes[id].childrenIds.push_back(childId);
      nodes[childId].value = value;
    }
  }

  long long bestSum = proceed(0, nodes);
  fout << bestSum << endl;
  
  int walker = 0;
  while(nodes[walker].bestChildId) {
    fout << walker + 1 << " ";
    walker = nodes[walker].bestChildId;
  }
  fout << walker + 1 << endl;

  fin.close();
  fout.close();
  return 0;
}

