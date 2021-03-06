#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define INPUT "tst.in"
#define OUTPUT "tst.out"


class Tree {
  private:
    class Node {
      public:
        int value;
        Node* left;
        Node* right;

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

    void remove(int x) {
      Node** current = &root;
      Node* child = nullptr;

      while((child = *current) && (child->value !=x)) {
        if (child->value > x) {
          if (child->left) current = &child->left;
          else return;
        } else {
          if (child->right) current = &child->right;
          else return;
        }
      }
      if (child->left && child->right) {
        Node* max = child->left;
        while(max->right) max = max->right;
        int max_key = max->value;
        remove(max_key);
        child->value = max_key;
        return;
      } else if (child->left && !child->right) {
        *current = child->left;
        child->left = nullptr;
      } else if (!child->left && child->right) {
        *current = child->right;
        child->right = nullptr;
      } else {
        *current = nullptr;
      }
      delete child;
    }

    int find_matches(vector<int> &matches, Node* node = nullptr) {
      if (!node) node = root;
      int height_left = -1, height_right = -1;
      if (node->left) height_left = find_matches(matches, node->left);
      if (node->right) height_right = find_matches(matches, node->right);
      if (abs(height_left - height_right) == 2) matches.push_back(node->value);
      return max(height_left, height_right) + 1;
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

  int key;
  Tree tree;
  while(fin >> key) {
    tree.insert(key);
  }

  vector<int> matches;
  tree.find_matches(matches);
  sort(matches.begin(), matches.end());
  if (matches.size() % 2) tree.remove(matches[matches.size() / 2]);
  fout << tree << endl;

  fin.close();
  fout.close();
  return 0;
}

