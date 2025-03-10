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

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> dp(n, vector<int>(m + 1, 0));
  if (a[0] == 0) {
    for (int x = 1; x <= m; ++x) {
      dp[0][x] = 1;
    }
  } else {
    dp[0][a[0]] = 1;
  }

  for (int i = 1; i < n; ++i) {
    if (a[i] == 0) {
      for (int x = 1; x <= m; ++x) {
        for (int k : {x - 1, x, x + 1}) {
          if (k >= 1 && k <= m) {
            (dp[i][x] += dp[i - 1][k]) %= MOD;
          }
        }
      }
    } else {
      for (int k : {a[i] - 1, a[i], a[i] + 1}) {
        if (k >= 1 && k <= m) {
          (dp[i][a[i]] += dp[i - 1][k]) %= MOD;
        }
      }
    }
  }

  int result = 0;
  for (int x = 1; x <= m; ++x) {
    (result += dp[n - 1][x]) %= MOD;
  }

  cout << result << endl;

  return 0;
}
