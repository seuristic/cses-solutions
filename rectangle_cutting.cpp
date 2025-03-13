#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define INF 1000000007
#define MOD INF

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;

  vector<vector<int>> dp(a + 1, vector<int>(b + 1, INF));

  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      if (i == j) {
        dp[i][j] = 0;
      } else {
        for (int k = 1; k < i; ++k) {
          dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
        }
        for (int k = 1; k < j; ++k) {
          dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
        }
      }
    }
  }

  cout << dp[a][b] << endl;

  return 0;
}
