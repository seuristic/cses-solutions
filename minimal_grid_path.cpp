// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;
// using ll = long long;

// #define size(x) (int)(x).size()
// #define all(x) begin(x), end(x)

// // string dfs(int r, int c, vector<string> &grid, vector<vector<string>>
// &memo)
// // {
// //   int n = size(grid);
// //   if (r == n - 1 && c == n - 1) {
// //     return string(1, grid[r][c]);
// //   }
// //   if (memo[r][c] != "") return memo[r][c];

// //   string down = string(1, 'z' + 1);
// //   string right = string(1, 'z' + 1);

// //   if (r + 1 < n)
// //     right = dfs(r + 1, c, grid, memo);
// //   if (c + 1 < n)
// //     down = dfs(r, c + 1, grid, memo);

// //   string best = (down < right) ? down : right;
// //   return memo[r][c] = grid[r][c] + best;
// // }

// void solve() {
//   int n;
//   cin >> n;
//   vector<string> grid(n);
//   for (string &row : grid) {
//     cin >> row;
//   }

//   // vector<vector<string>> memo(n, vector<string>(n, ""));
//   // cout << dfs(0, 0, grid, memo) << endl;

//   // Tabulation
//   // vector<vector<string>> dp(n, vector<string>(n));
//   // dp[0][0] = string(1, grid[0][0]);
//   // for (int r = 1; r < n; ++r) {
//   //   dp[r][0] = dp[r - 1][0] + grid[r][0];
//   // }
//   // for (int c = 1; c < n; ++c) {
//   //   dp[0][c] = dp[0][c - 1] + grid[0][c];
//   // }

//   // for (int r = 1; r < n; ++r) {
//   //   for (int c = 1; c < n; ++c) {
//   //     if (dp[r - 1][c] < dp[r][c - 1]) {
//   //       dp[r][c] = dp[r - 1][c] + grid[r][c];
//   //     } else {
//   //       dp[r][c] = dp[r][c - 1] + grid[r][c];
//   //     }
//   //   }
//   // }

//   // cout << dp[n - 1][n - 1] << endl;
//   //
//   // Tabulation 2.0
//   vector<string> prev(n), curr(n);
//   prev[0] = string(1, grid[0][0]);
//   for (int c = 1; c < n; ++c) {
//     prev[c] = prev[c - 1] + grid[0][c];
//   }

//   for (int r = 1; r < n; ++r) {
//     curr[0] = prev[0] + grid[r][0];
//     for (int c = 1; c < n; ++c) {
//       if (prev[c] < curr[c - 1]) {
//         curr[c] = prev[c] + grid[r][c];
//       } else {
//         curr[c] = curr[c - 1] + grid[r][c];
//       }
//     }
//     prev = curr;
//   }

//   cout << prev[n - 1] << endl;
// }

// int main() {
//   cin.tie(nullptr)->sync_with_stdio(false);
//   int t = 1;
//   // cin >> t;
//   while (t--) {
//     solve();
//   }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> grid(n);
  for (auto &row : grid)
    cin >> row;

  string ans = "";
  queue<pair<int, int>> q;
  q.push({0, 0});
  ans += grid[0][0];

  vector<vector<bool>> vis(n, vector<bool>(n, false));
  vis[0][0] = true;

  int dr[2] = {1, 0};
  int dc[2] = {0, 1};

  for (int step = 0; step < 2 * n - 2; ++step) {
    // store next frontier
    vector<pair<int, int>> next;
    char best = '{'; // '{' > 'z'
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      for (int k = 0; k < 2; ++k) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr < n && nc < n) {
          if (grid[nr][nc] < best) {
            best = grid[nr][nc];
            next.clear();
            next.push_back({nr, nc});
          } else if (grid[nr][nc] == best) {
            next.push_back({nr, nc});
          }
        }
      }
    }
    if (next.empty())
      break;
    ans += best;

    // deduplicate & enqueue
    sort(next.begin(), next.end());
    next.erase(unique(next.begin(), next.end()), next.end());
    for (auto [r, c] : next)
      q.push({r, c});
  }

  cout << ans << "\n";
  return 0;
}
