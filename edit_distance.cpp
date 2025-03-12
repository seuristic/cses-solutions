#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define MOD 1000000007

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  int n = sz(s1), m = sz(s2);

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
  dp[0][0] = 0;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i > 0) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      }
      if (j > 0) {
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      }
      if (i > 0 && j > 0) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
      }
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}
