#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  if (grid[n - 1][n - 1] == '.') {
    dp[n - 1][n - 1] = 1;
  }

  for (int r = n - 1; r >= 0; --r) {
    for (int c = n - 1; c >= 0; --c) {
      if ((r < n - 1 || c < n - 1) && grid[r][c] != '*') {
        dp[r][c] = (dp[r + 1][c] + dp[r][c + 1]) % MOD;
      }
    }
  }

  cout << dp[0][0] << endl;

  return 0;
}
