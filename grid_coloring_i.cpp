#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (string &row : grid) {
    cin >> row;
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      int chVal = grid[r][c] - 'A';
      int nextChVal = (chVal + 1) % 4;
      while ((r > 0 && grid[r - 1][c] == char('A' + nextChVal)) ||
             (c > 0 && grid[r][c - 1] == char('A' + nextChVal))) {
        nextChVal = (nextChVal + 1) % 4;
      }
      grid[r][c] = char('A' + nextChVal);
      cout << grid[r][c];
    }
    cout << endl;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
