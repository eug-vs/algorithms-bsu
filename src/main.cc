#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define INPUT "in.txt"
#define OUTPUT "out.txt"


struct Node {
  long long value;
  int parentId;
  long long sum;
};

void proceed(int id, vector<Node>& nodes) {
  Node* node = &nodes[id];
  int parentId = node->parentId;
  long long sum = node->value + node->sum;
  if (sum < nodes[parentId].sum || !nodes[parentId].sum) {
    nodes[parentId].sum = sum;
    if (parentId != 0) proceed(parentId, nodes);
  }
}

int main() {
  ifstream fin;
  ofstream fout;

  fin.open(INPUT);
  fout.open(OUTPUT);

  int n;
  fin >> n;

  vector<Node> nodes(n);
  vector<int> leafIds;

  for (int i = 0; i < n; i++) {
    int id, childrenCount;
    fin >> id >> childrenCount;
    id--;
    if (childrenCount == 0) leafIds.push_back(id);
    for (int j = 0; j < childrenCount; j++) {
      int childId, value;
      fin >> childId >> value;
      childId--;

      nodes[childId].parentId = id;
      nodes[childId].value = value;
    }
  }

  sort(leafIds.begin(), leafIds.end(), [nodes](int a, int b) {
    return nodes[a].value < nodes[b].value;
  });

  int bestLeafId;
  long long bestSum = 0;
  for (int id : leafIds) {
    proceed(id, nodes);
    if (!bestSum || nodes[0].sum < bestSum) {
      bestLeafId = id;
      bestSum = nodes[0].sum;
    }
  }

  vector<int> path;
  int id = bestLeafId;
  while (id != 0) {
    path.push_back(id);
    id = nodes[id].parentId;
  }

  fout << bestSum << endl;
  for (int i = path.size(); i >= 0; i--) {
    fout << path[i] + 1 << " ";
  }
  fout << endl;

  fin.close();
  fout.close();
  return 0;
}

