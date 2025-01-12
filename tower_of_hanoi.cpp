#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(int n, int A, int B, int C, vector<pair<int, int>> &moves) {
  if (n == 0) {
    return;
  }

  solve(n - 1, A, C, B, moves);

  moves.push_back({A, C});

  solve(n - 1, B, A, C, moves);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> moves;
  solve(n, 1, 2, 3, moves);

  cout << moves.size() << endl;
  for (auto [x, y] : moves) {
    cout << x << ' ' << y << endl;
  }

  return 0;
}
