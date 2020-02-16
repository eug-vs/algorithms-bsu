#include <iostream>
#include <string>
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

    Node(string s) {
      left = nullptr;
      right = nullptr;
      value = stoi(s);
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

    void insert(string s) {
      insert(stoi(s));
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
  string buffer;

  fin.open(INPUT);
  fout.open(OUTPUT);

  getline(fin, buffer);
  Node root(buffer);
  while(getline(fin, buffer)) {
    root.insert(buffer);
  }

  fout << root;

  fout.close();
  fin.close();
  return 0;
}

