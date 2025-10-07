#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));
  vector<set<int>> cols(n);
  for (int i = 0; i < n; ++i) {
    grid[i][0] = i;
    grid[0][i] = i;
    cols[0].insert(i);
  }

  for (int r = 0; r < n; ++r) {
    set<int> row = {r};
    for (int c = 0; c < n; ++c) {
      for (int i = 0; i < r + c + 1; ++i) {
        if (row.count(i) == 0 && cols[c].count(i) == 0) {
          row.insert(i);
          cols[c].insert(i);
          grid[r][c] = i;
          break;
        }
      }
    }
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      cout << grid[r][c] << ' ';
    }
    cout << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
