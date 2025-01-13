#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N = 8;

vector<string> board;
vector<bool> col, diag1, diag2;

bool isValid(int r, int c) {
  if (r < 0 || r >= N || c < 0 || c >= N || board[r][c] != '.' || col[c] ||
      diag1[r + c] || diag2[N + r - c - 1]) {
    return false;
  }

  return true;
}

void solve(int r, int &result) {
  if (r == N) {
    ++result;
    return;
  }

  for (int c = 0; c < N; ++c) {
    if (isValid(r, c)) {
      col[c] = true;
      diag1[r + c] = true;
      diag2[N + r - c - 1] = true;
      board[r][c] = '#';

      solve(r + 1, result);

      board[r][c] = '.';
      col[c] = false;
      diag1[r + c] = false;
      diag2[N + r - c - 1] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  board.resize(N);
  col.assign(N, false);
  diag1.assign(N, false);
  diag2.assign(N, false);

  for (string &row : board) {
    cin >> row;
  }

  int result = 0;
  solve(0, result);

  cout << result << endl;

  return 0;
}
