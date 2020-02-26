#include <iostream>
#include <fstream>
using namespace std;

#define INPUT "input.txt"
#define OUTPUT "output.txt"

class Node {
  private:
    Node* left;
    Node* right;

  public:
    int value;

    Node(int x) {
      left = nullptr;
      right = nullptr;
      value = x;
    }

    void insert(int x) {
      if (x < value) {
        if (left) left->insert(x);
        else left = new Node(x);
      } else if (x > value) {
        if (right) right->insert(x);
        else right = new Node(x);
      }
    }

    friend ostream& operator<< (ostream& fout, const Node& node) {
      fout << node.value << endl;
      if (node.left) fout << *node.left;
      if (node.right) fout << *node.right;
      return fout;
    }

    ~Node() {
      delete left;
      delete right;
    }
};


int main() {
  ifstream fin;
  ofstream fout;

  fin.open(INPUT);
  fout.open(OUTPUT);

  int target;
  int key;

  fin >> target >> key;
  Node root(key);
  while(fin >> key) {
    root.insert(key);
  }

  cout << root;

  fout.close();
  fin.close();
  return 0;
}

