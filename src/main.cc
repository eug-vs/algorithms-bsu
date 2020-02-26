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

    friend ostream& operator<< (ostream& os, const Node& node) {
      os << node.value << endl;
      if (node.left) os << *node.left;
      if (node.right) os << *node.right;
      return os;
    }

    ~Node() {
      delete left;
      delete right;
    }
};


class Tree {
  private:
    Node* root;

  public:

    Tree() {
      root = nullptr;
    }

    void insert(int x) {
      if (root) {
        root->insert(x);
      } else {
        root = new Node(x);
      }
    }

    friend ostream& operator<< (ostream& os, const Tree& tree) {
      os << *tree.root;
      return os;
    }

    ~Tree() {
      delete root;
    }
};


int main() {
  ifstream fin;
  ofstream fout;

  fin.open(INPUT);
  fout.open(OUTPUT);

  int target;
  int key;

  fin >> target;
  Tree tree;
  while(fin >> key) {
    tree.insert(key);
  }

  cout << tree;

  fout.close();
  fin.close();
  return 0;
}

