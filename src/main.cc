#include <iostream>
#include <fstream>
using namespace std;

#define INPUT "input.txt"
#define OUTPUT "output.txt"


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
        Node* min = child->right;
        while(min->left) min = min->left;
        int min_key = min->value;
        remove(min_key);
        child->value = min_key;
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

  tree.remove(target);
  fout << tree;

  fout.close();
  fin.close();
  return 0;
}

