#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

const int dr[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dc[] = {2, -2, 2, -2, 1, -1, 1, -1};

void bfs(vector<vector<int>> &grid, int n) {
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    int qsize = size(q);
    while (qsize--) {
      auto [r, c] = q.front();
      q.pop();
      for (int i = 0; i < 8; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == -1) {
          grid[nr][nc] = grid[r][c] + 1;
          q.push({nr, nc});
        }
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, -1));
  grid[0][0] = 0;
  bfs(grid, n);
  for (auto row : grid) {
    for (auto col : row) {
      cout << col << ' ';
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
