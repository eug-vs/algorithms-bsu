#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define INPUT "in.txt"
#define OUTPUT "out.txt"

const int knight_moves[8][2] = {
  { 1, 2 }, { 2, 1 },
  { 1, -2 }, { 2, -1 },
  { -1, 2 }, { -2, 1 },
  { -1, -2 }, { -2, -1 },
};

void spread(int i, int j, int num, vector<vector<int>>& board) {
  if (board[i][j] == 0) {
    board[i][j] = num;
    for (auto move : knight_moves) {
      int i2 = i + move[0];
      int j2 = j + move[1];
      if (i2 >= 0 && i2 < board.size() && j2 >= 0 && j2 < board[0].size()) {
        spread(i2, j2, num, board);
      }
    }
  }
}

int main() {
  ifstream fin;
  ofstream fout;
  string buffer;

  fin.open(INPUT);
  fout.open(OUTPUT);

  int n, m;
  fin >> n >> m;
  vector<vector<int>> board(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int value;
      fin >> value;
      board[i].push_back(value);
    }
  }

  int knights_num = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0) {
        knights_num += 1;
        spread(i, j, knights_num, board);
      }
    }
  }

  fout << knights_num << endl;

  fout.close();
  fin.close();
  return 0;
}

